#include <iostream>
#include <vector>
#include <utility>

#define N 9

// Checks if placing a number in a specific 3x3 subgrid is valid, i.e., it does not
// violate the uniqueness condition in a row, column or subgrid.
bool valid_move(const std::vector<std::vector<char>>& board, int startRow, int startCol, char num);

// Solves the Sudoku puzzle using a recursive backtracking approach.
// Each call increments the solveSodukoCalls parameter, so that
// a global count of all calls per puzzle is maintained.
bool solve_sudoku(std::vector<std::vector<char>>& board, int &solveSudokuCalls);

// Prints the current state of the Sudoku board.
void print_board(const std::vector<std::vector<char>>& board) {
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
            {'5', '1', '7', '6', '.', '.', '.', '3', '4'},
            {'2', '8', '9', '.', '.', '4', '.', '.', '.'},
            {'3', '4', '6', '2', '7', '5', '8', '.', '.'},
            {'.', '6', '8', '3', '4', '7', '1', '.', '.'},
            {'7', '.', '.', '.', '.', '.', '.', '.', '3'},
            {'.', '3', '5', '8', '1', '2', '4', '7', '.'},
            {'.', '7', '.', '.', '2', '6', '3', '4', '8'},
            {'.', '.', '.', '4', '3', '8', '.', '1', '.'},
            {'.', '.', '.', '7', '6', '1', '.', '9', '5'}
        }
    };

    for (int i = 0; i < boards.size(); ++i) {
        std::vector<std::vector<char>> board = boards[i];
        int solveSudokuCalls = 0;  // Initialize the counter for solveSudoku

        std::cout << "Initial Sudoku Board " << i + 1 << ":" << std::endl;
        print_board(board);

        if (solve_sudoku(board, solveSudokuCalls)) {
            std::cout << "Sudoku Solved Successfully:" << std::endl;
            print_board(board);
        } else {
            std::cout << "No solution exists for Sudoku Board " << i + 1 << "." << std::endl;
        }

        std::cout << "Number of calls to solveSudoku: " << solveSudokuCalls << std::endl;
        std::cout << std::endl;
    }

    return 0;
}