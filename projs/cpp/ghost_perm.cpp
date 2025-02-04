#include <iostream>
#include <vector>
#include <fstream>
#include <string>

void readInput(const std::string &filename, int &n, int &m, std::vector<int> &rungs)
{
    n = 0; 
    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cout << "Error: Could not open file " << filename << std::endl;
        return;
    }

    infile >> n >> m;
    rungs.resize(m);
    for (int i = 0; i < m; i++)
    {
        infile >> rungs[i];
    }

    infile.close();
}

// Function to compute the Ghost Leg permutation 
std::vector<int> ghost_permutation(int n, const std::vector<int> &rungs)
{
    // TODO: Implement this function
    return std::vector<int>();
}

int main()
{
    std::string testFiles[3] = {"input4.txt", "input5.txt", "input6.txt"};

    for (int i = 0; i < 3; i++)
    {
        int n, m;

        std::vector<int> rungs;

        readInput(testFiles[i], n, m, rungs);

        if (n > 0)
        {
            std::vector<int> result = ghost_permutation(n, rungs);

            // Print result
            std::cout << "Test case: " << testFiles[i] << std::endl;
            for (int j = 0; j < result.size(); j++)
            {
                std::cout << result[j] << std::endl;
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
