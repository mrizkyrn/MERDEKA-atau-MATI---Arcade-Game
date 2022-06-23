#include "Player.h"

// Private functions
void Player::initVariables()
{
	this->movementSpeed = this->window->getSize().x * 0.25f;
	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;
	this->powerCooldown = 10.f;

	this->damage = 1;

	this->hpMax = 100;
	this->hp = this->hpMax;
}

void Player::initTexture()
{
	if (!this->texture.loadFromFile("Resources/Textures/player.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void Player::initSprite()
{
	// Set the texture to the sprite
	this->sprite.setTexture(this->texture);

	// Set scale base on window size
	this->sprite.setScale(
		this->window->getSize().y * 0.001f,
		this->window->getSize().y * 0.001f);

	// Set the origin to the center of the gun
	this->sprite.setOrigin((this->sprite.getLocalBounds().width / 2.f) + 13.f, (this->sprite.getLocalBounds().height / 2.f) - 10.f);

	// Set the position of the sprite
	this->sprite.setPosition(this->window->getSize().x / 2.f, this->window->getSize().y / 2.f);
}

// Constructor & Destructor
Player::Player(sf::RenderWindow* window)
{
	this->window = window;
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{
	
}

// Accessors
const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

const int& Player::getDamage() const
{
	return this->damage;
}

const float& Player::getMovementSpeed() const
{
	return this->movementSpeed;
}

// Modifiers
void Player::setColor(const sf::Color & color)
{
	this->sprite.setColor(color);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
	{
		this->hp = 0;
	}
}

void Player::setDamage(const int damage)
{
	this->damage = damage;
}

void Player::setMovementSpeed(const float movementSpeed)
{
	this->movementSpeed = movementSpeed;
}

void Player::setAttackCooldown(const float attackCooldown)
{
	this->attackCooldownMax = attackCooldown;
}

// Functions
void Player::move(const float& dt, const float dirX, const float dirY)
{
	this->sprite.move(dirX * this->movementSpeed * dt, dirY * this->movementSpeed * dt);
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}

	return false;
}

const bool Player::canPower()
{
	if (this->powerCooldown >= 10.f)
	{
		this->powerCooldown = 0.f;
		return true;
	}

	return false;
}

void Player::rotatePlayer(const float mouseX, const float mouseY)
{
	sf::Vector2f direction;
	direction.x = this->sprite.getPosition().x - mouseX;
	direction.y = this->sprite.getPosition().y - mouseY;
	float angle = atan2(direction.y, direction.x) * 180 / 3.14;

	this->sprite.setRotation(angle - 90);
}

void Player::update()
{
	// Update the attack cooldown
	if(this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.5f;
	}

	// Update the power cooldown
	if (this->powerCooldown < 10.f)
	{
		this->powerCooldown += 0.5f;
	}
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}