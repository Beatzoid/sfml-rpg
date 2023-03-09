#pragma once

class Game
{
private:
    /* Variables */

    // The main game window
    sf::RenderWindow *window;
    // The SFML event
    sf::Event sfEvent;

    // Delta clock, works with the delta time to keep track of the time since the last frame
    sf::Clock dtClock;
    // Delta time, works with the delta clock to keep track of the time since the last frame
    float dt;

    /* Initializers */

    // Initialize the window
    void initWindow();

public:
    /* Constructors/Destructors */

    // The Game class manages all the core logic for the game
    Game();
    virtual ~Game();

    /* Functions */

    // Update the delta time
    void updateDeltaTime();
    // Handles all SFML events
    void updateSFMLEvents();
    // Updates the Game
    void update();
    // Renders all objects for the game
    void render();
    // Run the game
    void run();
};
