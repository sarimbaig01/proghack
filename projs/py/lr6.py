def largest_rectangle_linear(count):
    """
    Function to compute the largest rectangle (which may or may not contain spikes)
    using a linear time approach.

    Parameters:
    count (list): A list of integers representing the heights of the histogram bars.

    Returns:
    tuple: A tuple containing the left side index, right side index, and the area of the largest rectangle.
    """

    n = len(count)
    
    # Auxiliary arrays
    left_boundaries = [0] * n  # Left boundary of the largest rectangle ending at each bar
    rect_heights = [0] * n  # Heights of rectangles ending at each bar
    max_area = 0
    max_left = 0
    max_right = 0
    
    for i in range(n):
        if i == 0:
            # For the first bar, the rectangle starts at i itself
            left_boundaries[i] = i
            rect_heights[i] = count[i]
        else:
            #TODO: add code to compute left_boundaries[i] and rect_heights[i]
            #using left_boundaries[i-1], rect_heights[i-1], and count[i]

    #Scan the computed lists to find the largest rectangle overall
    for i in range(n):
        area = rect_heights[i] * (i - left_boundaries[i] + 1)
        max_left, max_right, max_area = updateMaxRectangle(left_boundaries[i], i, area, max_left, max_right, max_area)
        
    
    return (max_left, max_right, max_area)

