#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <list>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include "State.h"
#include "GameOver.h"
#include "GameWin.h"
#include "PauseMenu.h"
#include "Queue.h"
#include "Item.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Building.h"

class GameState : public State
{
private:
	// Sound effects
	std::map<std::string, sf::SoundBuffer*> soundBuffers;
	sf::Sound playerShoot;
	sf::Sound bulletHit;
	sf::Sound enemyHit;
	sf::Sound getItem;
	sf::Sound upPower;

	// World
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;

	// Pause
	PauseMenu* pauseMenu;

	// Systems
	float size_x;
	float size_y;
	unsigned score;
	unsigned finalScore;
	unsigned highScore;
	unsigned scoreWin;
	float winTimer;

	// GUI
	sf::Font font1;
	sf::Font font2;
	sf::Text pointText;
	sf::RectangleShape container;

	// PlayerGUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;
	sf::Text playerLifeText;

	// Building Gui
	sf::RectangleShape buildingHpBar;
	sf::RectangleShape buildingHpBarBack;
	sf::Text buildingLifeText;

	// Power Up Gui
	sf::Text damageUpText;
	sf::Text bulletUpText;
	sf::Text movementUpText;

	// Items
	std::list<Item*> items;
	float itemTimer;
	float itemTimerMax;

	// Power Ups
	Queue powerUps;
	sf::CircleShape powerUp1;
	sf::CircleShape powerUp2;
	sf::CircleShape powerUp3;
	float damageUpTimer;
	float bulletUpTimer;
	float movementUpTimer;

	// Player
	Player* player;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
	bool playerColorChange;
	float playerColorTimer;

	// Bullet
	std::vector<Bullet*> bullets;

	// Enemies
	std::vector<Enemy*> enemies;
	float spawnTimer;
	float spawnTimerMax;

	// Building
	Building* building;
	bool buildingColorChange;
	float buildingColorTimer;

    // Private functions
	void initSoundEffects();
	void initGUI();
	void initWorld();
	void initPauseMenu();
	void initSystems();
	void initItems();
	void initPowerUps();
	void initPlayer();
	void initEnemies();
	void initBuilding();

public:
	// Constructor & Destructor
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameState();

	// Functions
	void restart();
	void saveHighScore();
	void statIncrease(const short unsigned int &type);
	void updatePauseMenu();
	void updateInput(const float& dt, const sf::Vector2i& mousePos);
	void updateGUI();
	void updatePlayer();
	void updateItems();
	void updatePowerUps();
	void updateBuilding();
	void updateBullets(const float& dt);
	void updateEnemies(const float& dt);
	void updateCombat(const float& dt);
    void update(const float& dt);
	void gameOver();
	void gameWon();

    void renderGUI();
	void renderWorld();
    void render(sf::RenderTarget* target = nullptr);
};



#endif