
#include "GameState.h"

GameState::GameState(sf::RenderWindow *window)
    : State(window)
{
}

GameState::~GameState()
{
}

void GameState::update(const float &dt)
{
    std::cout << "Hello from GameState!"
              << "\n"
              << dt
              << "\n";
}

void GameState::render(sf::RenderTarget *target)
{
}

void GameState::endState()
{
}