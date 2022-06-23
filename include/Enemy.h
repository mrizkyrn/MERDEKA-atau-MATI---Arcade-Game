#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <map>

class Enemy
{
private:
	// Window
	sf::RenderWindow* window;

	sf::Sprite sprite;
	std::map<int, sf::Texture*> textures;

	unsigned textureIndex;
	unsigned pointCount;
	float speed;
	int hp;
	int damage;
	int points;

	// Private functions
	void initVariables();
	void initTextures();
	void initSprite();

public:
	// Constructor & Destructor
	Enemy(sf::RenderWindow* window);
	virtual ~Enemy();

	// Accessors
	const sf::FloatRect getBounds() const;
	const int& getSpeed() const;
	const int& getPoints() const;
	const int& getDamage() const;
	const int& getHp() const;

	// Modifiers
	void setSpeed(const float speed);
	void setHp(const int hp);
	void loseHp(const int value);

	// Functions
	void getShoot();
	void update(const float& dt);
	void render(sf::RenderTarget* target);
};


#endif