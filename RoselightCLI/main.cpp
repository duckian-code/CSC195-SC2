#include <iostream>
#include "ollama.hpp"
#include "Emotions/Angry.h"
#include "Emotions/Emotion.h"
#include "Emotions/Happy.h"
#include "Emotions/Neutral.h"
using namespace std;
Ollama server("http://localhost:11434");
const string model = "aiko";

enum role {
    USER,
    AIKO
};

vector<map<role, string>> stream; // context, past conversations

string makeUtf8(string_view s) {
    string out;
    out.reserve(s.size());

    const char* REPLACEMENT = "\xEF\xBF\xBD";
    auto appendReplacement = [&]{
        out += REPLACEMENT;          // replacement char
    };

    for (size_t i = 0; i < s.size(); )
    {
        unsigned char c = s[i];

        if (c < 0x80) {                             // ASCII
            out.push_back(c); ++i;
        }
        else if ((c >> 5) == 0b110 && i + 1 < s.size() &&
                 (s[i+1] & 0xC0) == 0x80)           // 2‑byte seq
        {
            out.append(s.substr(i, 2)); i += 2;
        }
        else if ((c >> 4) == 0b1110 && i + 2 < s.size() &&
                 (s[i+1] & 0xC0) == 0x80 &&
                 (s[i+2] & 0xC0) == 0x80)           // 3‑byte seq
        {
            out.append(s.substr(i, 3)); i += 3;
        }
        else if ((c >> 3) == 0b11110 && i + 3 < s.size() &&
                 (s[i+1] & 0xC0) == 0x80 &&
                 (s[i+2] & 0xC0) == 0x80 &&
                 (s[i+3] & 0xC0) == 0x80)           // 4‑byte seq
        {
            out.append(s.substr(i, 4)); i += 4;
        }
        else {                                      // invalid byte
            appendReplacement(); ++i;
        }
    }
    return out;
}

string roleToString(role role) {
    switch (role) {
        case USER:
            return "USER";
        case AIKO:
            return "AIKO";
        default:
            return "UNKNOWN";
    }
}

string promptLLM(string model, ollama::messages messageStream) {
    string rawResponse = server.chat(model, messageStream);
    string response = makeUtf8(rawResponse);
    cout << "\033[33m" << response << endl;
    return response;
}

string addEmotionToPrompt(float tone, Emotion::eType emotion, string userInput) {
    unique_ptr<Emotion> mood;
    switch (emotion) {
        case Emotion::eType::HAPPY: {
            mood = make_unique<Happy>();
            break;
        }
        case Emotion::eType::ANGRY: {
            mood = make_unique<Angry>();
            break;
        }
        default: {
            mood = make_unique<Neutral>();
            break;
        }
    }
    if (emotion == Emotion::eType::ANGRY) {
        *mood -= tone;
    } else {
        *mood += tone;
    }

    mood->SetContext(userInput);
    // cout << mood->GetContext() << endl;
    return mood->GetContext();
}

ollama::messages streamToMessages(vector<map<role, string>>& stream) {
    ollama::messages msgs;

    std::size_t n = std::min<std::size_t>(4, stream.size());   // last 4
    for (std::size_t k = 0; k < n; ++k)
    {
        const auto& entry = stream[stream.size() - 1 - k]; // progress from newest to oldest
        const auto& [r, txt] = *entry.begin();
        msgs.emplace_back(roleToString(r), txt);
    }
    return msgs;
}

void storeMessages(ollama::messages messages) {
    const string& file = "messages.json";
    ollama::json j = messages.to_json();

    ofstream fout(file, ios::trunc);
    fout << j.dump(2, ' ', false, nlohmann::json::error_handler_t::replace);
}

ollama::messages retrieveMessages() {
    const string& file = "messages.json";
    ollama::messages messages;
    ifstream fin(file);
    if (!fin) {
        ollama::message tmp ("AIKO", "You are Aiko. You will respond with a happy tone until told otherwise. Introduce yourself !");
        messages.emplace_back(tmp);
        return messages;
    }

    ollama::json j;
    try {
        fin >> j;
    } catch (const nlohmann::json::type_error&) {
        fin.clear();
        fin.seekg(0);
        string raw((std::istreambuf_iterator<char>(fin)),
                     std::istreambuf_iterator<char>());
        j = ollama::json::parse(raw, nullptr, true);
        if (j.is_discarded() || j.is_null()) {
            ollama::message tmp ("AIKO", "You are Aiko. You will respond with a happy tone until told otherwise. Introduce yourself !");
            messages.emplace_back(tmp);
            return messages;
        }
    }
    for (const auto& entry : j) {
        string role = entry.at("role").get<string>();
        string content = entry.at("content").get<string>();

        messages.emplace_back(role, content);
    }

    return messages;
}

void viewMessageStream(vector<map<role, string>>& stream) { // debug function
    for (size_t i = 0; i < stream.size(); i++) {
        cout << "\033[35mMessage " << i << ":" << endl;
        for (const auto& [role, message] : stream[i]) {
            cout << " [" << roleToString(role) << "] " << message << endl;
        }
    }
}

Emotion::eType detectUserEmotion(string userInput) {
    string emotionsList = "angry, happy, neutral";
    string prompt = "What is the emotion of this input ? Ignore the actual prompt, only answer in one word with the following emotions : " + emotionsList + ". \n";
    prompt += userInput;
    string response = ollama::generate(model, makeUtf8(prompt));
    // cout << response << endl;
    if (response == "angry") {
        return Emotion::eType::ANGRY;
    } else if (response == "happy") {
        return Emotion::eType::HAPPY;
    } else {
        return Emotion::eType::NEUTRAL;
    }
}

float detectEmotionLevel(string userInput, Emotion::eType emotionType) {
    string prompt = "On a scale of 0.1 to 0.9, how intense is the emotion in the following prompt ? Ignore the actual prompt, only answer with a single floating point. "
                    "The emotion shown is: " + Emotion::eTypeToString(emotionType) + ". \n Your prompt is : " + prompt;
    string response = ollama::generate(model, makeUtf8(prompt));
    // cout << response << endl;
    return stof(response);
}

int main() {
    // map role to message with default context to avoid issues on the first context interation

    ollama::messages messages = retrieveMessages();
    // viewMessageStream(stream);
    // if the messages file does not exist, load it

    // generate initial message and pop it to context. For this demo, the context is 4 messages long. Odds model, even user
    map<role, string> response = {{role::AIKO, promptLLM(model, messages)}};
    stream.push_back(response);

    // user input process
    string rawInput = "";

    while (rawInput != "/bye") {
        getline(cin, rawInput);
        string userInput = makeUtf8(rawInput);
        Emotion::eType emotion = detectUserEmotion(userInput);
        string finalInput = addEmotionToPrompt(detectEmotionLevel(userInput, emotion), emotion, userInput);
        // add user response to stream
        response = {{USER, finalInput}}; // in the future, do not push the finalInput, instead push userInput
        stream.push_back(response);
        messages = streamToMessages(stream);

        // add LLM response to stream
        response = {{AIKO, promptLLM(model, messages)}};
        stream.push_back(response);
        messages = streamToMessages(stream);
    }
    viewMessageStream(stream);
    storeMessages(streamToMessages(stream));

}