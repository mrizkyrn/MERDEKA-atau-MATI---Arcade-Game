#ifndef TUTORIALSTATE_H
#define TUTORIALSTATE_H

#include "Button.h"

class TutorialState : public State
{
private:
    // Variables
    sf::Font font;
    std::map<std::string, Button*> buttons;

    // Background
    sf::Texture backgroundTex;
    sf::Sprite background;

    // Private functions
    void initFonts();
    void initButtons();
    void initBackground();

public:
    // Constructor & Destructor
    TutorialState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~TutorialState();

    // Functions
    void updateButtons();
    void update(const float& dt);

    void renderBackground();
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);
};


#endif