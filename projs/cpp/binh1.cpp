void printHeap(const std::vector<int>& heap);

//main to test your printHeap and future functions
int main() {
    // Test data: various heap vectors
    std::vector<int> heap1 = {10, 15, 20, 17, 25, 30, 40, 19, 27, 35};
    std::vector<int> heap2 = {5, 12, 14, 17, 21, 23, 31, 19, 27, 35, 45, 50};
    std::vector<int> heap3 = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

    std::cout << "Heap 1 printed:" << std::endl;
    printHeap(heap1);
    std::cout << std::endl;

    std::cout << "Heap 2 printed:" << std::endl;
    printHeap(heap2);
    std::cout << std::endl;

    std::cout << "Heap 3 printed:" << std::endl;
    printHeap(heap3);
    std::cout << std::endl;

    return 0;
}
