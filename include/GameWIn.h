#ifndef GAMEWIN_H
#define GAMEWIN_H

#include "Button.h"

class GameWin : public State
{
private:
    // Variables
    sf::Font font;

    std::map<std::string, Button*> buttons;

    // Background
    sf::Texture backgroundTex;
    sf::Sprite background;

    // Credit
    sf::Texture creditTex;
    sf::Sprite credit;
    sf::RectangleShape container;
    bool iscreditShown;
    float mouseTimer;

    // Private functions
    void initFonts();
    void initButtons();
    void initBackground();
    void initCredit();

public:
    // Constructor & Destructor
    GameWin(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameWin();


    // Functions
    void updateButtons();
    void update(const float& dt);

    void renderCredit();
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);
};



#endif