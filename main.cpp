#include "morse_box.hpp"

int main(int argc,char* argv[]) {

    if(argc == 1) {
        /*cout << "No translation mode choosen to execute\n";
        cout << "Those are the options available:\n"
             << "-ATM \"alphabetical string\" (Alphabet to morse)\n"
             << "-MTA \"morse string\" (Morse to alphabet)\n"
             << "-ATMFILE \"filename\" (translate alphabet file to morse)\n"
             << "-MTAFILE \"filename\" (translate morse file to alphabet)\n\n";*/
        No_arg_menu();

    }
    else if(argc == 2) {
        cout << "No string or file given to translate\n";
    }
    else if(argc >= 4) {
        cout << "To much argument given\n";
    }
    else {
        string mode = argv[1];
        if(mode == "ATM") {
            cout << letter_to_morse(argv[2]) + '\n';
        }
        else if(mode == "MTA") {
            cout << morse_to_letter(argv[2]) + '\n';
        }
        else if(mode == "ATMFILE") {
            file_letter_to_morse(argv[2]);
        }
        else if(mode == "MTAFILE") {
            file_morse_to_letter(argv[2]);
        }
        else {
            
            cout << "Unknown argument given\n";
            cout << argv[1] << " " << argv[2];
        }
    }

    return 0;
}