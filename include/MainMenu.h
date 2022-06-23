#ifndef MAINMENU_H
#define MAINMENU_H

#include "GameState.h"
#include "TutorialState.h"
#include "Button.h"

class MainMenu : public State
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
    MainMenu(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~MainMenu();

    // Functions
    void updateButtons();
    void update(const float& dt);

    void renderBackground();
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);
};



#endif