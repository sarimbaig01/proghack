#include <iostream>

// Structure to represent a node of the linked list
struct node {
    double coeff;  // Coefficient of the term
    int power;     // Power of the term
    node* next;    // Pointer to the next node
};

// Adds a node at the start of the list
node* addNode(node* head, double coeff, int power);

// Displays the polynomial in human-readable form
void displayPolynomial(node* head);

// Adds two polynomials and returns the sum in a third polynomial
node* addPolynomials(node* poly1, node* poly2);

// Subtracts the second polynomial from the first and returns the difference in a third polynomial
node* subtractPolynomials(node* poly1, node* poly2);

// Multiplies two polynomials and returns the product in a third polynomial
node* multiplyPolynomials(node* poly1, node* poly2);

// Evaluates the polynomial for a given value of x
double evaluatePolynomial(node* poly, double x);

// Differentiates the polynomial and returns the derivative in a new polynomial
node* differentiatePolynomial(node* poly);

// Integrates the polynomial and returns the indefinite integral in a new polynomial
node* integratePolynomial(node* poly);

int main() {
    // Create linked lists to represent two sparse polynomials
    node* poly1 = nullptr;
    node* poly2 = nullptr;

    // Sparse Polynomial 1: 3x^100 + 2x^2 + 5
    poly1 = addNode(poly1, 5, 0);    // Adds constant term
    poly1 = addNode(poly1, 2, 2);    // Adds x^2 term
    poly1 = addNode(poly1, 3, 100);  // Adds x^100 term

    // Sparse Polynomial 2: 4x^50 + 2x^3 + 1
    poly2 = addNode(poly2, 1, 0);    // Adds constant term
    poly2 = addNode(poly2, 2, 3);    // Adds x^3 term
    poly2 = addNode(poly2, 4, 50);   // Adds x^50 term

    // Displays Polynomial 1
    std::cout << "Polynomial 1: ";
    displayPolynomial(poly1);

    // Displays Polynomial 2
    std::cout << "Polynomial 2: ";
    displayPolynomial(poly2);

    // Adds Polynomial 1 and Polynomial 2 and displays the sum
    node* sum = addPolynomials(poly1, poly2);
    std::cout << "Sum of Polynomial 1 and 2: ";
    displayPolynomial(sum);

    // Subtracts Polynomial 2 from Polynomial 1 and displays the result
    node* difference = subtractPolynomials(poly1, poly2);
    std::cout << "Difference of Polynomial 1 and 2: ";
    displayPolynomial(difference);

    // Multiplies Polynomial 1 and Polynomial 2 and displays the product
    node* product = multiplyPolynomials(poly1, poly2);
    std::cout << "Product of Polynomial 1 and 2: ";
    displayPolynomial(product);

    // Evaluates Polynomial 1 for x = 2 and displays the result
    double evalResult = evaluatePolynomial(poly1, 2);
    std::cout << "Evaluation of Polynomial 1 for x = 2: " << evalResult << std::endl;

    // Differentiates Polynomial 1 and displays the derivative
    node* derivative = differentiatePolynomial(poly1);
    std::cout << "Derivative of Polynomial 1: ";
    displayPolynomial(derivative);

    // Integrates Polynomial 1 and displays the indefinite integral
    node* integral = integratePolynomial(poly1);
    std::cout << "Indefinite Integral of Polynomial 1: ";
    displayPolynomial(integral);

    return 0;
}
