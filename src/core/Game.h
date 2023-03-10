#pragma once

#include "../utils/incl.h"
#include "../state/states/GameState.h"

class Game
{
private:
    /* Variables */

    /**
     * @brief The main game window to which everything that doesn't specify another window
     * is rendered too
     */
    sf::RenderWindow *window;
    /**
     * @brief Keeps track of the current SFML event
     */
    sf::Event sfEvent;

    /**
     * @brief Delta clock, works with the delta time to keep track of the time since the last frame
     */
    sf::Clock dtClock;
    /**
     * @brief Delta time, works with the delta clock to keep track of the time since the last frame
     */
    float dt;

    /**
     * @brief Represents the state stack, which is used to easily keep track and modify
        what state the program is currently in (Game, Menu, Editor, etc) by pushing/popping
        states on/off the stack
     */
    std::stack<State *> states;

    /* Initializers */

    /**
     * @brief Initialize and setup the window
     */
    void initWindow();
    /**
     * @brief Initialize the states and set their default values
     */
    void initStates();

public:
    /* Constructors/Destructors */

    /**
     * @brief The Game class manages all the core logic for the game
     *
     */
    Game();
    virtual ~Game();

    /* Functions */

    /**
     * @brief Updates the delta time
     */
    void updateDeltaTime();
    /**
     * @brief Handles all SFML events
     */
    void updateSFMLEvents();
    /**
     * @brief Update the game
     */
    void update();
    /**
     * @brief Render all objects for the game
     * 
     */
    void render();
    /**
     * @brief Run the game
     */
    void run();
};
