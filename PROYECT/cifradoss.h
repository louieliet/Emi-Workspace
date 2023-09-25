#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;


string encryptCaesar1(const std::string& plaintext, int shift);


char* encryptCaesar(const char* plaintext, int shift);
string encryptVigenere(const std::string& plaintext, const std::string& key);
char* encryptVigenere1(const char* plaintext, const char* key);