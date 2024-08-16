
#include <iostream>
#include <vector>
#include <utility>

#define N 9

// Checks if placing a number in a specific 3x3 subgrid is valid, i.e., it does not
// violate the uniqueness condition in the row, column and subgrid.
// You may find it useful to write utility functions that check row, column and subgrid contraints separately.
bool isValid(const std::vector<std::vector<char>>& board, int startRow, int startCol, char num);

// Solves the Sudoku puzzle using a recursive backtracking approach.
// Each call to placeValue within solveSudoku increments the placementAttempts parameter.
// This keeps a global count of all placement attempts (both successful and unsuccessful),
// providing a measure of the cost incurred to find the solution.
bool solveSudoku(std::vector<std::vector<char>>& board, int &placementAttempts);

// Places the value num at cell (row, col) and increments placementAttempts
bool placeValue(std::vector<std::vector<char>>& board, int row, int col, char num, int &placementAttempts) {
    placementAttempts++;
    if (isValid(board, row, col, num)) {
        board[row][col] = num;
        return true;
    }
    return false;
}

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
    std::vector<std::vector<std::vector<char>>> boards = {
        {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        },
        {
            {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '3', '6', '.', '.', '.', '.', '.'},
            {'.', '7', '.', '.', '9', '.', '2', '.', '.'},
            {'.', '5', '.', '.', '.', '7', '.', '.', '.'},
            {'.', '.', '.', '.', '4', '5', '7', '.', '.'},
            {'.', '.', '.', '1', '.', '.', '.', '3', '.'},
            {'.', '.', '1', '.', '.', '.', '.', '6', '8'},
            {'.', '.', '8', '5', '.', '.', '.', '1', '.'},
            {'.', '9', '.', '.', '.', '.', '4', '.', '.'}
        },
        {
            {'.', '.', '.', '2', '6', '.', '7', '.', '1'},
            {'6', '8', '.', '.', '7', '.', '.', '9', '.'},
            {'1', '9', '.', '.', '.', '4', '5', '.', '.'},
            {'8', '2', '.', '1', '.', '.', '.', '4', '.'},
            {'.', '.', '4', '6', '.', '2', '9', '.', '.'},
            {'.', '5', '.', '.', '.', '3', '.', '2', '8'},
            {'.', '.', '9', '3', '.', '.', '.', '7', '4'},
            {'.', '4', '.', '.', '5', '.', '.', '3', '6'},
            {'7', '.', '3', '.', '1', '8', '.', '.', '.'}
        }
    };

    for (int i = 0; i < boards.size(); ++i) {
        std::vector<std::vector<char>> board = boards[i];
        int placementAttempts = 0;  // Initialize the counter for placement attempts

        std::cout << "Initial Sudoku Board " << i + 1 << ":" << std::endl;
        printBoard(board);

        if (solveSudoku(board, placementAttempts)) {
            std::cout << "Sudoku Solved Successfully using basic backtracking:" << std::endl;
            printBoard(board);
        } else {
            std::cout << "No solution exists for Sudoku Board " << i + 1 << " using basic backtracking." << std::endl;
        }

        std::cout << "Number of placement attempts: " << placementAttempts << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
