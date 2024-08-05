#include <iostream>
#include <vector>

// Function prototype
int findRotatedMaximum(const std::vector<int>& nums);

int main() {
    std::vector<std::vector<int>> testCases = {
        {4, 5, 6, 7, 0, 1, 2},        
        {6, 7, 0, 1, 2, 4, 5},          
        {1, 2, 3, 4, 5},                
        {2, 3, 4, 5, 1},               
        {5, 1, 2, 3, 4},                
        {10, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 
        {1},                           
        {2, 1},                        
        {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000}, 
        {800, 900, 1000, 100, 200, 300, 400, 500, 600, 700}  
    };

    std::vector<int> expectedResults = {
        7, 7, 5, 5, 5, 10, 1, 2, 1000, 1000
    };

    bool allTestsPassed = true;

    for (int i = 0; i < testCases.size(); ++i) {
        const std::vector<int>& testCase = testCases[i];
        int expected = expectedResults[i];
        int actual = findRotatedMaximum(testCase);
        if (actual != expected) {
            std::cout << "Test failed for vector: ";
            for (int num : testCase) {
                std::cout << num << " ";
            }
            std::cout << ". Expected: " << expected << ", but got: " << actual << std::endl;
            allTestsPassed = false;
        }
    }

    if (allTestsPassed) {
        std::cout << "All tests passed." << std::endl;
    }

    return 0;
}
