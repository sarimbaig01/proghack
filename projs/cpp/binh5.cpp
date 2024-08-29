#include <iostream>
#include <vector>

// Changes the value of an element and restores the heap property
void updateKey(std::vector<int>& heap, int index, int newValue);

// Merges two heaps into one while maintaining the heap property
std::vector<int> mergeHeaps(const std::vector<int>& heap1, const std::vector<int>& heap2);

// Removes an element from the heap and restores the heap property
void deleteElement(std::vector<int>& heap, int index);

// Sorts a vector using heap sort algorithm
void heapSort(std::vector<int>& vec);

int main() {
    // Example heap vector
    std::vector<int> heap = {10, 20, 15, 30, 40, 50, 60, 70, 80, 90};

    // Test updateKey
    std::cout << "Original heap: ";
    for (int val : heap) std::cout << val << " ";
    std::cout << std::endl;

    updateKey(heap, 5, 12); // Update the value at index 5 to 12 (could be an increase or decrease)
    std::cout << "Heap after updateKey: ";
    for (int val : heap) std::cout << val << " ";
    std::cout << std::endl;

    // Test mergeHeaps
    std::vector<int> heap1 = {10, 20, 15, 40, 50};
    std::vector<int> heap2 = {5, 25, 30, 35, 45};
    std::vector<int> mergedHeap = mergeHeaps(heap1, heap2);
    std::cout << "Merged heap: ";
    for (int val : mergedHeap) std::cout << val << " ";
    std::cout << std::endl;

    // Test deleteElement
    deleteElement(heap, 3); // Delete the element at index 3
    std::cout << "Heap after deleteElement: ";
    for (int val : heap) std::cout << val << " ";
    std::cout << std::endl;

    // Test heapSort
    std::vector<int> unsortedVec = {10, 5, 20, 15, 30, 25, 40, 60, 50, 35};
    std::cout << "Unsorted vector: ";
    for (int val : unsortedVec) std::cout << val << " ";
    std::cout << std::endl;

    heapSort(unsortedVec); // Sort the vector
    std::cout << "Sorted vector using heapSort: ";
    for (int val : unsortedVec) std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}

