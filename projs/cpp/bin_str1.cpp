#include <iostream>
#include <string>
#include <vector>

void bstrings_sort_sel(std::vector<std::string> & bin_strings)
{
   //TODO: Implement this function, using the repeated selection method
}

// Use the following main to test your function
int main()
{
    std::vector<std::string> grid2 = {
        "01", "01", "11", "10"};

    // Test Grid 1: Length 3
    std::vector<std::string> grid3 = {
        "101", "001", "111", "010", "000", "011", "100", "110"};

    // Test Grid 2: Length 7
    std::vector<std::string> grid7 = {
        "1010101", "0000001", "1111111", "0101010",
        "0011001", "1010010", "1100110", "0001111"};

    // Test Grid 3: Length 20
    std::vector<std::string> grid20 = {
        "10101010101010101010",
        "00000000000000000001",
        "11111111111111111111",
        "01010101010101010101",
        "00110011001100110011",
        "11001100110011001100",
        "10011001100110011001",
        "01100110011001100110"};

    // Store grids in a single collection to iterate through
    std::vector<std::vector<std::string>> grids = {grid2, grid3, grid7, grid20};

    // Process each grid
    for (size_t i = 0; i < grids.size(); ++i)
    {
        std::cout << std::endl << "Grid " << i + 1 << " before sorting:" << std::endl;
        for (size_t j = 0; j < grids[i].size(); ++j)
        {
            std::cout << grids[i][j] << std::endl;
        }

        // Call the bstrings_sort_sel function (not implemented)
        bstrings_sort_sel(grids[i]);

        std::cout << std::endl << "Grid " << i + 1 << " after sorting:" << std::endl;
        for (size_t j = 0; j < grids[i].size(); ++j)
        {
            std::cout << grids[i][j] << std::endl;
        }
    }

    return 0;
}