#include <iostream>
#include <vector>

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

    for (const auto& testCase : testCases) {
        const auto& str = testCase.first;
        bool expected = testCase.second;
        bool actual = isBalanced(str);
        if (actual != expected) {
            std::cout << "Test failed for string: \"" << str << "\". Expected: " 
                      << (expected ? "balanced" : "not balanced") 
                      << ", but got: " 
                      << (actual ? "balanced" : "not balanced") 
                      << std::endl;
            allTestsPassed = false;
        }
    }

    if (allTestsPassed) {
        std::cout << "All tests passed." << std::endl;
    }

    return 0;
}
