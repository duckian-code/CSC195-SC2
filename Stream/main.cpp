#include <iostream>
#include <fstream>
using namespace std;

void Write(string text, ostream& ostream) {
    ostream << text;
}

int main() {
    string text = "Hello World\n";
    cout << text;
    //
    // // cin >> text; -- listens for single word in sentence
    //
    getline(cin, text);
    // // cout << text;
    // Write(text, cout);
    //
    // time_t startTime = time(NULL);
    // for (int i = 0; i < 1'000'000'000; i++) {
    //     cout << i;
    //     Write(text, cout);
    //     // time stamped at 131 seconds
    // }
    // time_t endTime = time(NULL);
    //
    // cout << "Total time: " << endTime - startTime << " seconds" << endl;

   // output to a file
    ofstream fout("data.txt");
    fout << text;
    fout.close();

    text = "";
    // input from file
    ifstream input("data.txt");
    input >> text;
    getline(input, text);
    // cout << text;
    input.close();
}