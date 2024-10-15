def main():
    # Test case 1: Typical case with mixed increases and decreases
    data = [1, 7, 3, 5, 9, 2, 8, 6, 10, 3, 7, 12]
    print("Test case 1 - Expected: 6, Output:", longest_trend_length(data))
    
    # Test case 2: All elements are increasing
    data = [2, 4, 6, 8, 10, 12, 14, 16, 18]
    print("Test case 2 - Expected: 9, Output:", longest_trend_length(data))
    
    # Test case 3: Mixed values with some consecutive increases
    data = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 9]
    print("Test case 3 - Expected: 5, Output:", longest_trend_length(data))
    
    # Test case 4: Single element
    data = [42]
    print("Test case 4 - Expected: 1, Output:", longest_trend_length(data))
    
    # Test case 5: Decreasing sequence
    data = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    print("Test case 5 - Expected: 1, Output:", longest_trend_length(data))

# Run the main function to execute the test cases
if __name__ == "__main__":
    main()
