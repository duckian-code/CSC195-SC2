#include <iostream>
#include "ollama.hpp"
using namespace std;

int main() {
    // initialise model and model details
    Ollama server("http://localhost:11434");
    ollama::request request(ollama::message_type::chat);
    request["model"] = "aiko";
    vector<string> stream; // context, past conversations
    stream.
}
