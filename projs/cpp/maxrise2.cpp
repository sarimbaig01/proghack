#include <iostream>
#include <vector>

// Assume maximum_rise function is already defined

int main() {
    // Test cases: each test case is represented by a vector of prices
    std::vector<std::vector<int>> test_prices = {
        {100, 180, 260, 310, 40, 535, 695},  // General case with multiple rises
        {100, 90, 80, 70, 60, 50, 40},       // Decreasing prices
        {50, 50, 50, 50},                    // Constant prices
        {90, 180, 60, 310, 40, 250, 695},    // Mixed case with rise after initial fall
        {20, 60, 100, 40, 30, 150, 10},      // Peak price in the middle
        {100, 90, 150, 30, 120, 180, 50},    // Complex with multiple local rises
        {5}                                  // Only one price: no rise
    };

    std::vector<int> expected_results = {655, -1, -1, 655, 130, 150, -1};

    for (int i = 0; i < test_prices.size(); ++i) {
        int result = maximum_rise(test_prices[i]);
        
        if (result == expected_results[i]) {
            std::cout << "Test case " << i + 1 << ": Test Passed" << std::endl;
        } else {
            std::cout << "Test case " << i + 1 << ": Test Failed" << std::endl;
            std::cout << "Expected " << expected_results[i] << ", but got " << result << std::endl;
        }
    }

    return 0;
}
