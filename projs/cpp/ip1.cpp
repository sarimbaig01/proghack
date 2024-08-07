#include <iostream>
#include <vector>

// Function prototypes
void addToPlaylist(std::vector<char>& data, std::vector<int>& links, int& start, char song);
void removeFromPlaylist(std::vector<char>& data, std::vector<int>& links, int& start, int songIndex);
void defragment(std::vector<char>& data, std::vector<int>& links, int& start);
void shufflePlaylist(std::vector<char>& data, std::vector<int>& links, int& start);

int main() {
    std::vector<char> data(200);  // Initialize vector with size 200
    std::vector<int> links(200, -1);  // Initialize vector with size 200, filled with -1
    int start = 0;

    // Example initialization (A -> P -> X)
    data[0] = 'A';
    data[1] = 'P';
    data[2] = 'X';
    links[0] = 1;  // A -> P
    links[1] = 2;  // P -> X
    links[2] = -1; // X is the last song

    std::cout << "Initial playlist:\n";
    for (int i = start; i != -1; i = links[i]) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    // Test addToPlaylist
    char newSong = 'Q';
    addToPlaylist(data, links, start, newSong);
    std::cout << "Playlist after adding Q:\n";
    for (int i = start; i != -1; i = links[i]) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    // Test removeFromPlaylist
    removeFromPlaylist(data, links, start, 1); // Remove song P
    std::cout << "Playlist after removing P:\n";
    for (int i = start; i != -1; i = links[i]) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    // Test defragment
    defragment(data, links, start);
    std::cout << "Playlist after defragmenting:\n";
    for (int i = start; i != -1; i = links[i]) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    // Test shufflePlaylist
    shufflePlaylist(data, links, start);
    std::cout << "Playlist after shuffling:\n";
    for (int i = start; i != -1; i = links[i]) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
