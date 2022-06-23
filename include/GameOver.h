#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "Button.h"

class GameOver : public State
{
private:
    // Variables
    sf::Font font;
    sf::Text gameOverText;
    sf::Text highScoreText;
    sf::Text scoreText;

    unsigned int score;
    unsigned int highScore;

    std::map<std::string, Button*> buttons;

    // Background
    sf::Texture backgroundTex;
    sf::Sprite background;

    // Poster
    sf::Texture posterTex;
    sf::Sprite poster;
    sf::RectangleShape container;
    bool isPosterShown;
    float mouseTimer;

    // Private functions
    void initFonts();
    void initText();
    void initButtons();
    void initBackground();
    void initPoster();
    void initHighScore();

public:
    // Constructor & Destructor
    GameOver(sf::RenderWindow* window, std::stack<State*>* states, unsigned score);
    virtual ~GameOver();


    // Functions
    void updateButtons();
    void update(const float& dt);

    void renderPoster();
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);
};


#endif