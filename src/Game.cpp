#include "Game.h"

/* Static Functions */

/* Init Functions */

void Game::initWindow()
{
    /*
        Creates an SFML window using the full desktop width and height as the window size
        and also gives it a simple title
        TODO: Load the window options from a file (e.x. window.ini)
    */
    this->window = new sf::RenderWindow(
        sf::VideoMode(
            sf::VideoMode::getDesktopMode().width,
            sf::VideoMode::getDesktopMode().height),
        "SFML Application");
}

/* Constructors/Destructors */

Game::Game()
{
    this->initWindow();
}

Game::~Game()
{
    /* Cleanup */

    delete this->window;
}

/* Functions */

void Game::updateDeltaTime()
{
    /* Updates the dt variable with the time it took to update and render the last frame */
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        // This makes sure that the close event actually closes the window
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->updateSFMLEvents();
}

void Game::render()
{
    this->window->clear();

    // Put anything you want to render here (between the clear and display lines)

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDeltaTime();
        this->update();
        this->render();
    }
}