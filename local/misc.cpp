#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> trim_grid(const std::vector<std::string> &bin_strings, int dig_num, char last_dig)
{
    std::vector<std::string> trimmed;
    for (int i = 0; i < bin_strings.size(); i++)
    {
        if (bin_strings[i][dig_num] == last_dig)
        {
            trimmed.push_back(bin_strings[i]);
        }
    }
    return trimmed;
}

std::string missing_machine(const std::vector<std::string> &bin_strings)
{
    std::vector<std::string> aux = bin_strings;
    
    std::string missing;
    int d = aux[0].size();
    for (int dig_num = 0; dig_num < d; dig_num++)
    {
        int zero_count = 0, one_count = 0;
        for (int i = 0; i < aux.size(); i++)
        {
            zero_count += aux[i][dig_num] == '0';
            one_count += aux[i][dig_num] == '1';
        }
        if (zero_count > one_count)
        {
            missing.push_back('1');
        }
        else
        {
            missing.push_back('0');
        }
        aux = trim_grid(aux, dig_num, missing[missing.size() - 1]);
    }
    return missing;
}

int main()
{
    // Test cases
    std::vector<int> dimensions = {3, 3, 4, 4, 5};
    std::vector< std::vector< std::string >> grids = {
        {"011", "000", "101", "110", "111", "100", "001"},
        {"110", "101", "011", "000", "111", "010", "100"},
        {"1011", "0100", "0111", "1111", "0000", "0011", "1001", "1101", "0010", "1000", "0101", "1110", "0110", "1100", "0001"},
        {"0110", "1101", "1010", "1111", "0000", "0101", "0010", "1001", "0111", "0001", "1011", "1110", "1000", "0011", "0100"},
        {"00000", "00001", "00010", "00011", "00100", "00101", "00110", "00111", "01000", "01001", "01010", "01011", "01100", "01110", "01111", "10000", "10001", "10010", "10011", "10100", "10101", "10110", "10111", "11000", "11001", "11010", "11011", "11100", "11101", "11110", "11111"}
    };
    std::vector<std::string> expected_values = {"010", "001", "1010", "1100", "01101"};

    // Run the test cases
    for (size_t i = 0; i < dimensions.size(); ++i)
    {
        int d = dimensions[i];
        std::vector<std::string> grid = grids[i];
        std::string expected = expected_values[i];
        std::string result = missing_machine(grid);
        std::cout << "Test Case " << i + 1 << " (d = " << d << "):" << std::endl;
        std::cout << "  Missing string: " << expected << std::endl;
        std::cout << "  Computed string: " << result << std::endl;
        if (result == expected)
        {
            std::cout << "  Test passed!" << std::endl << std::endl;
        }
        else
        {
            std::cout << "  Test failed!" << std::endl << std::endl;
        }
    }
    return 0;
}