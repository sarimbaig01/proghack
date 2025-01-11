#include <iostream>
#include <string>
#include <vector>

void bstrings_sort_sel(std::vector<std::string> &bin_strings)
{
    for (int i = 0; i < bin_strings.size(); ++i)
    {

        int min_str_i = i;

        for (int j = i + 1; j < bin_strings.size(); ++j)
        {
            if (bin_strings[j] < bin_strings[min_str_i])
            {
                min_str_i = j;
            }
        }

        std::swap(bin_strings[i], bin_strings[min_str_i]);
    }
}

void sort_on_digit(const std::vector<std::string> &source, std::vector<std::string> &dest, int dig_num)
{

    int N = source.size();

    // pass for 0's
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        if (source[i][dig_num] == '0')
        {
            dest[k] = source[i];
            k++;
        }
    }

    // pass for 1's
    for (int i = 0; i < N; i++)
    {
        if (source[i][dig_num] == '1')
        {
            dest[k] = source[i];
            k++;
        }
    }
}

void bstrings_sort_fast(std::vector<std::string> &bin_strings)
{

    std::vector<std::string> b_aux = bin_strings;

    bool turn = true;
    for (int dig_num = bin_strings[0].size() - 1; dig_num >= 0; dig_num--)
    {
        if (turn)
            sort_on_digit(bin_strings, b_aux, dig_num);
        else
            sort_on_digit(b_aux, bin_strings, dig_num);

        turn = !turn;
    }

    // Copy data back into bin_strings, if required
    if (!turn)
        bin_strings = b_aux;
}

std::vector<std::string> trim_grid(const std::vector<std::string> & bin_strings, int dig_num, char last_dig){
    std::vector<std::string> trimmed;
    for(int i=0; i<bin_strings.size(); i++){
        if(bin_strings[i][dig_num]==last_dig){
            trimmed.push_back(bin_strings[i]);
        }
    }
    return trimmed;
}

std::string missing_bstring(const std::vector<std::string> &bin_strings)
{
    std::vector<std::string> aux = bin_strings;
    bstrings_sort_fast(aux);

    std::string missing;
    int d = aux[0].size();

    for (int dig_num = 0; dig_num < d; dig_num++)
    {
        int zero_count = 0, one_count = 0;

        for (int i = 0; i < aux.size(); i++)
        {
            zero_count+=aux[i][dig_num]=='0';
            one_count+=aux[i][dig_num]=='1';
        }

        if(zero_count > one_count){
            missing.push_back('1');
        }else{
            missing.push_back('0');
        }

        aux = trim_grid(aux, dig_num,missing[missing.size()-1]);
    }

    return missing;
}

int main() {
    // Test cases
    struct TestCase {
        int d;
        std::vector<std::string> grid;
        std::string expected;
    };

    std::vector<TestCase> test_cases = {
        {3, {"011", "000", "101", "110", "111", "100", "001"}, "010"},
        {3, {"110", "101", "011", "000", "111", "010", "100"}, "001"},
        {4, {"1011", "0100", "0111", "1111", "0000", "0011", "1001", "1101", "0010", "1000", "0101", "1110", "0110", "1100", "0001"}, "1010"},
        {4, {"0110", "1101", "1010", "1111", "0000", "0101", "0010", "1001", "0111", "0001", "1011", "1110", "1000", "0011", "0100"}, "1100"},
        {5, {"00000", "00001", "00010", "00011", "00100", "00101", "00110", "00111", "01000", "01001", "01010", "01011", "01100", "01110", "01111", "10000", "10001", "10010", "10011", "10100", "10101", "10110", "10111", "11000", "11001", "11010", "11011", "11100", "11101", "11110", "11111"}, "01101" }
    };

    // Run the test cases
    for (size_t i = 0; i < test_cases.size(); ++i) {
        int d = test_cases[i].d;
        const std::vector<std::string> &grid = test_cases[i].grid;
        const std::string &expected = test_cases[i].expected;

        std::string result = missing_bstring(grid);

        std::cout << "Test Case " << i + 1 << " (d = " << d << "):\n";
        std::cout << "  Missing string: " << expected << "\n";
        std::cout << "  Computed string: " << result << "\n";

        if (result == expected) {
            std::cout << "  Test passed!\n\n";
        } else {
            std::cout << "  Test failed!\n\n";
        }
    }

    return 0;
}
/*int main()
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
        std::cout << "\nGrid " << i + 1 << " before sorting:\n";
        for (size_t j = 0; j < grids[i].size(); ++j)
        {
            std::cout << grids[i][j] << "\n";
        }

        // Call the bstrings_sort_sel function (not implemented)
        bstrings_sort_fast(grids[i]);

        std::cout << "\nGrid " << i + 1 << " after sorting:\n";
        for (size_t j = 0; j < grids[i].size(); ++j)
        {
            std::cout << grids[i][j] << "\n";
        }
    }

    return 0;
}*/
