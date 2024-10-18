#Utility function to be used within the following function 
def updateMaxRectangle(left_side, right_side, area, max_left, max_right, max_area):
    if area > max_area:
        max_area = area
        max_left = left_side
        max_right = right_side
    
    return max_left, max_right, max_area



def largest_spikeless_rectangle_brute_force(count):
    """
    Finds the largest rectangle without spikes in the given list of bar heights using a brute-force algorithm.

    Parameters:
    count (list): A list of integers where each element represents the height of a bar.

    Returns:
    tuple: A tuple containing the left side bar index, right side bar index, and area of the largest spikeless rectangle.
    """
    # Brute-force implementation goes here, inspecting all possible spikeless rectangles
    
    return (0, 0, 0)  # Placeholder return values
