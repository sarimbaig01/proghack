def main():
    test_strings = [
        "{([])}{}", "{([)]}", "{{[[(())]]}}", "([{}])", "([)]", "", "{[()()]}", "{[(])}",
        "{{{{}}", "[({})]", "{[}]", "()[]{}", "((()))", "((())", "{{}}[()]{{}}", "{[({[({[()]})]})]}",
        "{[({[({[()}])]}])}", "{[]}", "{[({})]}", "{[(])}"
    ]

    expected_results = [
        True, False, True, True, False, True, True, False,
        False, True, False, True, True, False, True, True,
        False, True, True, False
    ]

    all_tests_passed = True

    for i in range(len(test_strings)):
        result = is_balanced(test_strings[i])

        # Debug output to check each test result
        print(f'Testing "{test_strings[i]}": ', end="")
        print("balanced" if result else "not balanced", end=" - Expected: ")
        print("balanced" if expected_results[i] else "not balanced")

        # Check if the result matches the expected result
        if result != expected_results[i]:
            print(f'Test failed for "{test_strings[i]}". Expected: '
                  f'{"balanced" if expected_results[i] else "not balanced"}, but got: '
                  f'{"balanced" if result else "not balanced"}')
            all_tests_passed = False

    if all_tests_passed:
        print("All tests passed.")

if __name__ == "__main__":
    main()
