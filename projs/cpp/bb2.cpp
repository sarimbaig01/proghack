#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> testStrings = {
        "{([])}{}", "{([)]}", "{{[[(())]]}}", "([{}])", "([)]", "", "{[()()]}", "{[(])}",
        "{{{{}}", "[({})]", "{[}]", "()[]{}", "((()))", "((())", "{{}}[()]{{}}", "{[({[({[()]})]})]}",
        "{[({[({[()}])]}])}", "{[]}", "{[({})]}", "{[(])}"
    };

    std::vector<bool> expectedResults = {
        true, false, true, true, false, true, true, false,
        false, true, false, true, true, false, true, true,
        false, true, true, false
    };

    bool allTestsPassed = true;

    for (int i = 0; i < testStrings.size(); ++i) {
        bool result = is_balanced(testStrings[i]);

        // Print the test case and result for debugging
        std::cout << "Testing \"" << testStrings[i] << "\": ";
        if (result) {
            std::cout << "balanced";
        } else {
            std::cout << "not balanced";
        }
        std::cout << " - Expected: ";
        if (expectedResults[i]) {
            std::cout << "balanced";
        } else {
            std::cout << "not balanced";
        }
        std::cout << std::endl;

        // Check if the result matches the expected result
        if (result != expectedResults[i]) {
            std::cout << "Test failed for string: \"" << testStrings[i] << "\". Expected: ";
            if (expectedResults[i]) {
                std::cout << "balanced";
            } else {
                std::cout << "not balanced";
            }
            std::cout << ", but got: ";
            if (result) {
                std::cout << "balanced";
            } else {
                std::cout << "not balanced";
            }
            std::cout << std::endl;
            allTestsPassed = false;
        }
    }

    if (allTestsPassed) {
        std::cout << "All tests passed." << std::endl;
    }

    return 0;
}
