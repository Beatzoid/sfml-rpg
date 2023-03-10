#pragma once
#include "../utils/incl.h"

class State
{
private:
    sf::RenderWindow *window;
    std::vector<sf::Texture *> textures;

public:
    /* Constructors/Destructors */

    /**
     * @brief The State class handles any type of State in the game (editor, menu, game, etc)
     *
     * @param window The window to render the state to
     */
    State(sf::RenderWindow *window);
    virtual ~State();

    /*
        virtual void <name>() = 0; is a pure virtual function
        It makes it so that the parent class (State) doesn't have to implement the methods
        But any class that inherits from State must implement the methods (e.x. MenuState, GameState, etc)
        Very similar to abstract functions in Typescript/Javascript
        For more info, see the NOTES.md file in the root of the repo
    */

    /**
     * @brief Used to cleanup and end the current state
     */
    virtual void endState() = 0;

    /**
     * @brief Update the state
     *
     * @param dt The delta time, which is the time it took the last frame to render
     */
    virtual void update(const float &dt) = 0;

    /**
     * @brief Render the state
     *
     * @param target The target to render to, if null then it renders to the default target
     */
    virtual void render(sf::RenderTarget *target = nullptr) = 0;
};
