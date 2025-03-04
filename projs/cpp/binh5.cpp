#include <iostream>
#include <vector>

///Implement all class functions such that the following code works as expected

int main() {
    MinHeap heap;

    // Accepting a pre-built heap
    std::cout << "Accepting a pre-built heap:\n";
    heap.acceptHeap({10, 20, 15, 30, 40, 50, 60, 70, 80, 90});
    heap.printHeap();
    std::cout << std::endl;

    // Test updateKey
    std::cout << "Updating index 5 to 12:\n";
    heap.updateKey(5, 12);  // Update index 5 to 12
    heap.printHeap();
    std::cout << std::endl;

    // Test mergeHeaps
    MinHeap heap1, heap2, mergedHeap;
    heap1.acceptHeap({10, 20, 15, 40, 50});
    heap2.acceptHeap({5, 25, 30, 35, 45});
    mergedHeap = heap1.mergeHeaps(heap2);
    std::cout << "Merged heap:\n";
    mergedHeap.printHeap();
    std::cout << std::endl;

    // Test deleteElement
    std::cout << "Deleting element at index 3:\n";
    heap.deleteElement(3);  // Delete index 3
    heap.printHeap();
    std::cout << std::endl;

    // Test heapSort
    std::vector<int> unsortedVec = {10, 5, 20, 15, 30, 25, 40, 60, 50, 35};
    std::cout << "Unsorted vector: ";
    for (int val : unsortedVec) std::cout << val << " ";
    std::cout << std::endl;

    heap.heapSort(unsortedVec);
    std::cout << "Sorted vector using heapSort: ";
    for (int val : unsortedVec) std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}
