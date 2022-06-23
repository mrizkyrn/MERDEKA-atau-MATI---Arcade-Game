#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
private:
	sf::RenderWindow* window;

	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;

	float attackCooldown;
	float attackCooldownMax;
	float powerCooldown;

	int damage;

	int hp;
	int hpMax;

	// Private functions
	void initVariables();
	void initTexture();
	void initSprite();

public:
	// Constructor & Destructor
	Player(sf::RenderWindow* window);
	virtual ~Player();

	// Accessors
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getHpMax() const;
	const int& getDamage() const;
	const float& getMovementSpeed() const;

	// Modifiers
	void setColor(const sf::Color& color);
	void setPosition(const float x, const float y);
	void setHp(const int hp);
	void loseHp(const int value);
	void setDamage(const int damage);
	void setMovementSpeed(const float movementSpeed);
	void setAttackCooldown(const float attackCooldown);

	// Functions
	void move(const float& dt, const float dirX, const float dirY);
	void rotatePlayer(const float mouseX, const float mouseY);
	const bool canAttack();
	const bool canPower();

	void update();
	void render(sf::RenderTarget& target);
};


#endif