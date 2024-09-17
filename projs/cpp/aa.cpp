#include <iostream>
#include <vector>
#include <chrono>

// Prototype for the function maxDecline
double maxDecline(int p, int a, int b, int c, int d, int n);

int main() {
    // Test cases
    std::vector<std::vector<int>> testInputs = {
        {4, 1, 23, 4, 8, 10},     // Sample Input 1
        {100, 7, 615, 998, 801, 3}, // Sample Input 2
        {100, 432, 406, 867, 60, 1000}  // Sample Input 3
    };

    std::vector<double> expectedOutputs = {
        104.855110477, // Expected Output for Sample Input 1
        0.00,          // Expected Output for Sample Input 2
        399.303813     // Expected Output for Sample Input 3
    };

    // Run tests and time them
    for (int i = 0; i < testInputs.size(); ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        
        double result = maxDecline(
            testInputs[i][0], 
            testInputs[i][1], 
            testInputs[i][2], 
            testInputs[i][3], 
            testInputs[i][4], 
            testInputs[i][5]
        );

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        std::cout << "Test case " << i + 1 << ": Expected = " 
                  << expectedOutputs[i] << ", Result = " << result << std::endl;

        if (elapsed.count() > 0.0001) {
            std::cout << "Implementation took longer than 10^-4 seconds. Time: " 
                      << elapsed.count() << " seconds." << std::endl;
        } else {
            std::cout << "Implementation passes time testing. Time: " 
                      << elapsed.count() << " seconds." << std::endl;
        }
    }

    return 0;
}
