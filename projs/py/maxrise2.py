def main():
    # Test cases
    test_cases = [
        ([100, 180, 260, 310, 40, 535, 695], 655),  # General case with multiple rises
        ([100, 90, 80, 70, 60, 50, 40],  -1),      # Decreasing prices
        ([50, 50, 50, 50], -1),                   # Constant prices
        ([90, 180, 60, 310, 40, 250, 695], 655),    # Mixed case with rise after initial fall
        ([20, 60, 100, 40, 30, 150, 10],  130),      # Peak price in the middle
        ([100, 90, 150, 30, 120, 180, 50], 150),    # Complex with multiple local rises
        ([5], -1)                                 #Only one price: no rise
    ]
    
    for i, (prices, expected) in enumerate(test_cases, 1):
        result = maximum_rise(prices)
        if result == expected:
            print(f"Test case {i}: Test Passed")
        else:
            print(f"Test case {i}: Test Failed")
            print(f"Expected {expected}, but got {result}")


if __name__ == "__main__":
    # Running the main function to test maximum_rise on the test cases
    main()






