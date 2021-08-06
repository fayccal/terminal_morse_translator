#include "morse_box.hpp"

vector<pair<char, string>> morseTry = { 
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, 
        {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
        {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."},
        {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
        {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},

        {'.', ".-.-.-"}, {',', "--..--"}, {'?', "..--.."}, {'\'', ".----."}, {'!', "-.-.--"},
        {'/', "-..-."}, {'(', "-.--."}, {')', "-.--.-"}, {'&', ".-..."}, {':', "---..."},
        {';', "-.-.-."}, {'=', "-...-"}, {'+', ".-.-."}, {'-', "-....-"}, {'_', "..--.-"},
        {'"', ".-..-."}, {'$', "...-..-"}, {'@', ".--.-."}
};
inline bool exists_test0 (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

void file_morse_to_letter(const std::string& fileName) {

    if(exists_test0(fileName) == false) {
        cout << "this file doesnt exist\n";
        return;
    }

    string readingLine;
    ifstream readFile("input.txt");
    ofstream writeFile("output.txt");

    while(getline(readFile, readingLine)) {
        vector<string> splited = split(readingLine,' ');

        for(auto i : splited) {
            if(i == "") {
                writeFile << " ";
                continue;
            }

            auto it = find_if(morseTry.begin(), morseTry.end(), [&i](const pair<char, string> p) 
            {return p.second == i;});

            if( it == morseTry.end()) {
                writeFile << "�";
            }
            else {
            writeFile << it->first;
            }
        }
    }

    readFile.close();
    writeFile.close();
}

void file_letter_to_morse(const std::string& fileName) {

    if(exists_test0(fileName) == false) {
        cout << "this file doesnt exist\n";
        return;
    }

    string readingLine;
    ifstream readFile("input.txt");
    ofstream writeFile("output.txt");

    while(getline(readFile, readingLine)) {
        for(char& c : readingLine) {
            if(c == ' ') {
                writeFile << " ";
                continue;
            }
        
            auto it = find_if(morseTry.begin(), morseTry.end(), [&c](const pair<char, string> p) 
            {return p.first == toupper(c);});

            if( it == morseTry.end()) {
                writeFile << "�";
            }
            else {
            writeFile << it->second + " ";
            }
        }
    }

    readFile.close();
    writeFile.close();
}

string morse_to_letter(string morseString) {
    string fullMSG = "";
    vector<string> splited = split(morseString,' ');

    for(auto i : splited) {
        if(i == "") {
            fullMSG += " ";
            continue;
        }

        auto it = find_if(morseTry.begin(), morseTry.end(), [&i](const pair<char, string> p) 
        {return p.second == i;});

        if( it == morseTry.end()) {
            fullMSG += "�";
        }
        else {
        fullMSG += it->first;
        }
    }

    return fullMSG;
}

string letter_to_morse(string alphaString) {

    string fullMSG = "";

    for(char& c : alphaString) {
        if(c == ' ') {
            fullMSG += " ";
            continue;
        }
        
        auto it = find_if(morseTry.begin(), morseTry.end(), [&c](const pair<char, string> p) 
        {return p.first == toupper(c);});

        if( it == morseTry.end()) {
            fullMSG += "�";
        }
        else {
        fullMSG += it->second + " ";
        }
    }

    return fullMSG;
}

void No_arg_menu() {
        string choice;
        string toTranslate;
        cout << "Welcome to the morse translator! \n";
            cout << "Those are the options available:\n"
             << "-ATM (Alphabet to morse)\n"
             << "-MTA (Morse to alphabet)\n"
             << "-ATMFILE (translate alphabet file to morse)\n"
             << "-MTAFILE (translate morse file to alphabet)\n\n"
             << "type exit to quit the translator.\n\n";
        do {

            cout << "Mode:";
            getline(cin, choice);
            if(choice == "ATM") {
                cout << "Enter the alphabetical string:\n";
                getline(cin, toTranslate);
                cout << "\nTranslation:" + letter_to_morse(toTranslate) + "\n\n\n";
            }
            else if(choice == "MTA") {
                cout << "Enter the morse string:\n";
                getline(cin, toTranslate);
                cout << "\nTranslation:" + morse_to_letter(toTranslate) + "\n\n\n";
            }
            else if(choice == "ATMFILE") {
                cout << "Enter the name of your file:\n";
                getline(cin, toTranslate);
                file_letter_to_morse(toTranslate);
            }
            else if(choice == "MTAFILE") {
                cout << "Enter the name of your file:\n";
                getline(cin, toTranslate);
                file_morse_to_letter(toTranslate);
            }
            else if(choice == "exit") {}
            else {
                cout << "undifined\n\n";
            }
        }while(choice != "exit");

}