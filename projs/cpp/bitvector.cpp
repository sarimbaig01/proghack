#include <cstddef>
#include <cstdint>
#include <iostream>

class BitVector {
private:
    uint32_t* bits;  // Dynamically allocated bit storage
    size_t num_bits; // Total number of bits
    size_t num_uint32; // Number of uint32_t elements needed

public:
    // Constructor
    BitVector(size_t n);

    // Destructor
    ~BitVector();

    // Copy Constructor
    BitVector(const BitVector& other);

    // Assignment Operator 
    const BitVector& operator=(const BitVector& other);

    // Set a bit at the given index
    void set(size_t index);

    // Clear a bit at the given index
    void clear(size_t index);

    // Check if a bit is set
    bool get(size_t index) const;

    // Returns the number of uint32_t elements in the bit vector
    size_t size() const;

    // Returns the total number of bits represented
    size_t numBits() const;

    // Returns a "read only" pointer to the internal bit storage
    const uint32_t* getBits() const;

};

int main() {
    size_t N = 100;  // Total number of bits in the bit vector
    BitVector bv(N); // Create a BitVector of size N

    // Set some bits
    bv.set(3);
    bv.set(7);
    bv.set(15);
    bv.set(31);
    bv.set(63);
    
    std::cout << "BitVector after setting some bits:\n";
    for (size_t i = 0; i < N; i++) {
        if (bv.get(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    // Clear some bits
    bv.clear(7);
    bv.clear(31);

    std::cout << "BitVector after clearing bits 7 and 31:\n";
    for (size_t i = 0; i < N; i++) {
        if (bv.get(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    // Check specific bits
    std::cout << "Checking bits:\n";
    std::cout << "Bit 3: " << bv.get(3) << std::endl;  // Expected: 1
    std::cout << "Bit 7: " << bv.get(7) << std::endl;  // Expected: 0 (cleared)
    std::cout << "Bit 15: " << bv.get(15) << std::endl; // Expected: 1
    std::cout << "Bit 31: " << bv.get(31) << std::endl; // Expected: 0 (cleared)
    std::cout << "Bit 63: " << bv.get(63) << std::endl; // Expected: 1

    // Print bit vector size information
    std::cout << "Total bits: " << bv.numBits() << std::endl;
    std::cout << "Number of uint32_t blocks used: " << bv.size() << std::endl;

     // Retrieve a read-only pointer to internal bit storage
     const uint32_t* bitData = bv.getBits();

     std::cout << "Raw bit storage (read-only access):\n";
     for (size_t i = 0; i < bv.size(); i++) {
         std::cout << "Block " << i << ": " << bitData[i] << std::endl;
     }

    return 0;
}