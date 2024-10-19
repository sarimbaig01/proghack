def main():
    # List of test cases
    test_cases = [

      ([2, 2, 7, 2, 7, 2, 2, 9, 6, 5, 8, 10, 9, 5, 8, 8, 3, 2, 1, 6], (7, 15, 45)),
      ([5, 4, 5, 9, 6, 2, 8, 8, 8, 6, 4, 6, 3, 1, 8, 9, 9, 5, 1, 6], (0, 12, 26))
    ]
    """
        ([2, 1, 5, 6, 2, 3], (2, 3, 10)),   # Test Case 1
        ([1, 3, 2, 5, 4, 1], (1, 3, 9))     # Test Case 2
        ([4, 2, 0, 3, 2], (0, 3, 12)),      # Test Case 3
        ([3, 1, 4, 1, 5, 9, 2], (2, 4, 12)),# Test Case 4
        ([5], (0, 0, 5)),                   # Test Case 5
        ([1, 4, 9, 1, 4, 1, 11, 3, 2, 2, 10, 1, 6, 4, 5, 5, 9, 8, 5, 2], (10, 16, 63)), # Test Case 6
        ([4, 2, 4, 6, 10, 8, 8, 10, 8, 2, 4, 4, 2, 2, 2, 2, 1, 8, 8, 9], (7, 19, 117))  # Test Case 7"""
   
    
    for i, (count, expected) in enumerate(test_cases):
        left_index, right_index, area = largest_rectangle_linear(count)
        
        # Output the results
        print(f"Test Case {i + 1} Results:")
        print("Left Side Index:", left_index, "| Expected:", expected[0])
        print("Right Side Index:", right_index, "| Expected:", expected[1])
        print("Area of the Largest Rectangle:", area, "| Expected:", expected[2])
        
        # Check if the results match
        test_passed = (left_index == expected[0] and 
                       right_index == expected[1] and 
                       area == expected[2])
        if test_passed: 
            print("Test passed\n")
        else:
            print("Test failed\n")

if __name__ == "__main__":
    main()
