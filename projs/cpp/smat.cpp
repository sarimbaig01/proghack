#include <iostream>
#include <vector>

// Structure to represent a node of the sparse matrix linked list
struct MatrixNode {
    int row;
    int col;
    double value;
    MatrixNode* next;
};

// Function prototypes for sparse matrix operations

// Add two sparse matrices
MatrixNode* addMatrices(MatrixNode* matrix1, MatrixNode* matrix2);

// Subtract matrix2 from matrix1
MatrixNode* subtractMatrices(MatrixNode* matrix1, MatrixNode* matrix2);

// Multiply two sparse matrices (assume compatibility)
MatrixNode* multiplyMatrices(MatrixNode* matrix1, MatrixNode* matrix2, int rows1, int cols1, int cols2);

// Multiply a sparse matrix by a vector (assume compatibility)
void multiplyMatrixByVector(MatrixNode* matrix, const std::vector<double>& vector, std::vector<double>& result, int rows, int cols);

// Transpose a sparse matrix
MatrixNode* transposeMatrix(MatrixNode* matrix);

// Scale a sparse matrix by a scalar
void scaleMatrix(MatrixNode* matrix, double scalar);

// Zero out a specific row in the matrix
MatrixNode* zeroOutRow(MatrixNode* matrix, int rowToZero);

// Zero out a specific column in the matrix
MatrixNode* zeroOutColumn(MatrixNode* matrix, int colToZero);

// Swap two rows of the matrix
MatrixNode* swapRows(MatrixNode* matrix, int row1, int row2);

// Swap two columns of the matrix
MatrixNode* swapColumns(MatrixNode* matrix, int col1, int col2);

// Utility function to add a node to the sparse matrix
MatrixNode* addNode(MatrixNode* head, int row, int col, double value);

// Utility function to display the sparse matrix
void displayMatrix(MatrixNode* matrix) {
    MatrixNode* current = matrix;
    while (current != nullptr) {
        std::cout << "(" << current->row << ", " << current->col << ", " << current->value << ") ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Main function
int main() {
    // Create a sparse matrix
    MatrixNode* matrix1 = nullptr;
    matrix1 = addNode(matrix1, 0, 0, 5);
    matrix1 = addNode(matrix1, 0, 2, 3);
    matrix1 = addNode(matrix1, 1, 1, 22);
    matrix1 = addNode(matrix1, 2, 1, 17);
    matrix1 = addNode(matrix1, 3, 4, 4);

    MatrixNode* matrix2 = nullptr;
    matrix2 = addNode(matrix2, 0, 0, 1);
    matrix2 = addNode(matrix2, 0, 2, 2);
    matrix2 = addNode(matrix2, 1, 1, 3);
    matrix2 = addNode(matrix2, 2, 1, 5);
    matrix2 = addNode(matrix2, 3, 4, 6);

    // Display matrices
    std::cout << "Matrix 1: \n";
    displayMatrix(matrix1);
    
    std::cout << "Matrix 2: \n";
    displayMatrix(matrix2);

    // Perform operations
    MatrixNode* sum = addMatrices(matrix1, matrix2);
    std::cout << "Sum of matrices: \n";
    displayMatrix(sum);

    MatrixNode* diff = subtractMatrices(matrix1, matrix2);
    std::cout << "Difference of matrices: \n";
    displayMatrix(diff);

    MatrixNode* product = multiplyMatrices(matrix1, matrix2, 4, 5, 5); // assuming 4x5 matrices
    std::cout << "Product of matrices: \n";
    displayMatrix(product);

    MatrixNode* transposed = transposeMatrix(matrix1);
    std::cout << "Transpose of matrix 1: \n";
    displayMatrix(transposed);

    // Multiply a sparse matrix by a vector (assume compatibility)
    std::vector<double> vector = {1, 2, 3, 4, 5};
    std::vector<double> result(vector.size(), 0);  // initialize result vector with size of 'vector' and values 0
    multiplyMatrixByVector(matrix1, vector, result, 4, 5);
    std::cout << "Matrix 1 multiplied by vector: ";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    // Scale the matrix by a scalar
    scaleMatrix(matrix1, 2);
    std::cout << "Matrix 1 scaled by 2: \n";
    displayMatrix(matrix1);

    // Zero out row 1
    MatrixNode* zeroRow = zeroOutRow(matrix1, 1);
    std::cout << "Matrix 1 with row 1 zeroed out: \n";
    displayMatrix(zeroRow);

    // Zero out column 2
    MatrixNode* zeroCol = zeroOutColumn(matrix1, 2);
    std::cout << "Matrix 1 with column 2 zeroed out: \n";
    displayMatrix(zeroCol);

    // Swap rows 1 and 2
    MatrixNode* swappedRows = swapRows(matrix1, 1, 2);
    std::cout << "Matrix 1 with rows 1 and 2 swapped: \n";
    displayMatrix(swappedRows);

    // Swap columns 0 and 3
    MatrixNode* swappedCols = swapColumns(matrix1, 0, 3);
    std::cout << "Matrix 1 with columns 0 and 3 swapped: \n";
    displayMatrix(swappedCols);

    return 0;
}

