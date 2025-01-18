#include <iostream>
#include <vector>

// Structures and Functions (as provided in the prompt)
struct Term{
    int exp;
    double coeff;
};

struct Polynomial {
    std::vector<Term> terms;
    int deg;
};

void print_polynomial(const Polynomial &p) {
    if (p.terms.empty()) {
        std::cout << "0" << std::endl; // Handle empty polynomial
        return;
    }

    for (size_t i = 0; i < p.terms.size(); ++i) {
        const Term &term = p.terms[i];

        // Skip terms with a coefficient of 0
        if (term.coeff == 0) {
            continue;
        }

        // Print sign for non-first terms
        if (i > 0 && term.coeff > 0) {
            std::cout << "+";
        }

        // Print coefficient
        if (std::abs(term.coeff) != 1 || term.exp == 0) {
            std::cout << term.coeff;
        } else if (term.coeff == -1) {
            std::cout << "-";
        }

        // Print variable and exponent
        if (term.exp > 0) {
            std::cout << "x";
            if (term.exp > 1) {
                std::cout << "^" << term.exp;
            }
        }
    }

    std::cout << std::endl;
}
Polynomial add_polynomials(const Polynomial &p, const Polynomial &q) {
    Polynomial r;
    int pi = 0, qi = 0;

    // Merge terms from both polynomials
    while (pi < p.terms.size() && qi < q.terms.size()) {
        Term t;
        if (p.terms[pi].exp == q.terms[qi].exp) {
            t.coeff = p.terms[pi].coeff + q.terms[qi].coeff;
            t.exp = p.terms[pi].exp;
            pi++;
            qi++;
        } else if (p.terms[pi].exp > q.terms[qi].exp) {
            t = p.terms[pi++];
        } else {
            t = q.terms[qi++];
        }

        if (t.coeff != 0) {
            r.terms.push_back(t);
        }
    }

    // Add remaining terms from p
    while (pi < p.terms.size()) {
        Term t = p.terms[pi++];
        if (t.coeff != 0) {
            r.terms.push_back(t);
        }
    }

    // Add remaining terms from q
    while (qi < q.terms.size()) {
        Term t = q.terms[qi++];
        if (t.coeff != 0) {
            r.terms.push_back(t);
        }
    }

    // Update degree based on resulting terms
    if (!r.terms.empty()) {
        r.deg = r.terms.front().exp;  // Highest exponent in descending order
    } else {
        r.deg = 0; // Zero polynomial
    }

    return r;
}

Polynomial mul_polynomials(const Polynomial &p, const Polynomial &q) {
    Polynomial r, part;


    for(int pi = 0; pi < p.terms.size(); ++pi){
        part.terms.clear();

        for(int qi=0; qi <q.terms.size(); ++qi ){
            Term t;
            t.coeff = p.terms[pi].coeff * q.terms[qi].coeff; 
            t.exp = p.terms[pi].exp + q.terms[qi].exp;
            part.terms.push_back(t);
        }

        r = add_polynomials(r, part);
    }
    
    return r;
}


// Main function
int main() {
    // Create a vector of polynomials
    std::vector<Polynomial> polynomials = {
        {{ {4, 2.0}, {3, -1.0}, {2, 3.0} }, 4},  // 2x^4 - x^3 + 3x^2
        {{ {4, -2.0}, {3, 1.0}, {1, -4.0} }, 4}, // -2x^4 + x^3 - 4x
        {{ {5, 6.0}, {2, -3.0}, {1, 4.0}, {0, 1.0} }, 2},  // -3x^2 + 4x + 1
        {{ {1, -4.0}, {0, -1.0} }, 1},           // -4x - 1
        {{ {0, 7.0} }, 0}                        // 7
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



