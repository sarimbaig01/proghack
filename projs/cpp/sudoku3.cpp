
// Returns the value that, when placed in the cell at (row, col), least constrains the remaining cells.
char h_LCV(const std::vector<std::vector<char>>& board, int row, int col);

// Solves the Sudoku puzzle using the LCV heuristic, returning true if a solution is found.
bool solve_sudoku_LCV(std::vector<std::vector<char>>& board, int &solveSudokuLCVCalls);