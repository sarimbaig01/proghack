#include <iostream>
#include <vector>

// Structures
struct Term{
    int exp;
    double coeff;
};

struct Polynomial {
    std::vector<Term> terms;
    int deg;
};

void print_polynomial(const Polynomial &p) {
   ///TODO: Implement this function
}

Polynomial add_polynomials(const Polynomial &p, const Polynomial &q) {
     ///TODO: Implement this function
     ///A single scan of p and q should be sufficient
     ///since terms are sorted by exponents
}

Polynomial mul_polynomials(const Polynomial &p, const Polynomial &q) {
    ///TODO: Implement this function
    ///Use add_polynomials to accumulate intermediate sums
}

int main() {
    ///Some example polynomials
    std::vector<Polynomial> polynomials = {
        {{ {4, 2.0}, {3, -1.0}, {2, 3.0} }, 4},  // 2x^4 - x^3 + 3x^2
        {{ {4, -2.0}, {3, 1.0}, {1, -4.0} }, 4}, // -2x^4 + x^3 - 4x
        {{ {5, 6.0}, {2, -3.0}, {1, 4.0}, {0, 1.0} }, 2},  // -3x^2 + 4x + 1
        {{ {1, -4.0}, {0, -1.0} }, 1}, // -4x - 1
        {{ {0, 7.0} }, 0} // 7
    };

    // Print each polynomial
    std::cout << "Input Polynomials:" << std::endl;
    for (int i = 0; i < polynomials.size(); ++i) {
        std::cout << "Polynomial " << i + 1 << ": ";
        print_polynomial(polynomials[i]);
    }

    // Compute the sum of all polynomials
    Polynomial sum = polynomials[0];
    for (int i = 1; i < polynomials.size(); ++i) {
        sum = add_polynomials(sum, polynomials[i]);
    }

    // Print the result
    std::cout << "Sum of all polynomials: ";
    print_polynomial(sum);
    std::cout << "Expected answer: 6x^5-4x+7" << std::endl;

    // Test multiplication
    std::cout << "\nTesting multiplication of Polynomial 1 and Polynomial 2:" << std::endl;
    Polynomial product = mul_polynomials(polynomials[0], polynomials[1]);

    std::cout << "Result of multiplication: ";
    print_polynomial(product);

    // Print the expected result
    std::cout << "Expected result: -4x^8+4x^7-7x^6-5x^5+4x^4-12x^3" << std::endl;

    return 0;
}