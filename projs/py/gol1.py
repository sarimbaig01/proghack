import pygame
import random

# Constants
GRID_SIZE = 100
CELL_SIZE = 10
SCREEN_SIZE = GRID_SIZE * CELL_SIZE
BLACK, WHITE = (0, 0, 0), (255, 255, 255)

# Initialize Pygame
pygame.init()
screen = pygame.display.set_mode((SCREEN_SIZE, SCREEN_SIZE))
pygame.display.set_caption("Game of Life")

# Generate random initial configuration
def generate_random_init_conf():
    """Generates a random initial grid configuration.
    
    Returns:
        list of list of int: A 2D grid where each cell is randomly set to 0 (dead) or 1 (alive).
    """
    return [[random.choice([0, 1]) for _ in range(GRID_SIZE)] for _ in range(GRID_SIZE)]

# Stub for counting alive neighbors
def count_alive_neighbors(grid, x, y):
    """Counts the number of alive (1) neighbors around a cell at position (x, y).
    
    Args:
        grid (list of list of int): The 2D grid representing the current state of the Game of Life.
        x (int): The x-coordinate (row) of the cell.
        y (int): The y-coordinate (column) of the cell.
    
    Returns:
        int: The count of neighboring cells that are alive (have a value of 1).
    """
    # Temporary default return value
    return 0

# In-place update for the grid state
def update_grid(grid):
    """Updates the grid in place based on Game of Life rules.
    
    Args:
        grid (list of list of int): The 2D grid representing the current state of the Game of Life.
    
    This function modifies `grid` directly, without returning a new grid, to save memory.
    """
    # TODO: Implement logic to update each cell in the grid based on Game of Life rules
    pass

# Draw the grid
def draw_grid(grid):
    """Draws the grid on the Pygame screen.
    
    Args:
        grid (list of list of int): The 2D grid representing the current state of the Game of Life.
    """
    screen.fill(BLACK)
    for i in range(GRID_SIZE):
        for j in range(GRID_SIZE):
            color = WHITE if grid[i][j] == 1 else BLACK
            pygame.draw.rect(screen, color, (j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE))
    pygame.display.flip()

# Main function
def main():
    """Main loop of the Game of Life simulation."""
    grid = generate_random_init_conf()
    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        update_grid(grid)
        draw_grid(grid)
        pygame.time.delay(100)
    pygame.quit()

if __name__ == "__main__":
    main()
