#include <iostream>
#include <string>

// Function prototypes
void print_binary_strings(int n);
void print_binary_strings(int n, std::string current);

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Invalid input. n must be non-negative." << std::endl;
    } else {
        print_binary_strings(n);
    }

    return 0;
}