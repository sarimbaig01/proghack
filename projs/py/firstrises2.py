def main():
    # Test cases with expected outputs
    test_cases = [
        ([100, 180, 260, 310, 40, 535, 695], [80, 80, 50, 225, 495, 160, -1]),   # General case with multiple rises
        ([100, 90, 80, 70, 60, 50, 40], [-1, -1, -1, -1, -1, -1, -1]),           # Decreasing prices, all should be -1
        ([50, 50, 50, 50], [-1, -1, -1, -1]),                                    # Constant prices, all should be -1
        ([90, 180, 60, 310, 40, 250, 695], [90, 130, 250, -1, 210, 445, -1]),     # Mixed rises and falls
        ([5], [-1])                                                              # Single price, should return [-1]
    ]

    for i, (prices, expected) in enumerate(test_cases, 1):
        result = first_rises(prices)
        if result == expected:
            print(f"Test case {i}: Test Passed")
        else:
            print(f"Test case {i}: Test Failed")
            print(f"Expected: {expected}, but got: {result}")
        print("-" * 50)

# Running the main function to test first_rises
if __name__ == "__main__":
    main()
