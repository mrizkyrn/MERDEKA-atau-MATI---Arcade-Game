#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include "State.h"

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED};

class Button
{
private:
    short unsigned int buttonState;

    sf::Font* font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color pressedColor;

    unsigned textSize;
    unsigned textSizeHover;

public:
    // Constructor & Destructor
    Button(float x, float y, unsigned text_size, unsigned text_size_hover, sf::Font* font, std::string text, 
        sf::Color idleColor, sf::Color hoverColor, sf::Color pressedColor);
    ~Button();

    // Accessors
    const bool isPressed() const;

    // Functions
    void update(const sf::Vector2i& mousePosWindow);
    void render(sf::RenderTarget& target);
};



#endif