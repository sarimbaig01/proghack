def main():
    # Test case 1
    image = [5, 3, 2, 6, 4, 0, 11, 9, -7, 13]
    frozen_indices = [0, 2, 4, 6]
    reverse_with_frozen_indices(image, frozen_indices)
    print("Test case 1 - Expected: [5, 13, 2, -7, 4, 9, 11, 0, 6, 3], Output:", image)
    
    # Test case 2
    image = [7, 14, 2, 8, -1, 5, 0, 3, 9, -4, 12, 6]
    frozen_indices = [1, 3, 5, 7, 10]
    reverse_with_frozen_indices(image, frozen_indices)
    print("Test case 2 - Expected: [6, 14, -4, 8, 9, 5, 3, 3, 0, 2, 12, 7], Output:", image)
    
    # Test case 3
    image = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    frozen_indices = [0, 4, 9]
    reverse_with_frozen_indices(image, frozen_indices)
    print("Test case 3 - Expected: [1, 9, 8, 7, 5, 6, 4, 3, 2, 10], Output:", image)
    
    # Test case 4
    image = [15, -10, 30, -20, 25, -5, 40, -30, 50, -40]
    frozen_indices = [1, 3, 7]
    reverse_with_frozen_indices(image, frozen_indices)
    print("Test case 4 - Expected: [-40, -10, 50, -20, 40, 25, -5, -30, 30, 15], Output:", image)

# Call the main function to execute the test cases
if __name__ == "__main__":
    main()
