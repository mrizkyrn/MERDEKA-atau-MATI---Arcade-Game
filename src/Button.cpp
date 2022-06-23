#include "Button.h"

// Constructor & Destructor
Button::Button(float x, float y, unsigned text_size, unsigned text_size_hover, sf::Font* font, std::string text,
    sf::Color idleColor, sf::Color hoverColor, sf::Color pressedColor)
{
 	this->buttonState = BTN_IDLE;

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(idleColor);
	this->text.setCharacterSize(text_size);
    this->text.setStyle(sf::Text::Bold);
    this->text.setOrigin(this->text.getGlobalBounds().width / 2.f, this->text.getGlobalBounds().height / 2.f);
    this->text.setPosition(x, y);

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->pressedColor = pressedColor;

    this->textSize = text_size;
    this->textSizeHover = text_size_hover;
}

Button::~Button()
{
    
}

// Accessor
const bool Button::isPressed() const
{
    return this->buttonState == BTN_PRESSED;
}

// Functions
void Button::update(const sf::Vector2i& mousePosWindow)
{
    // hover
    if (this->text.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosWindow)))
    {
        this->buttonState = BTN_HOVER;

        // pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->buttonState = BTN_PRESSED;
        }
    }
    // idle
    else
    {
        this->buttonState = BTN_IDLE;
    }

    // change color and text size
    switch (this->buttonState)
    {
    case BTN_IDLE:
        this->text.setFillColor(this->idleColor);
        this->text.setCharacterSize(this->textSize);
        break;
    case BTN_HOVER:
        this->text.setFillColor(this->hoverColor);
        this->text.setCharacterSize(this->textSizeHover);
        break;
    case BTN_PRESSED:
        this->text.setFillColor(this->pressedColor);
        this->text.setCharacterSize(this->textSize);
        break;

    default:
        break;
    }
}

void Button::render(sf::RenderTarget& target)
{
    target.draw(this->text);
}