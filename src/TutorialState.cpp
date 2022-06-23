#include "TutorialState.h"

// Private functions
void TutorialState::initFonts()
{
    if (!this->font.loadFromFile("Resources/Fonts/PixellettersFull.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }
}

void TutorialState::initButtons()
{
    float x = this->window->getSize().x * 0.13f;
    float y = this->window->getSize().y * 0.85f;
    float size = this->window->getSize().y * 0.045;

    this->buttons["MAIN_MENU_STATE"] = new Button(x, y, size, size + 5, &this->font, "Main Menu", 
        sf::Color(255, 255, 255, 255), sf::Color(255, 246, 18, 255), sf::Color(255, 246, 18, 150));
}

void TutorialState::initBackground()
{
    if (!this->backgroundTex.loadFromFile("Resources/Textures/tutorial_bg.jpg"))
    {
        std::cout << "Failed to load TutorialState_background" << std::endl;
    }
    this->background.setTexture(this->backgroundTex);
    this->background.setScale(
        static_cast<float>(this->window->getSize().x) / this->background.getLocalBounds().width,
		static_cast<float>(this->window->getSize().y) / this->background.getLocalBounds().height);
}

// Constructor & Destructor
TutorialState::TutorialState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
    this->playMenuMusic = true;
    this->initFonts();
    this->initButtons();
    this->initBackground();
}

TutorialState::~TutorialState()
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
void TutorialState::updateButtons()
{
    for (auto& button : this->buttons)
    {
        button.second->update(this->mousePosWindow);
    }

    // MainMenu button
    if (this->buttons["MAIN_MENU_STATE"]->isPressed())
    {
        this->endState();
    }

}

void TutorialState::update(const float& dt)
{
    this->updateMousePositions();
    this->updateButtons();
}

void TutorialState::renderBackground()
{
    this->window->draw(this->background);
}

void TutorialState::renderButtons(sf::RenderTarget& target)
{
    for (auto& button : this->buttons)
    {
        button.second->render(target);
    }
}

void TutorialState::render(sf::RenderTarget* target)
{
    if (!target)
    {
        target = this->window;
    }

    this->renderBackground();

    this->renderButtons(*target);
}