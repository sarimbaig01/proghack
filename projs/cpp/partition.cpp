#include <iostream>
#include <vector>

int partition(std::vector<int>& A, int pivot_index) {
    ///TODO Implement this function
}

int main() {
    // Create all vectors at the start
    std::vector<int> A1 = {9, 3, 7, 6, 2, 8, 1, 4, 5, 10};
    std::vector<int> A2 = {12, 15, 7, 19, 3, 8, 6, 5, 2, 10};
    std::vector<int> A3 = {20, 17, 14, 13, 18, 16, 11, 15, 19, 12};

    // Test case 1
    std::cout << "Before partitioning (Test Case 1): ";
    for (int i = 0; i < A1.size(); i++) {
        std::cout << A1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Pivot value: " << A1[2] << std::endl; // Display pivot value
    int pivot1 = partition(A1, 2); // Using 7 as the pivot
    std::cout << "After partitioning (Test Case 1): ";
    for (int i = 0; i < A1.size(); i++) {
        std::cout << A1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Pivot index: " << pivot1 << std::endl;

    // Test case 2
    std::cout << "Before partitioning (Test Case 2): ";
    for (int i = 0; i < A2.size(); i++) {
        std::cout << A2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Pivot value: " << A2[4] << std::endl; // Display pivot value
    int pivot2 = partition(A2, 4); // Using 3 as the pivot
    std::cout << "After partitioning (Test Case 2): ";
    for (int i = 0; i < A2.size(); i++) {
        std::cout << A2[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Pivot index: " << pivot2 << std::endl;

    // Test case 3
    std::cout << "Before partitioning (Test Case 3): ";
    for (int i = 0; i < A3.size(); i++) {
        std::cout << A3[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Pivot value: " << A3[5] << std::endl; // Display pivot value
    int pivot3 = partition(A3, 5); // Using 16 as the pivot
    std::cout << "After partitioning (Test Case 3): ";
    for (int i = 0; i < A3.size(); i++) {
        std::cout << A3[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Pivot index: " << pivot3 << std::endl;

    return 0;
}