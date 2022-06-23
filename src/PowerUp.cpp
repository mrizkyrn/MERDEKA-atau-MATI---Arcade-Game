#include "GameState.h"

// Private functions
void PowerUp::initVariables()
{
    this->next = nullptr;

    this->pos_y = this->window->getSize().y * 0.2f;
}

void PowerUp::initTextures()
{
    this->textures[0] = new sf::Texture();
    this->textures[0]->loadFromFile("Resources/Textures/damageUp.png");

    this->textures[1] = new sf::Texture();
    this->textures[1]->loadFromFile("Resources/Textures/bulletUp.png");

    this->textures[2] = new sf::Texture();
    this->textures[2]->loadFromFile("Resources/Textures/movementUp.png");
}

void PowerUp::initSprite()
{
    this->sprite.setTexture(*this->textures[this->powerUpType]);
    this->sprite.scale(
        this->window->getSize().y * 0.0008f,
        this->window->getSize().y * 0.0008f);
}

// Constructor & Destructor
PowerUp::PowerUp(sf::RenderWindow* window, unsigned int PowerUp_type)
{
    this->window = window;
    this->powerUpType = PowerUp_type;
    this->initVariables();
    this->initTextures();
    this->initSprite();
}

PowerUp::~PowerUp()
{
    for (auto& texture : this->textures)
    {
        delete texture.second;
    }

    this->textures.clear();
}

// Accessors
const sf::FloatRect PowerUp::getBounds() const
{
    return this->sprite.getGlobalBounds();
}

const short unsigned int& PowerUp::getType() const
{
    return this->powerUpType;
}

// Functions
void PowerUp::update(float counter)
{    
    this->sprite.setPosition(this->window->getSize().x * counter, this->window->getSize().y * 0.137f);
}

void PowerUp::render(sf::RenderTarget* target)
{
    target->draw(this->sprite);
}