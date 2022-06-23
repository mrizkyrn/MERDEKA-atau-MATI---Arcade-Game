#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet
{
private:
	sf::Sprite shape;
	sf::Texture texture;

	sf::Vector2f direction;
	float movementSpeed;

public:
	// Constructor & Destructor
	Bullet();
	Bullet(float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed);
	virtual ~Bullet();

	// Accessors
	const sf::FloatRect getBounds() const;
	const sf::Vector2f getPos() const;
	
	// Functions
	void update(const float& dt);
	void render(sf::RenderTarget* target);
};


#endif