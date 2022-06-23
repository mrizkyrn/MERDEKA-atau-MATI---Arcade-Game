#include "State.h"

// Constructor & Destructor
State::State(sf::RenderWindow* window, std::stack<State*>* states)
{
    this->window = window;
    this->states = states;
    this->quit = false;
    this->mainMenu = false;
    this->paused = false;
    this->playMenuMusic = false;
    this->playGameMusic = false;
}

State::~State()
{
    
}

// Accessor
const bool& State::getQuit() const
{
    return this->quit;
}

const bool& State::getMainMenu() const
{
    return this->mainMenu;
}

const bool& State::getPaused() const
{
    return this->paused;
}

const bool& State::getMenuMusic() const
{
    return this->playMenuMusic;
}

const bool& State::getGameMusic() const
{
    return this->playGameMusic;
}

// Functions
void State::endState()
{
    this->quit = true;
}

void State::updateMousePositions()
{
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}