
// Returns a vector of all valid digits that can be placed in the cell at (row, col)
std::vector<char> valid_digits_for_cell(const std::vector<std::vector<char>>& board, int row, int col);

// Identifies the cell with the fewest valid digits and returns its position along with the digit to place in that cell
std::pair<int, int> h_MRV(const std::vector<std::vector<char>>& board, char& bestDigit);

// Solves the Sudoku puzzle using the MRV heuristic, counting the number of recursive calls made
bool solve_sudoku_MRV(std::vector<std::vector<char>>& board, int &solveSudokuMRVCalls);