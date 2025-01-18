#include <iostream>
#include <vector>

bool can_relay(const std::vector<int>& ranges) {
    int n = ranges.size();
    if (n == 0) return false; // Edge case: Empty input

    int farthest = 0; // Tracks the farthest reachable sensor

    for (int i = 0; i < n; ++i) {
        // If the current sensor is not reachable, return false
        if (i > farthest) return false;

        // Update the farthest point reachable from the current sensor
        farthest = std::max(farthest, i + ranges[i]);

        // If the last sensor is reachable, return true
        if (farthest >= n - 1) return true;
    }

    return false; // If we finish the loop without reaching the last sensor
}

std::vector<int> min_relay_path(const std::vector<int>& ranges) {
    ///TODO: Implement this function

    ///The function may assume that a valid relay path exists
    ///(determined by an earlier call to can_relay)

    std::vector<int> path;
    if(ranges.size()==0){
        return path;
    }

    int current_jump = ranges[0];
    path.push_back(0);
    int N = ranges.size();
    int  i = 1;
    while(i<N && current_jump < N - 1){
        
        int max_new_jump = current_jump;
        int max_idx = -1;
        
        for(; i < N && i <= current_jump; ++i){
            if(i + ranges[i] > max_new_jump){
                max_new_jump = i + ranges[i];
                max_idx = i;
            }
        }

        if(max_new_jump < N){
            path.push_back(max_idx);
        }
        
        current_jump = max_new_jump; 
    }

    path.push_back(N-1);
    return path;
}

int main() {
    // Test cases with expected results
    std::vector<std::pair<std::vector<int>, bool>> test_cases = {
        {{2, 3, 1, 1, 4}, true},      
        {{3, 2, 1, 0, 4}, false},     
        {{1, 1, 1, 1, 1}, true},      
        {{2, 0, 2, 0, 1}, true},      
        {{5, 0, 0, 0, 0, 0}, true}    
    };

    for (int i = 0; i < test_cases.size(); ++i) {
        bool result = can_relay(test_cases[i].first);
        bool expected = test_cases[i].second;

        std::cout << "Test Case " << i + 1 << ":" << std::endl;
        std::cout << "Input: ";
        for (int j = 0; j < test_cases[i].first.size(); ++j) {
            std::cout << test_cases[i].first[j] << " ";
        }
        std::cout << std::endl;

        std::cout << "Expected: ";
        if (expected) {
            std::cout << "true" << std::endl;
        } else {
            std::cout << "false" << std::endl;
        }

        std::cout << "Output: ";
        if (result) {
            std::cout << "true" << std::endl;
        } else {
            std::cout << "false" << std::endl;
        }

        if (result) {
            std::vector<int> path = min_relay_path(test_cases[i].first);
            std::cout << "Relaying Path: ";
            for (int sensor : path) {
                std::cout << sensor << " ";
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
