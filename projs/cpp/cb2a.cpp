void initializePaddle(sf::RectangleShape& paddle, float paddleWidth, float windowHeight) {
    const float paddleHeight = 20.0f; // Hard-coded paddle height
    paddle.setSize(sf::Vector2f(paddleWidth, paddleHeight));
    paddle.setFillColor(sf::Color::Red);
    paddle.setPosition(20, windowHeight - paddleHeight); // Fixed position at the bottom
}

void drawScreen(sf::RenderWindow& window, sf::CircleShape& ball, sf::RectangleShape& paddle) {
    window.clear(sf::Color::Black); // Clear the window with black color
    window.draw(ball);
    window.draw(paddle);
    window.display();
}
