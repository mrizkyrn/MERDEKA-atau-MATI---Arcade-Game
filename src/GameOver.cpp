#include "GameOver.h"

// Private functions
void GameOver::initFonts()
{
    if (!this->font.loadFromFile("Resources/Fonts/PixellettersFull.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }
}

void GameOver::initText()
{
    float textSize = this->window->getSize().y * 0.05f;
    float y = this->window->getSize().y * 0.1f;

    // Game over text
    this->gameOverText.setFont(this->font);
    this->gameOverText.setString("KAMU GAGAL!");
    this->gameOverText.setCharacterSize(textSize * 3.5f);
    this->gameOverText.setStyle(sf::Text::Bold);
    this->gameOverText.setFillColor(sf::Color::Red);
    this->gameOverText.setOrigin(this->gameOverText.getGlobalBounds().width / 2, this->gameOverText.getGlobalBounds().height / 2);
    this->gameOverText.setPosition(sf::Vector2f(window->getSize().x / 2, y));

    // High score text
    this->highScoreText.setFont(this->font);

    if (this->score == this->highScore)
        this->highScoreText.setString("New High Score!");
    else
        this->highScoreText.setString("Your High Score : " + std::to_string(highScore));

    this->highScoreText.setCharacterSize(textSize);
    this->highScoreText.setFillColor(sf::Color::White);
    this->highScoreText.setOrigin(this->highScoreText.getGlobalBounds().width / 2, this->highScoreText.getGlobalBounds().height / 2);
    this->highScoreText.setPosition(sf::Vector2f(window->getSize().x / 2, y * 2.5f));

    // Score text
    this->scoreText.setFont(this->font);
    this->scoreText.setString(std::to_string(score));
    this->scoreText.setCharacterSize(textSize * 3.5f);
    this->scoreText.setStyle(sf::Text::Bold);
    this->scoreText.setFillColor(sf::Color::White);
    this->scoreText.setOrigin(this->scoreText.getGlobalBounds().width / 2, this->scoreText.getGlobalBounds().height / 2);
    this->scoreText.setPosition(sf::Vector2f(window->getSize().x / 2, y * 5.f));
}

void GameOver::initButtons()
{
    float x = this->window->getSize().x * 0.13f;
    float y = this->window->getSize().y * 0.85f;
    float size = this->window->getSize().y * 0.045;

    this->buttons["MAIN_MENU_STATE"] = new Button(x, y, size, size + 5, &this->font, "Main Menu", 
        sf::Color(255, 255, 255, 255), sf::Color(255, 246, 18, 255), sf::Color(255, 246, 18, 150));

    this->buttons["GAME_STATE"] = new Button(window->getSize().x - x, y, size, size + 5, &this->font, "Ulangi", 
        sf::Color(255, 255, 255, 255), sf::Color(255, 246, 18, 255), sf::Color(255, 246, 18, 150));

    this->buttons["POSTER_STATE"] = new Button(this->window->getSize().x / 2, x / 5, size, size, &this->font, "Poster",
        sf::Color(255, 255, 255, 150), sf::Color(255, 246, 18, 255), sf::Color(255, 246, 18, 150));
}

void GameOver::initBackground()
{
    if (!this->backgroundTex.loadFromFile("Resources/Textures/gameover_bg.jpg"))
    {
        std::cout << "Failed to load TutorialState_background" << std::endl;
    }

    this->background.setTexture(this->backgroundTex);
    this->background.setScale(
        this->window->getSize().x / this->background.getGlobalBounds().width,
        this->window->getSize().y / this->background.getGlobalBounds().height
    );
}

void GameOver::initPoster()
{
    // Poster texture
    if (this->score < 5000)
        this->posterTex.loadFromFile("Resources/Textures/Ahmad Yani.png");
    else if (this->score < 11000 && this->score >= 5000)
        this->posterTex.loadFromFile("Resources/Textures/Nasution.jpg");
    else
        this->posterTex.loadFromFile("Resources/Textures/Soedirman.jpg");

    this->poster.setTexture(this->posterTex);
    this->poster.setScale(
        this->window->getSize().x * 0.35f/ this->poster.getGlobalBounds().width,
        this->window->getSize().y * 0.85f/ this->poster.getGlobalBounds().height
    );
    this->poster.setPosition(sf::Vector2f(
        window->getSize().x / 2 - this->poster.getGlobalBounds().width / 2,
        window->getSize().y / 1.85f - this->poster.getGlobalBounds().height / 2
    ));

    // Poster container
    this->container.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
    this->container.setFillColor(sf::Color(0, 0, 0, 150));
    this->container.setPosition(sf::Vector2f(0, 0));

    // Poster variables
    this->isPosterShown = false;
    this->mouseTimer = 10.f;
}

void GameOver::initHighScore()
{
    std::ifstream inFile;
    inFile.open(".highscore.txt");

    if (inFile.is_open())
    {
        inFile >> this->highScore;
        inFile.close();
    }
    else
    {
        std::cout << "Failed to open highscore.txt" << std::endl;
    }
}

// Constructor & Destructor
GameOver::GameOver(sf::RenderWindow* window, std::stack<State*>* states, unsigned score) : State(window, states)
{
    this->score = score;
    this->initHighScore();
    this->initFonts();
    this->initText();
    this->initButtons();
    this->initBackground();
    this->initPoster();
}

GameOver::~GameOver()
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
void GameOver::updateButtons()
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

    // Game button
    if (this->buttons["GAME_STATE"]->isPressed())
    {
        this->endState();
    }

    // Poster button
    if (this->buttons["POSTER_STATE"]->isPressed() && this->mouseTimer <= 0.f)
    {
        this->isPosterShown = !this->isPosterShown;
        this->mouseTimer = 10.f;
    }
}

void GameOver::update(const float& dt)
{
    // Update mouse timer
    if (this->mouseTimer > 0.f)
        this->mouseTimer -= 0.5f;

    this->updateMousePositions();
    this->updateButtons();
}

void GameOver::renderPoster()
{
    if (this->isPosterShown)
    {
        this->window->draw(this->container);
        this->window->draw(this->poster);
    }
}

void GameOver::renderButtons(sf::RenderTarget& target)
{
    for (auto& button : this->buttons)
    {
        button.second->render(target);
    }
}

void GameOver::render(sf::RenderTarget* target)
{
    if (!target)
    {
        target = this->window;
    }

    // Render background
    this->window->draw(this->background);

    // Render text
    target->draw(this->gameOverText);
    target->draw(this->highScoreText);
    target->draw(this->scoreText);

    // Render poster
    this->renderPoster();

    // Render buttons
    this->renderButtons(*target);
}