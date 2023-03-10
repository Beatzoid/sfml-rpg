#include "Game.h"

/* Static Functions */

/* Init Functions */

void Game::initWindow()
{
    /*
        Creates an SFML window using settings from a window.ini file
    */

    /*
        This path is relative to the file inside the bin folder
        If you use a different path (e.x. ./config/window.ini)
        then put it here instead
    */
    std::ifstream ifs("./window.ini");

    /* Default window settings */

    sf::VideoMode window_bounds(800, 600);
    std::string title = "None";
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;

    // Open the config file and set each line to its specific variable
    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

    // Create the window with the variables above
    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initStates()
{
    this->states.push(new GameState(this->window));
}

/* Constructors/Destructors */

Game::Game()
{
    this->initWindow();
    this->initStates();
}

Game::~Game()
{
    /* Cleanup */

    delete this->window;

    while (!this->states.empty())
    {
        // Deletes the data in the pointer
        delete this->states.top();
        // Deletes the actual pointer
        this->states.pop();
    }
}

/* Functions */

void Game::updateDeltaTime()
{
    // Updates the dt variable with the time it took to update and render the last frame
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

    // Update top (first) state item
    if (!this->states.empty())
        this->states.top()->update(this->dt);
}

void Game::render()
{
    this->window->clear();

    // Put anything you want to render here (between the clear and display lines)

    // Render top (first) state item
    if (!this->states.empty())
        this->states.top()->render(this->window);

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