#include <iostream>
#include <string>

// Function prototypes
void print_permutations(std::string s);
void print_permutations(std::string s, std::string chosen);

int main() {
    std::string s;
    std::cout << "Enter a string: ";
    std::cin >> s;

    if (s.empty()) {
        std::cout << "Invalid input. String must not be empty." << std::endl;
    } else {
        print_permutations(s);
    }

    return 0;
}
