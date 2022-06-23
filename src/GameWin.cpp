#include "GameWIn.h"

// Constructor & Destructor
GameWin::GameWin(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
    this->initFonts();
    this->initButtons();
    this->initBackground();
    this->initCredit();
}

GameWin::~GameWin()
{
    // Delete buttons
    auto it = this->buttons.begin();
    while (it != this->buttons.end())
    {
        delete it->second;
        it++;
    }

    this->buttons.clear();
}

// Functions
void GameWin::updateButtons()
{
    for (auto& button : this->buttons)
    {
        button.second->update(this->mousePosWindow);
    }

    // Main menu button
    if (this->buttons["MAIN_MENU_STATE"]->isPressed())
    {
        this->mainMenu = true;
    }

    // Credit button
    if (this->buttons["CREDIT"]->isPressed() && this->mouseTimer <= 0)
    {
        this->iscreditShown = !this->iscreditShown;
        this->mouseTimer = 10.0f;
    }
}

void GameWin::update(const float& dt)
{
    // Update mouse timer
    if (this->mouseTimer > 0.f)
        this->mouseTimer -= 0.5f;

    this->updateMousePositions();
    this->updateButtons();
}

void GameWin::renderCredit()
{
    if (this->iscreditShown)
    {
        this->window->draw(this->container);
        this->window->draw(this->credit);
    }
}

void GameWin::renderButtons(sf::RenderTarget& target)
{
    for (auto& button : this->buttons)
    {
        button.second->render(target);
    }
}

void GameWin::render(sf::RenderTarget* target)
{
    if (!target)
    {
        target = this->window;
    }

    // Render background
    this->window->draw(this->background);

    // Render credit
    this->renderCredit();

    // Render buttons
    this->renderButtons(*target);
}