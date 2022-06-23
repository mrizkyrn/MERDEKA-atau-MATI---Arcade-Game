#include "PauseMenu.h"

// Private functions
void PauseMenu::initFonts(sf::RenderWindow* window)
{
    if (!this->font.loadFromFile("Resources/Fonts/PixellettersFull.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }

    // Pause text
    this->pauseText.setFont(this->font);
    this->pauseText.setString("PAUSED");
    this->pauseText.setCharacterSize(window->getSize().x * 0.08f);
    this->pauseText.setFillColor(sf::Color::Yellow);
    this->pauseText.setOutlineThickness(2.5f);
    this->pauseText.setOutlineColor(sf::Color(112, 105, 4, 255));
    this->pauseText.setPosition(window->getSize().x * 0.5f - this->pauseText.getGlobalBounds().width * 0.5f, window->getSize().y * 0.25f);
}

void PauseMenu::initButtons(sf::RenderWindow* window)
{
    float x = window->getSize().x * 0.5f;
    float y = window->getSize().y * 0.1f;
    float size = window->getSize().y * 0.05f;

    this->buttons["RESUME"] = new Button(x, y * 5, size, size, &this->font, "Resume", 
        sf::Color(255, 255, 255, 255), sf::Color(255, 246, 18, 255), sf::Color(255, 246, 18, 100));
    
    this->buttons["MAIN_MENU"] = new Button(x, y * 6, size, size, &this->font, "Main menu", 
        sf::Color(255, 255, 255, 255), sf::Color(255, 246, 18, 255), sf::Color(255, 246, 18, 100));
}

void PauseMenu::initBackground(sf::RenderWindow* window)
{
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color(20, 20, 20, 100));

    this->container.setSize(sf::Vector2f(window->getSize().x * 0.5f, window->getSize().y * 0.5f));
    this->container.setFillColor(sf::Color(20, 20, 20, 200));
    this->container.setPosition(sf::Vector2f(window->getSize().x * 0.25f, window->getSize().y * 0.25f));
}

// Constructor & Destructor
PauseMenu::PauseMenu(sf::RenderWindow* window)
{
    this->initFonts(window);
    this->initButtons(window);
    this->initBackground(window);
}

PauseMenu::~PauseMenu()
{
    for (auto& button : this->buttons)
    {
        delete button.second;
    }

    this->buttons.clear();
}

// Accessor
std::map<std::string, Button*>& PauseMenu::getButtons()
{
    return this->buttons;
}

// Functions
const bool PauseMenu::isButtonPressed(const std::string key)
{
    return this->buttons[key]->isPressed();
}

void PauseMenu::update(const sf::Vector2i& mousePos)
{
    for (auto& button : this->buttons)
    {
        button.second->update(static_cast<sf::Vector2i>(mousePos));
    }
}

void PauseMenu::render(sf::RenderTarget& target)
{
    // Draw background
    target.draw(this->background);
    target.draw(this->container);

    // Draw text
    target.draw(this->pauseText);

    // Draw buttons
    for (auto& button : this->buttons)
    {
        button.second->render(target);
    }
}