#include <SFML/Graphics.hpp>
#include <vector>

//This is a graphics related function implemented for you.
//You may not bother about this code yet, 
//however, when something visual needs to be done 
//you'd need to make changes in this function.
void drawGrid(sf::RenderWindow &window, const std::vector<std::vector<int>> &grid, int rows, int cols, int cellSize) {
    window.clear(sf::Color::White);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setPosition(j * cellSize, i * cellSize);
            if (grid[i][j] == 1) {
                cell.setFillColor(sf::Color::Black);
            } else {
                cell.setFillColor(sf::Color::White);
                cell.setOutlineColor(sf::Color::Black);
                cell.setOutlineThickness(1);
            }
            window.draw(cell);
        }
    }

    window.display();
}

//Funtions to be implemented

void generateRandomInitConf(std::vector<std::vector<int>> &grid, int rows, int cols, float liveProbability) {
    //TODO: add code here
    //the function sets any given cell to alive with probability liveProbability
}

int countLiveNeighbours(const std::vector<std::vector<int>> &grid, int i, int j, int rows, int cols) {
    ///count the live neighbors of the cell at grid[i][j]
    int liveNeighbors = 0;
    //TODO: add code here
    return liveNeighbors;
}

void updateGrid(std::vector<std::vector<int>> &grid, int rows, int cols) {
    //TODO: add code here
}

//The main 
int main() {
   //Using the following parameters we get a window size of 600x600 pixels
   //The grid itself is 100 x 100 cells, and each cell is 6x6 pixels

    const int rows = 100;  // Number of rows in the grid
    const int cols = 100;  // Number of columns in the grid
    const int cellSize = 6;  // Size of each cell in pixels

    const float updateInterval = 0.09f; // Time between generations in seconds

    //Open the graphics window
    sf::RenderWindow window(sf::VideoMode(cols * cellSize, rows * cellSize), "Conway's Game of Life");

    //Create the grid vector
    std::vector<std::vector<int>> grid(rows, std::vector<int>(cols, 0));

    //Generate a random initial configuration
    //with the probability of any call being alive = 0.2 
  
    //generateRandomInitConf(grid, 100, 100, 0.2); //Function needs implementation

    //clock is used to measure elapsed time
    sf::Clock clock;

   //The main event loop
   ///The only event we're handling at the moment is window close 
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ///After each 0.09 seconds progress to the next generation
        if (clock.getElapsedTime().asSeconds() > updateInterval) {
          
            //updateGrid(grid, rows, cols); //Function needs implementation
          
            drawGrid(window, grid, rows, cols, cellSize);
            clock.restart();//Start measuring again from 0
        }
    }

    return 0;
}
