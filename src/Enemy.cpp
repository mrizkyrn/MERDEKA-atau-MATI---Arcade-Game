#include "Enemy.h"

// Private functions
void Enemy::initVariables()
{
	this->textureIndex = rand() % 3 + 1; // Random between 1 and 3
	this->pointCount = rand() % 8 + 3; // 3 to 10 points
	this->speed		= static_cast<float>(this->pointCount / 2.f) * this->window->getSize().y * 0.065f;
	this->hp		= this->textureIndex;
	this->damage	= this->pointCount;
	this->points	= this->pointCount * 1.5;
}

void Enemy::initTextures()
{
	this->textures[1] = new sf::Texture();
	this->textures[1]->loadFromFile("Resources/Textures/inggris.png");

	this->textures[2] = new sf::Texture();
	this->textures[2]->loadFromFile("Resources/Textures/jepang.png");

	this->textures[3] = new sf::Texture();
	this->textures[3]->loadFromFile("Resources/Textures/belanda.png");
}

void Enemy::initSprite()
{
	this->sprite.setTexture(*this->textures[this->textureIndex]);
	this->sprite.setScale(
		this->window->getSize().y * 0.0005f,
		this->window->getSize().y * 0.0005f);
	this->sprite.setOrigin(this->sprite.getGlobalBounds().width/2, this->sprite.getGlobalBounds().height / 2.f);
	this->sprite.setPosition(rand() % (this->window->getSize().x - 100) + 50.f, -100.f);
	this->sprite.rotate(180.f);
}

// Constructor & Destructor
Enemy::Enemy(sf::RenderWindow* window)
{
	this->window = window;
	this->initVariables();
	this->initTextures();
	this->initSprite();
}

Enemy::~Enemy()
{
	for (auto it = this->textures.begin(); it != this->textures.end(); it++)
	{
		delete it->second;
	}

	this->textures.clear();
}

// Accessors
const sf::FloatRect Enemy::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return this->points;
}

const int& Enemy::getDamage() const
{
	return this->damage;
}

const int& Enemy::getHp() const
{
	return this->hp;
}

// Modifiers
void Enemy::setHp(const int hp)
{
	this->hp = hp;
}

void Enemy::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
	{
		this->hp = 0;
	}
}

// Functions
void Enemy::getShoot()
{
	// Change color
	this->sprite.setColor(sf::Color(242, 141, 141, 255));

	// Reduce speed
	this->speed -= this->speed * 0.1f;
	if (this->speed < 50.f)
	{
		this->speed = 50.f;
	}
}

void Enemy::update(const float& dt)
{
	this->sprite.move(0.f, this->speed * dt);
}

void Enemy::render(sf::RenderTarget * target)
{
	target->draw(this->sprite);
}