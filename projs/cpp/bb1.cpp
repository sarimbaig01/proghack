#include <iostream>
#include <vector>
#include <string>
#include <utility>

// Function prototype
bool isBalanced(const std::string& str);

int main() {
    std::vector<std::pair<std::string, bool>> testCases = {
        {"{([])}{}", true},
        {"{([)]}", false},
        {"{{[[(())]]}}", true},
        {"([{}])", true},
        {"([)]", false},
        {"", true},
        {"{[()()]}", true},
        {"{[(])}", false},
        {"{{{{}}", false},
        {"[({})]", true},
        {"{[}]", false},
        {"()[]{}", true},
        {"((()))", true},
        {"((())", false},
        {"{{}}[()]{{}}", true},
        {"{[({[({[()]})]})]}", true},
        {"{[({[({[()}])]}])}", false},
        {"{[]}", true},
        {"{[({})]}", true},
        {"{[(])}", false}
    };

    bool allTestsPassed = true;

    for (int i = 0; i < testCases.size(); ++i) {
        if (isBalanced(testCases[i].first) != testCases[i].second) {
            std::cout << "Test failed for string: \"" << testCases[i].first << "\". Expected: " 
                      << (testCases[i].second ? "balanced" : "not balanced") 
                      << ", but got: " 
                      << (isBalanced(testCases[i].first) ? "balanced" : "not balanced") 
                      << std::endl;
            allTestsPassed = false;
        }
    }

    if (allTestsPassed) {
        std::cout << "All tests passed." << std::endl;
    }

    return 0;
}
