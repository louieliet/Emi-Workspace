#include "cifradoss.h"
std::string encryptCaesar1(const std::string& plaintext, int shift) {
    std::string ciphertext = "";
    for (auto c : plaintext) {
        if (isalpha(c)) {
            char base = (isupper(c)) ? 'A' : 'a';
            ciphertext += static_cast<char>((c - base + shift) % 26 + base);
        }
        else {
            ciphertext += c; // Leave non-alphabetic characters unchanged
        }
    }
    return ciphertext;
}


char* encryptVigenere1(const char* plaintext, const char* key) {
    int keyLength;
    int plainTextLength;
    int count = 0;
    while (plaintext[count] != '\0') {
        count++;
    }
    plainTextLength = count;
    char* ciphertext = new char[count + 1];
    ciphertext[count] = '\0';
    count = 0;
    while (key[count] != '\0') {
        count++;
    }
    keyLength = count;

    for (int i = 0; i < plainTextLength; ++i) {
        if (isalpha(plaintext[i])) {
            char base = (isupper(plaintext[i])) ? 'A' : 'a';
            int shift = key[i % keyLength] - base;
            ciphertext[i] = static_cast<char>((plaintext[i] - base + shift) % 26 + base);
        }
        else {
            ciphertext[i] = plaintext[i]; // Leave non-alphabetic characters unchanged
        }
    }
    return ciphertext;
}


char* encryptCaesar(const char* plaintext, int shift) {
    int count = 0;
    while (plaintext[count] != '\0')
        count++;
    std::cout << "count: " << count << std::endl;
    char* ciphertext = new char[count + 1];
    ciphertext[count] = '\0';
    for (int i = 0; i < count; ++i) {
        if (isalpha(plaintext[i])) {
            char base = (isupper(plaintext[i])) ? 'A' : 'a';
            ciphertext[i] = static_cast<char>((plaintext[i] - base + shift) % 26 + base);

        }
        else {
            ciphertext[i] = plaintext[i]; // Leave non-alphabetic characters unchanged
        }
    }
    return ciphertext;
}