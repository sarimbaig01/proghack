#include <iostream>
#include <vector>

#define N 9

// Checks if placing a number in a specific row is valid.
bool validRow(const std::vector<std::vector<char>>& board, int row, char num);

// Checks if placing a number in a specific column is valid.
bool validCol(const std::vector<std::vector<char>>& board, int col, char num);

// Checks if placing a number in a specific 3x3 subgrid is valid.
bool validGrid(const std::vector<std::vector<char>>& board, int startRow, int startCol, char num);

// Solves the Sudoku puzzle using a recursive backtracking approach.
bool solveSudoku(std::vector<std::vector<char>>& board);

// Prints the current state of the Sudoku board.
void printBoard(const std::vector<std::vector<char>>& board) {
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            std::cout << board[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    std::cout << "Initial Sudoku Board:" << std::endl;
    printBoard(board);

    if (solveSudoku(board)) {
        std::cout << "Sudoku Solved Successfully:" << std::endl;
        printBoard(board);
    } else {
        std::cout << "No solution exists for the given Sudoku board." << std::endl;
    }

    return 0;
}
