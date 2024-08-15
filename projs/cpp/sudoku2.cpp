
// Returns the number of valid digits that can be placed in the cell at (row, col).
int countMRV(const std::vector<std::vector<char>>& board, int row, int col);

// Finds the cell with the minimum remaining values (fewest legal options) and suggests a valid digit to place there.
std::pair<int, int> hMRV(const std::vector<std::vector<char>>& board, char& bestDigit);

// Solves the Sudoku puzzle using the MRV heuristic, counting the number of recursive calls made.
bool solveSudokuMRV(std::vector<std::vector<char>>& board, int &solveSudokuMRVCalls);
