#include <iostream>
#include <unordered_set>
#include <string>
#include <fstream>

// Function to read dictionary from a file
std::unordered_set<std::string> readDictionary(const std::string& filename) {
    std::unordered_set<std::string> dictionary;
    std::ifstream file(filename);
    std::string word;
    while (file >> word) {
        dictionary.insert(word);
    }
    file.close();
    return dictionary;
}

// Function to check if a word is valid by looking it up in the dictionary
bool validWord(const std::unordered_set<std::string>& dictionary, const std::string& str) {
    return dictionary.find(str) != dictionary.end();
}

// Test the functions
int main() {
    // Read the dictionary from the provided file
    std::unordered_set<std::string> dictionary = readDictionary("wordlist.10000");

    // Example stream
    std::string stream = "helloworldthisisatest";
    std::string decoded;

    // Test Stage 1
    if (validCommunication(dictionary, stream)) {
        std::cout << "Valid communication is possible." << std::endl;
    } else {
        std::cout << "No valid communication possible." << std::endl;
    }

    // Test Stage 2
    if (validCommunication(dictionary, stream, decoded)) {
        std::cout << "Decoded sentence: " << decoded << std::endl;
    } else {
        std::cout << "No valid communication possible." << std::endl;
    }

    return 0;
}
