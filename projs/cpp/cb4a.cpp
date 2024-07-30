//The following code should be added in the event loop inside the main

// Check keyboard input

/*
  To learn more about SFML events, 
  see documentation here: https://www.sfml-dev.org/tutorials/2.6/window-events.php
*/

bool moveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
bool moveLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);

// Update the paddle's position
float elapsedTime = clock.restart().asSeconds();
if (moveRight || moveLeft) {
    //TODO: make an appropriate call to the function updatePaddlePosition
}