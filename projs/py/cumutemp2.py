def main():
    # Test cases with expected outputs
    test_data = [
        ([2, -4, 3, -1, 5, -2, 7, -3], (2, 6, 12)),
        ([-5, -1, -8, 4, -2, 6, -3, 1], (3, 5, 8)),
        ([1, -3, 2, 1, -1, 3, -2, 4, -5], (2, 7, 7)),
        ([-1, -2], (0, 0, -1)),  # Example with all negative values
        ([-3, -5, -1, -7], (2, 2, -1))  # Another example with all negative values
    ]
    
    # Initialize test case counter
    test_case_number = 1
    
    # Run each test case
    for test_case in test_data:
        temperatures, expected = test_case
        result = max_cumulative_temperature(temperatures)
        
        # Print test case information without f-string formatting
        print("Test Case " + str(test_case_number) + ":")
        print("Temperatures: " + str(temperatures))
        print("Expected Output: Start Index = " + str(expected[0]) + ", End Index = " + str(expected[1]) + ", Max Sum = " + str(expected[2]))
        print("Function Output: Start Index = " + str(result[0]) + ", End Index = " + str(result[1]) + ", Max Sum = " + str(result[2]))
        
    
        
        # Increment the test case counter
        test_case_number += 1

# Run the main function to test
if __name__ == "__main__":
    main()
