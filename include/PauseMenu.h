#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "Button.h"

class PauseMenu
{
private:
    // Variables
	sf::Font font;
    sf::Text pauseText;
	std::map<std::string, Button*> buttons;

    // Background
	sf::RectangleShape background;
	sf::RectangleShape container;

	// Private Functions
    void initFonts(sf::RenderWindow* window);
    void initButtons(sf::RenderWindow* window);
    void initBackground(sf::RenderWindow* window);

public:
    // Constructor & Destructor
	PauseMenu(sf::RenderWindow* window);
	virtual ~PauseMenu();

	// Accessor
	std::map<std::string, Button*>& getButtons();

	// Functions
	const bool isButtonPressed(const std::string key);

	void update(const sf::Vector2i& mousePos);
	void render(sf::RenderTarget& target);
};


#endif // PAUSEMENU_H