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
        bool result = is_balanced(testStrings[i]);  // Calling the is_balanced function

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
