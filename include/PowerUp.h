#ifndef POWERUP_H
#define POWERUP_H

#include <SFML/Graphics.hpp>
#include <map>


class PowerUp
{
private:
    sf::RenderWindow* window;

    sf::Sprite sprite;
    std::map<int, sf::Texture*> textures;

    short unsigned int powerUpType;

    float pos_y;

    // Private functions
    void initVariables();
    void initTextures();
    void initSprite();

public:
    // Public variable
    PowerUp* next;

    // Constructor & Destructor
    PowerUp(sf::RenderWindow* window, unsigned int PowerUp_type);
    ~PowerUp();

    // Accessors
    const sf::FloatRect getBounds() const;
    const short unsigned int& getType() const;

    // Functions
    void update(float counter);
    void render(sf::RenderTarget* target);
};



#endif