#ifndef INTROSTATE_H
#define INTROSTATE_H

#include "MainMenu.h"

class IntroState : public State
{
private:
    // Variables
    sf::Font font;
    std::map<std::string, Button*> buttons;


    // Background
    sf::Texture backgroundTex;
    sf::Sprite background;

    sf::RectangleShape fadeBackground;
    int alpha;

    // Private functions
    void initFonts();
    void initButtons();
    void initBackground();

public:
    // Constructor & Destructor
    IntroState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~IntroState();

    // Functions
    void updateFadeBackground();
    void updateButtons();
    void update(const float& dt);

    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);
};


#endif