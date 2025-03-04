#include <vector>
#include <iostream>

class MinHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);
    int leftChild(int index);
    int rightChild(int index);

public:
    MinHeap() = default;

    void acceptHeap(const std::vector<int>& values);
    void insert(int value);
    int removeMin();
    int getMin() const;
    void printHeap() const;
};

// Function to accept a ready-made heap
void MinHeap::acceptHeap(const std::vector<int>& values) {
    heap = values;
}

// Function to print heap (member function of MinHeap)
void MinHeap::printHeap() const {
    ///Implement this, and other required functions 
}

// Main function to test printHeap and future functions
int main() {
    MinHeap heap1, heap2, heap3;

    heap1.acceptHeap({10, 15, 20, 17, 25, 30, 40, 19, 27, 35});
    heap2.acceptHeap({5, 12, 14, 17, 21, 23, 31, 19, 27, 35, 45, 50});
    heap3.acceptHeap({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31});

    std::cout << "Heap 1 printed:" << std::endl;
    heap1.printHeap();
    std::cout << std::endl;

    std::cout << "Heap 2 printed:" << std::endl;
    heap2.printHeap();
    std::cout << std::endl;

    std::cout << "Heap 3 printed:" << std::endl;
    heap3.printHeap();
    std::cout << std::endl;

    return 0;
}
