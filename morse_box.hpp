#ifndef MORSEBOX_HPP
#define MORSEBOX_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<sstream>
#include <utility>
#include <array>
#include <chrono>
#include <fstream>
using namespace std;

extern vector<pair<char, string>> morseTry;

inline bool exists_test0 (const std::string& name);
vector<string> split(const string &s, char delim);
void file_morse_to_letter(const std::string& fileName);
void file_letter_to_morse(const std::string& fileName);
string morse_to_letter(string morseString);
string letter_to_morse(string alphaString);
void No_arg_menu();

#endif