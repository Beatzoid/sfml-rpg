#pragma once
#include "../../utils/incl.h"

#include "../State.h"

class GameState : public State
{
private:
public:
    /* Constructors/Destructors */

    /**
     * @brief The GameState class handles the state for the game
     *
     * @param window The window to render the state to
     */
    GameState(sf::RenderWindow *window);
    virtual ~GameState();

    /* Functions */

    // End and cleanup the state
    void endState();

    /**
     * @brief Update the GameState
     *
     * @param dt The delta time, which is the time it took the last frame to render
     */
    void update(const float &dt);

    /**
     * @brief Render the GameStrate
     *
     * @param target The target to render to, if null then it renders to the default target
     */
    void render(sf::RenderTarget *target = nullptr);
};