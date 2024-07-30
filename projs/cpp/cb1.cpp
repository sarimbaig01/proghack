#include <SFML/Graphics.hpp>

//this function currently places the ball at the origin
//you may change it to place the ball at any random position 
//provided as a parameter 
void initializeBall(sf::CircleShape& ball, float ballRadius) {
    ball.setRadius(ballRadius);
    ball.setFillColor(sf::Color::Yellow);
    // Set the ball position at the origin (top-left corner)
    ball.setPosition(0, 0); 
}

//update this method to move the ball according to
//a certain direction
//a new direction parameter may be introduced
void updateBallPosition(sf::CircleShape& ball, float elapsedTime, float ballSpeed, int windowWidth) {
    sf::Vector2f position = ball.getPosition();

    //moving the ball by 2 times radius moves it by one "ball width" (one diameter)  
    if (position.x + ball.getRadius() * 2 < windowWidth) {
        ball.move(ballSpeed * elapsedTime, 0);
    }
}

//no need to change this function
void drawScreen(sf::RenderWindow& window, sf::CircleShape& ball) {
    // Clear the window with black color
    window.clear(sf::Color::Black); 
    window.draw(ball);
    window.display();
}

int main() {

    // Constants for screen dimensions
    // and ball parameters
    const int windowWidth = 800;
    const int windowHeight = 600;
    const float ballRadius = 20.0; //pixels 
    const float ballSpeed = 400.0; //units per elapsed time 

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Contained Bounce");

    // Create a ball and place it at the origin
    sf::CircleShape ball;
    initializeBall(ball, ballRadius);

    // Clock to measure time between frames
    sf::Clock clock;

    // Main loop
    // Currently the only event being handled is close window
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update the ball's position
        float elapsedTime = clock.restart().asSeconds();
        updateBallPosition(ball, elapsedTime, ballSpeed, windowWidth);

        // Draw the screen
        drawScreen(window, ball);
    }

    return 0;
}