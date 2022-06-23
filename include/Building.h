#ifndef BUILDING_H
#define BUILDING_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Building
{
private:
    // Variables
    sf::Sprite shape;
    sf::Texture texture;

    int hp;
    int hpMax;

    // Window
    sf::RenderWindow* window;

    // Private functions
    void initVariables();
    void initTexture();
    void initSprite();

public:
    // Constructor & Destructor
    Building(sf::RenderWindow* window);
    virtual ~Building();

    // Accessor
    const sf::FloatRect getBounds() const;
    const int& getHp() const;
    const int& getHpMax() const;

    // Modifiers
    void setColor(const sf::Color& color);
    void setHp(const int hp);
    void loseHp(const int value);

    // Functions
    void update();
    void render(sf::RenderTarget& target);
};

#endif