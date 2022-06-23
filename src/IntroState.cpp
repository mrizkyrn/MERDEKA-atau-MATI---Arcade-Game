#include "IntroState.h"

// Private functions
void IntroState::initFonts()
{
    if (!this->font.loadFromFile("Resources/Fonts/PixellettersFull.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }
}

void IntroState::initButtons()
{
    float x = this->window->getSize().x * 0.9f;
    float y = this->window->getSize().y * 0.85f;
    float size = this->window->getSize().y * 0.045;

    this->buttons["MAIN_MENU_STATE"] = new Button(x, y, size, size + 5, &this->font, "Next", 
        sf::Color(255, 255, 255, 255), sf::Color(255, 246, 18, 255), sf::Color(255, 246, 18, 150));
}

void IntroState::initBackground()
{
    if (!this->backgroundTex.loadFromFile("Resources/Textures/intro_bg.jpg"))
    {
        std::cout << "Failed to load main menu background" << std::endl;
    }
    this->background.setTexture(this->backgroundTex);
    this->background.setScale(
		static_cast<float>(this->window->getSize().x) / this->background.getLocalBounds().width,
		static_cast<float>(this->window->getSize().y) / this->background.getLocalBounds().height);

    this->fadeBackground.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
    this->fadeBackground.setFillColor(sf::Color(0, 0, 0, 255));

    this->alpha = 255;
}

// Constructor & Destructor
IntroState::IntroState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
    this->initFonts();
    this->initButtons();
    this->initBackground();
}

IntroState::~IntroState()
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
void IntroState::updateFadeBackground()
{
    if (this->alpha > 0)
    {
        this->alpha -= 1;
    }

    this->fadeBackground.setFillColor(sf::Color(0, 0, 0, this->alpha));
}

void IntroState::updateButtons()
{
    for (auto& button : this->buttons)
    {
        button.second->update(this->mousePosWindow);
    }

    // GameState button
    if (this->buttons["MAIN_MENU_STATE"]->isPressed())
    {
        this->states->push(new MainMenu(this->window, this->states));
    }
}

void IntroState::update(const float& dt)
{
    this->updateFadeBackground();
    this->updateMousePositions();
    this->updateButtons();
}

void IntroState::renderButtons(sf::RenderTarget& target)
{
    for (auto& button : this->buttons)
    {
        button.second->render(target);
    }
}

void IntroState::render(sf::RenderTarget* target)
{
    if (!target)
    {
        target = this->window;
    }

    this->window->draw(this->background);

    if(this->alpha == 0)
        this->renderButtons(*target);

    this->window->draw(this->fadeBackground);
}