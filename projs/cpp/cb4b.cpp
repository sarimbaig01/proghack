void updatePaddlePosition(sf::RectangleShape& paddle, float paddleSpeed, float elapsedTime, int windowWidth, bool moveRight) {
    // Update the paddle's position based on keyboard input
    if (moveRight) {
        paddle.move(paddleSpeed * elapsedTime, 0);
    } else {
        paddle.move(-paddleSpeed * elapsedTime, 0);
    }

    //TODO: add code to ensure that the paddle stays within the window bounds
}