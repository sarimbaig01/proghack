def partition(A, pivot_index):
    """
    Partition the list A around the element at pivot_index.

    Args:
        A: List of elements to partition.
        pivot_index: Index of the pivot element in A.
    
    Modifies:
        The list A in place.
    """
    # Initialize pointers
    i = 0
    j = len(A) - 1
    pivot = A[pivot_index]  # Pivot value

    # TODO: Implement the partition logic here
