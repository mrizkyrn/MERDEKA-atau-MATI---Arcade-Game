#include "MainMenu.h"

// Private functions
void MainMenu::initFonts()
{
    if (!this->font.loadFromFile("Resources/Fonts/PixellettersFull.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }
}

void MainMenu::initButtons()
{
    float x = this->window->getSize().x * 0.23f;
    float y = this->window->getSize().y * 0.45f;
    float size = this->window->getSize().y * 0.06;
    float space = this->window->getSize().y * 0.15;

    this->buttons["GAME_STATE"] = new Button(x, y, size, size + 5, &this->font, "Mulai", 
        sf::Color(255, 255, 255, 255), sf::Color(255, 246, 18, 255), sf::Color(255, 246, 18, 150));

    this->buttons["TUTORIAL_STATE"] = new Button(x, y + space, size, size + 5, &this->font, "Tutorial", 
        sf::Color(255, 255, 255, 255), sf::Color(255, 246, 18, 255), sf::Color(255, 246, 18, 150));

    this->buttons["EXIT_STATE"] = new Button(x, y + space * 2, size, size + 5, &this->font, "Keluar", 
        sf::Color(255, 255, 255, 255), sf::Color(255, 246, 18, 255), sf::Color(255, 246, 18, 150));
}

void MainMenu::initBackground()
{
    if (!this->backgroundTex.loadFromFile("Resources/Textures/main_menu_bg.jpg"))
    {
        std::cout << "Failed to load main menu background" << std::endl;
    }
    this->background.setTexture(this->backgroundTex);
    this->background.setScale(
		static_cast<float>(this->window->getSize().x) / this->background.getLocalBounds().width,
		static_cast<float>(this->window->getSize().y) / this->background.getLocalBounds().height);
}

// Constructor & Destructor
MainMenu::MainMenu(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
    this->playMenuMusic = true;
    this->initFonts();
    this->initButtons();
    this->initBackground();
}

MainMenu::~MainMenu()
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
void MainMenu::updateButtons()
{
    for (auto& button : this->buttons)
    {
        button.second->update(this->mousePosWindow);
    }

    // GameState button
    if (this->buttons["GAME_STATE"]->isPressed())
    {
        this->states->push(new GameState(this->window, this->states));
    }

    // TutorialState button
    if (this->buttons["TUTORIAL_STATE"]->isPressed())
    {
        this->states->push(new TutorialState(this->window, this->states));
    }

    // Quit the game
    if (this->buttons["EXIT_STATE"]->isPressed())
    {
        this->window->close();
    }
}

void MainMenu::update(const float& dt)
{
    this->updateMousePositions();
    this->updateButtons();
}

void MainMenu::renderBackground()
{
    this->window->draw(this->background);
}

void MainMenu::renderButtons(sf::RenderTarget& target)
{
    for (auto& button : this->buttons)
    {
        button.second->render(target);
    }
}

void MainMenu::render(sf::RenderTarget* target)
{
    if (!target)
    {
        target = this->window;
    }

    this->renderBackground();

    this->renderButtons(*target);
}