#pragma once

class State
{
private:
    std::vector<sf::Texture *> textures;

public:
    /* Constructors/Destructors */

    // The State class handles any type of State in the game (editor, menu, game, etc)
    State();
    virtual ~State();

    /*
        virtual void <name>() = 0; is a pure virtual function
        It makes it so that the parent class (State) doesn't have to implement the methods
        But any class that inherits from State must implement the methods (e.x. MenuState, GameState, etc)
        Very similar to abstract functions in Typescript/Javascript
    */

    // Update the state
    virtual void update() = 0;
    // Render the state
    virtual void render() = 0;
};
