#include <iostream>

class FastSet {
private:
    BitVector bv;  
public:
    // Constructor
    FastSet(int N);

    // Insert an element into the set
    void insert(int x);

    // Remove an element from the set
    void remove(int x);

    // Check if an element is in the set
    bool isMember(int x) const;

    // Compute the union of two sets and return a new set
    FastSet unionWith(const FastSet& other) const;

    // Compute the intersection of two sets and return a new set
    FastSet intersectionWith(const FastSet& other) const;

    // Print all elements in the set
    void print() const;
};

int main() {
    int N = 100;

    FastSet setA(N), setB(N);

    // Insert elements into set A
    setA.insert(10);
    setA.insert(20);
    setA.insert(30);
    setA.insert(40);

    // Insert elements into set B
    setB.insert(20);
    setB.insert(30);
    setB.insert(50);
    setB.insert(60);

    // Compute Union
    FastSet unionResult = setA.unionWith(setB);
    std::cout << "Union: ";
    unionResult.print();

    // Compute Intersection
    FastSet intersectResult = setA.intersectionWith(setB);
    std::cout << "Intersection: ";
    intersectResult.print();

    return 0;
}
