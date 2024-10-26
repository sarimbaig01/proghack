def main():
    # Test cases: Each test case has (prices, expected_i, expected_j, expected_rise)
    test_cases = [
        ([100, 180, 260, 310, 40, 535, 695], 4, 6, 655),   # General case with multiple rises
        ([100, 90, 80, 70, 60, 50, 40], -1, -1, -1),       # Decreasing prices
        ([50, 50, 50, 50], -1, -1, -1),                    # Constant prices
        ([90, 180, 60, 310, 40, 250, 695], 4, 6, 655),     # Mixed case with rise after initial fall
        ([20, 60, 100, 40, 30, 150, 10], 0, 5, 130),       # Peak price in the middle
        ([100, 90, 150, 30, 120, 180, 50], 3, 5, 150),     # Complex with multiple local rises
        ([5], -1, -1, -1)                                  # Only one price: no rise
    ]
    
    for i, (prices, expected_i, expected_j, expected_rise) in enumerate(test_cases, 1):
        result_i, result_j, max_rise = maximum_rise(prices)
        if (result_i, result_j, max_rise) == (expected_i, expected_j, expected_rise):
            print(f"Test case {i}: Test Passed")
        else:
            print(f"Test case {i}: Test Failed")
            print(f"Expected ({expected_i}, {expected_j}, {expected_rise}), but got ({result_i}, {result_j}, {max_rise})")


if __name__ == "__main__":
    # Running the main function to test maximum_rise on the test cases
    main()
