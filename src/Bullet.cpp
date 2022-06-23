#include "Bullet.h"

// Constructor & Destructor
Bullet::Bullet()
{

}

Bullet::Bullet(float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	// texture
	if (!this->texture.loadFromFile("Resources/Textures/circleBullet.png"))
	{
		std::cout << "Error loading bullet texture!" << std::endl;
	}

	this->shape.setTexture(this->texture);
	this->shape.setScale(0.01f, 0.01f);

	this->shape.setPosition(pos_x, pos_y);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;
}

Bullet::~Bullet()
{
	
}

// Accessor
const sf::FloatRect Bullet::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const sf::Vector2f Bullet::getPos() const
{
	return this->shape.getPosition();
}

// Functions
void Bullet::update(const float& dt)
{
	// Movement
	this->shape.move(this->movementSpeed * this->direction * dt);
}

void Bullet::render(sf::RenderTarget * target)
{
	target->draw(this->shape);
}