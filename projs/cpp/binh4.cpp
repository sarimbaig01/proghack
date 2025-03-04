#include <iostream>
#include <vector>

int main() {
    MinHeap heap;

    // Test acceptHeap
    std::cout << "Accepting a pre-built heap:\n";
    heap.acceptHeap({10, 15, 20, 17, 25, 30, 40, 19, 27, 35});
    heap.printHeap();
    std::cout << std::endl;

    // Test insert function
    std::cout << "Inserting values: 5, 8, 12\n";
    heap.insert(5);
    heap.insert(8);
    heap.insert(12);
    heap.printHeap();
    std::cout << std::endl;

    // Test getMin function
    std::cout << "Current minimum element: " << heap.getMin() << std::endl;

    // Test removeMin function
    std::cout << "Removing minimum elements:\n";
    while (!heap.isEmpty()) {
        std::cout << "Removed: " << heap.removeMin() << " -> Heap: ";
        heap.printHeap();
    }
    std::cout << std::endl;

    return 0;
}
