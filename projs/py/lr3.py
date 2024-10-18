def main():
    # List of test cases
    test_cases = [
        ([2, 1, 5, 6, 2, 3], (2, 3, 10)),  # Test Case 1
        ([1, 3, 2, 5, 4, 1], (1, 3, 9)),    # Test Case 2
        ([4, 2, 0, 3, 2], (0, 4, 10))        # Test Case 3
    ]
    
    for i, (count, expected) in enumerate(test_cases):
        left_index, right_index, area = largest_rectangle_brute_force(count)
        
        # Output the results
        print(f"Test Case {i + 1} Results:")
        print("Left Side Index:", left_index, "| Expected:", expected[0])
        print("Right Side Index:", right_index, "| Expected:", expected[1])
        print("Area of the Largest Rectangle:", area, "| Expected:", expected[2])
        
        # Check if the results match
        test_passed = (left_index == expected[0] and 
                       right_index == expected[1] and 
                       area == expected[2])
        print("Test passed:", test_passed)
        print()

if __name__ == "__main__":
    main()
