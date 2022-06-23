#include "Item.h"

// Private functions
void Item::initVariables()
{
    this->itemType = rand() % 4;
}

void Item::initTextures()
{
    this->textures[0] = new sf::Texture();
    this->textures[0]->loadFromFile("Resources/Textures/damageUp.png");

    this->textures[1] = new sf::Texture();
    this->textures[1]->loadFromFile("Resources/Textures/bulletUp.png");

    this->textures[2] = new sf::Texture();
    this->textures[2]->loadFromFile("Resources/Textures/movementUp.png");

    this->textures[3] = new sf::Texture();
    this->textures[3]->loadFromFile("Resources/Textures/health.png");
}

void Item::initSprite()
{
    this->sprite.setTexture(*this->textures[this->itemType]);
    this->sprite.scale(1.f, 1.f);
}

// Constructor & Destructor
Item::Item(float pos_x, float pos_y)
{
    this->initVariables();
    this->initTextures();
    this->initSprite();

    this->sprite.setPosition(pos_x, pos_y);
}

Item::~Item()
{
    for (auto& texture : this->textures)
    {
        delete texture.second;
    }

    this->textures.clear();
}

// Accessors
const sf::FloatRect Item::getBounds() const
{
    return this->sprite.getGlobalBounds();
}

const short unsigned int& Item::getType() const
{
    return this->itemType;
}

// Functions
void Item::update(const float& dt)
{
    
}

void Item::render(sf::RenderTarget* target)
{
    target->draw(this->sprite);
}