#include <iostream>
#include <vector>

// Prototype for the partition function
void partition(std::vector<int>& A, int pivot_index);

int main() {
    // Create all vectors at the start
    std::vector<int> A1 = {9, 3, 7, 6, 2, 8, 1, 4, 5, 10};
    std::vector<int> A2 = {12, 15, 7, 19, 3, 8, 6, 5, 2, 10};
    std::vector<int> A3 = {20, 17, 14, 13, 18, 16, 11, 15, 19, 12};

    // Test case 1
    std::cout << "Before partitioning (Test Case 1): ";
    for (int num : A1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    partition(A1, 2); // Using 7 as the pivot

    std::cout << "After partitioning (Test Case 1): ";
    for (int num : A1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Test case 2
    std::cout << "Before partitioning (Test Case 2): ";
    for (int num : A2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    partition(A2, 4); // Using 3 as the pivot

    std::cout << "After partitioning (Test Case 2): ";
    for (int num : A2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Test case 3
    std::cout << "Before partitioning (Test Case 3): ";
    for (int num : A3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    partition(A3, 5); // Using 16 as the pivot

    std::cout << "After partitioning (Test Case 3): ";
    for (int num : A3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
