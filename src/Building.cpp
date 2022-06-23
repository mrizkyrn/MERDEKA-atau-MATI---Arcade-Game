#include "../include/Building.h"

// Private functions
void Building::initVariables()
{
    this->hpMax = 100;
    this->hp = this->hpMax;
}

void Building::initTexture()
{
    if (!this->texture.loadFromFile("Resources/Textures/building.png"))
    {
        std::cout << "ERROR::BUILDING::INITTEXTURE::Could not load texture file." << std::endl;
    }
}

void Building::initSprite()
{
    this->shape.setTexture(this->texture);
    this->shape.setPosition(0.f, window->getSize().y * 0.85f);
    this->shape.setScale(
        this->window->getSize().x / this->shape.getLocalBounds().width, 
        this->window->getSize().y * 0.20f/ this->shape.getLocalBounds().height);
}

// Constructor & Destructor
Building::Building(sf::RenderWindow* window)
{
    this->window = window;
    this->initVariables();
    this->initTexture();
    this->initSprite();
}

Building::~Building()
{
    
}

// Accessor
const sf::FloatRect Building::getBounds() const
{
    return this->shape.getGlobalBounds();
}

const int& Building::getHp() const
{
    return this->hp;
}

const int& Building::getHpMax() const
{
    return this->hpMax;
}

// Modifiers
void Building::setColor(const sf::Color& color)
{
    this->shape.setColor(color);
}

void Building::setHp(const int hp)
{
    this->hp = hp;
}

void Building::loseHp(const int value)
{
    this->hp -= value;
    if (this->hp < 0)
    {
        this->hp = 0;
    }
}

// Functions
void Building::update()
{

}

void Building::render(sf::RenderTarget& target)
{
    target.draw(this->shape);
}