#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>
#include <map>

class Item
{
private:
    sf::Sprite sprite;
    std::map<int, sf::Texture*> textures;

    short unsigned int itemType;

    // Private functions
    void initVariables();
    void initTextures();
    void initSprite();

public:
    // Constructor & Destructor
    Item(float pos_x, float pos_y);
    ~Item();

    // Accessors
    const sf::FloatRect getBounds() const;
    const short unsigned int& getType() const;

    // Functions
    void update(const float& dt);
    void render(sf::RenderTarget* target);
};


#endif