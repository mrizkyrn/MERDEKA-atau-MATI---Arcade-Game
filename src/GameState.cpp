#include "GameState.h"

// Private functions
void GameState::initSoundEffects()
{
	this->soundBuffers["SHOOT"] = new sf::SoundBuffer();
	this->soundBuffers["SHOOT"]->loadFromFile("Resources/Sound Effects/player_shoot.wav");

	this->playerShoot.setBuffer(*this->soundBuffers["SHOOT"]);
	this->playerShoot.setVolume(25);

	this->soundBuffers["BULLET_HIT"] = new sf::SoundBuffer();
	this->soundBuffers["BULLET_HIT"]->loadFromFile("Resources/Sound Effects/bullet_hit.wav");

	this->bulletHit.setBuffer(*this->soundBuffers["BULLET_HIT"]);
	this->bulletHit.setVolume(50);

	this->soundBuffers["ENEMY_HIT"] = new sf::SoundBuffer();
	this->soundBuffers["ENEMY_HIT"]->loadFromFile("Resources/Sound Effects/enemy_hit.wav");

	this->enemyHit.setBuffer(*this->soundBuffers["ENEMY_HIT"]);
	this->enemyHit.setVolume(100);

	this->soundBuffers["GET_ITEM"] = new sf::SoundBuffer();
	this->soundBuffers["GET_ITEM"]->loadFromFile("Resources/Sound Effects/get_item.wav");

	this->getItem.setBuffer(*this->soundBuffers["GET_ITEM"]);
	this->getItem.setVolume(25);

	this->soundBuffers["UP_POWER"] = new sf::SoundBuffer();
	this->soundBuffers["UP_POWER"]->loadFromFile("Resources/Sound Effects/powerup.wav");

	this->upPower.setBuffer(*this->soundBuffers["UP_POWER"]);
	this->upPower.setVolume(25);
}

void GameState::initGUI()
{
	// Load font
	if (!this->font1.loadFromFile("Resources/Fonts/PixellettersFull.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";

	if (!this->font2.loadFromFile("Resources/Fonts/Mukta-Bold.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";

	float pos = this->window->getSize().y * 0.04f;
	float space = this->window->getSize().y * 0.045f;

	// Init point text
	this->pointText.setFont(this->font1);
	this->pointText.setPosition(window->getSize().x * 0.85f, 20.f);
	this->pointText.setCharacterSize(this->size_y);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("test");

	// Init container
	this->container.setSize(sf::Vector2f(this->size_x * 2.95f, this->window->getSize().y * 0.16f));
	this->container.setPosition(pos / 2.f, pos / 2.f);
	this->container.setFillColor(sf::Color(0, 0, 0, 70));

	// Init player Hp Bar
	this->playerHpBar.setSize(sf::Vector2f(this->size_x * 2.5f, this->size_y * 0.5f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(pos, pos));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

	// Init player health text
	this->playerLifeText.setFont(this->font2);
	this->playerLifeText.setCharacterSize(this->size_y * 0.35f);
	this->playerLifeText.setFillColor(sf::Color::White);
	this->playerLifeText.setString("Player Health");
	this->playerLifeText.setPosition(sf::Vector2f(pos + (pos * 0.08f), pos));

	// Init building Hp Bar
	this->buildingHpBar.setSize(sf::Vector2f(this->size_x * 2.5f, this->size_y * 0.5f));
	this->buildingHpBar.setFillColor(sf::Color::Blue);
	this->buildingHpBar.setPosition(sf::Vector2f(pos, pos + space));

	this->buildingHpBarBack = this->buildingHpBar;
	this->buildingHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

	// Init building health text
	this->buildingLifeText.setFont(this->font2);
	this->buildingLifeText.setCharacterSize(this->size_y * 0.35f);
	this->buildingLifeText.setFillColor(sf::Color::White);
	this->buildingLifeText.setString("Building Health");
	this->buildingLifeText.setPosition(sf::Vector2f(pos + (pos * 0.08f), pos + space));

	// Power Up Gui
	this->damageUpText.setFont(this->font2);
	this->damageUpText.setCharacterSize(this->size_y * 0.5f);
	this->damageUpText.setFillColor(sf::Color::White);
	this->damageUpText.setOutlineThickness(1.f);
	this->damageUpText.setOutlineColor(sf::Color::Black);
	this->damageUpText.setString("Damage Up");
	this->damageUpText.setPosition(sf::Vector2f(pos + (pos * 0.08f), pos * 20));

	this->bulletUpText.setFont(this->font2);
	this->bulletUpText.setCharacterSize(this->size_y * 0.5f);
	this->bulletUpText.setFillColor(sf::Color::White);
	this->bulletUpText.setOutlineThickness(1.f);
	this->bulletUpText.setOutlineColor(sf::Color::Black);
	this->bulletUpText.setString("Bullet Up");
	this->bulletUpText.setPosition(sf::Vector2f(pos + (pos * 0.08f), (pos * 20) - space));

	this->movementUpText.setFont(this->font2);
	this->movementUpText.setCharacterSize(this->size_y * 0.5f);
	this->movementUpText.setFillColor(sf::Color::White);
	this->movementUpText.setOutlineThickness(1.f);
	this->movementUpText.setOutlineColor(sf::Color::Black);
	this->movementUpText.setString("Movement Up");
	this->movementUpText.setPosition(sf::Vector2f(pos + (pos * 0.08f), (pos * 20) - (space * 2)));
}

void GameState::initWorld()
{
	if (!this->worldBackgroundTex.loadFromFile("Resources/Textures/game_bg.jpg"))
	{
		std::cout << "ERROR::GAME::COULD NOT LOAD BACKGROUND TEXTURE" << "\n";
	}

	this->worldBackground.setTexture(this->worldBackgroundTex);
	this->worldBackground.setScale(
		static_cast<float>(this->window->getSize().x) / this->worldBackground.getLocalBounds().width,
		static_cast<float>(this->window->getSize().y) / this->worldBackground.getLocalBounds().height);
}

void GameState::initPauseMenu()
{
	this->pauseMenu = new PauseMenu(this->window);
	this->paused = false;
}

void GameState::initSystems()
{
	this->size_x = static_cast<int>(this->window->getSize().x * 0.05f);
	this->size_y = static_cast<int>(this->window->getSize().y * 0.05f);
	this->score = 0;
	this->finalScore = 0;
	this->highScore = 0;
	this->scoreWin = 17845;
	this->winTimer = 75.f;
}

void GameState::initItems()
{
	this->itemTimerMax = rand() % 200 + 400;
	this->itemTimer = 0;
}

void GameState::initPowerUps()
{
	powerUp1.setRadius(this->size_x * 0.25f);
	powerUp1.setFillColor(sf::Color(25, 25, 25, 200));
	powerUp1.setOrigin(powerUp1.getLocalBounds().width / 2, powerUp1.getLocalBounds().height / 2);
	powerUp1.setPosition(sf::Vector2f(this->window->getSize().x * 0.14f, this->window->getSize().y * 0.15f));

	powerUp2 = powerUp1;
	powerUp2.setPosition(sf::Vector2f(this->window->getSize().x * 0.09f, this->window->getSize().y * 0.15f));

	powerUp3 = powerUp1;
	powerUp3.setPosition(sf::Vector2f(this->window->getSize().x * 0.04f, this->window->getSize().y * 0.15f));

	this->damageUpTimer = 0.f;
	this->bulletUpTimer = 0.f;
	this->movementUpTimer = 0.f;
}

void GameState::initPlayer()
{
	this->player = new Player(this->window);
	this->playerColorChange = false;
}

void GameState::initEnemies()
{
	this->spawnTimerMax = 200.f;
	this->spawnTimer = this->spawnTimerMax;
}

void GameState::initBuilding()
{
	this->building = new Building(this->window);
	this->buildingColorChange = false;
}

// Constructor & Destructor
GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
	this->playGameMusic = true;
	this->initSoundEffects();
	this->initSystems();
	this->initGUI();
	this->initWorld();
	this->initPauseMenu();
	this->initItems();
	this->initPowerUps();
	this->initPlayer();
	this->initEnemies();
	this->initBuilding();
}

GameState::~GameState()
{
	// Delete player
    delete this->player;

	// Delete items
	for (auto item : this->items)
	{
		delete item;
	}

	// Delete power ups
	this->powerUps.clear();

	// Delete bullets
	for (auto *i : this->bullets)
	{
		delete i;
	}

	// Delete enemies
	for (auto *i : this->enemies)
	{
		delete i;
	}

	// Delete building
	delete this->building;

	// Delete pause menu
	delete this->pauseMenu;

	// Delete Sound Buffers
	for (auto &i : this->soundBuffers)
	{
		delete i.second;
	}
}

// Functions
void GameState::restart()
{
	// reset player
	this->score = 0;
	this->player->setHp(100);
	this->player->setPosition(this->window->getSize().x / 2.f, this->window->getSize().y / 2.f);
	this->player->setColor(sf::Color::White);

	// reset enemies
	this->enemies.clear();
	this->spawnTimer = this->spawnTimerMax;

	// reset building
	this->building->setHp(100);
	this->building->setColor(sf::Color::White);

	// reset bullets
	this->bullets.clear();
}

void GameState::saveHighScore()
{
	// Set final score
	this->finalScore = this->score;

	// Load high score
	std::ifstream inFile;
    inFile.open(".highscore.txt");

    if (inFile.is_open())
    {
        inFile >> this->highScore;
        inFile.close();
    }
    else
    {
        std::cout << "Failed to open highscore.txt" << std::endl;
    }

	// Save high score
	if (this->score > this->highScore)
	{
		std::ofstream outfile(".highscore.txt");
		outfile << this->score;
		outfile.close();
	}
}

void GameState::statIncrease(const short unsigned int &type)
{
	switch (type)
	{
	case 0:
		this->damageUpTimer += 100.f;
		this->player->setDamage(3);
		break;
	case 1:
		this->bulletUpTimer += 100.f;
		this->player->setAttackCooldown(5.f);
		break;
	case 2:
		this->movementUpTimer += 100.f;
		this->player->setMovementSpeed(this->window->getSize().x * 0.45f);
		break;

	default:
		break;
	}
}

void GameState::updateInput(const float& dt, const sf::Vector2i& mousePos)
{
	// Move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(dt, 0.f, 1.f);

	// Shoot
	this->aimDir = sf::Vector2f(mousePos.x - this->player->getPos().x, mousePos.y - this->player->getPos().y);
	this->aimDirNorm.x = aimDir.x / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
	this->aimDirNorm.y = aimDir.y / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
		this->playerShoot.play();

		this->bullets.push_back(
			new Bullet(
			this->player->getPos().x,
			this->player->getPos().y, 
			aimDirNorm.x, 
			aimDirNorm.y, 
			this->window->getSize().x * 0.7f
			)
		);
	}

	// Rotate player
	this->player->rotatePlayer(mousePos.x, mousePos.y);

	// Power up
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && this->player->canPower() && !this->powerUps.isEmpty())
	{
		this->upPower.play();

		this->statIncrease(this->powerUps.front()->getType());
		this->powerUps.dequeue();
		this->itemTimer = 0;
	}

	// Pause game
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !this->paused)
	{
		this->paused = true;
	}
}

void GameState::updatePauseMenu()
{
	if (this->pauseMenu->isButtonPressed("RESUME"))
		this->paused = false;
	
	if (this->pauseMenu->isButtonPressed("MAIN_MENU"))
		this->mainMenu = true;

}

void GameState::updateGUI()
{
	std::stringstream ss;
	std::stringstream ss2;
	std::stringstream ss3;

	ss << "Score: " << this->score;
	this->pointText.setString(ss.str());

	ss2 << this->player->getHp() << "/" << this->player->getHpMax();
	this->playerLifeText.setString(ss2.str());

	ss3 << this->building->getHp() << "/" << this->building->getHpMax();
	this->buildingLifeText.setString(ss3.str());

	// Update player GUI
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(this->size_x * 2.5f * hpPercent, this->playerHpBar.getSize().y));

	// Update building GUI
	float buildingHpPercent = static_cast<float>(this->building->getHp()) / this->building->getHpMax();
	this->buildingHpBar.setSize(sf::Vector2f(this->size_x * 2.5f * buildingHpPercent, this->buildingHpBar.getSize().y));

	// Update power up GUI
	std::stringstream ss4;
	ss4 << "Damage Up " << std::setprecision(2) << std::fixed << this->damageUpTimer / 10.f;
	this->damageUpText.setString(ss4.str());

	std::stringstream ss5;
	ss5 << "Bullet Up " << std::setprecision(2) << std::fixed << this->bulletUpTimer / 10.f;
	this->bulletUpText.setString(ss5.str());

	std::stringstream ss6;
	ss6 << "Movement Up " << std::setprecision(2) << std::fixed << this->movementUpTimer / 10.f;
	this->movementUpText.setString(ss6.str());
}

void GameState::updatePlayer()
{
	// Left world collision
	if (this->player->getPos().x < 30)
		this->player->setPosition(30.f, this->player->getPos().y);

	// Right world collison
	else if (this->player->getPos().x > this->window->getSize().x - 30)
		this->player->setPosition(this->window->getSize().x - 30, this->player->getPos().y);

	// Top world collision
	if (this->player->getPos().y < 30)
		this->player->setPosition(this->player->getPos().x, 30.f);

	// Bottom world collision
	else if (this->player->getPos().y > this->window->getSize().y * 0.85f)
		this->player->setPosition(this->player->getPos().x, this->window->getSize().y * 0.85f);

	// Change color
	if (this->playerColorChange)
	{
		playerColorTimer++;

		if (this->playerColorTimer >= 20.f)
		{
			this->player->setColor(sf::Color(255, 255, 255, 255));
			this->playerColorTimer = 0;
			this->playerColorChange = false;
		}
	}
}

void GameState::updateItems()
{
	// Spawn items
	this->itemTimer += 0.5f;
	if (this->itemTimer >= this->itemTimerMax && this->items.size() < 2 && this->powerUps.size() < 3 && this->score < this->scoreWin) 
	{
		this->items.push_front(new Item(rand() % this->window->getSize().x, rand() % static_cast<int>(this->window->getSize().y * 0.80f) + 30));
		this->itemTimer = 0.f;
		this->itemTimerMax = rand() % 200 + 400;
	}

	// Items & player collision
	for (auto *item : this->items)
	{
		if (this->player->getBounds().intersects(item->getBounds()))
		{
			this->getItem.play();

			if (item == this->items.front())
			{
				if (item->getType() == 3)
				{
					player->setHp(player->getHp() + player->getHpMax() * (rand() % 10 + 10)/100);
				}
				else
				{
					this->powerUps.enqueue(new PowerUp(this->window, item->getType()));
				}

				delete items.front();
				this->items.pop_front();
			}
			else
			{
				if (item->getType() == 3)
				{
					player->setHp(player->getHp() + player->getHpMax() * (rand() % 10 + 10)/100);
				}
				else
				{
					this->powerUps.enqueue(new PowerUp(this->window, item->getType()));
				}

				delete items.back();
				this->items.pop_back();
			}

			if (this->player->getHp() > this->player->getHpMax())
			{
				this->player->setHp(this->player->getHpMax());
			}
		}
	}
}

void GameState::updatePowerUps()
{
	if (this->damageUpTimer > 0)
		this->damageUpTimer -= 0.1f;
	else
		this->player->setDamage(1);
	
	if (this->bulletUpTimer > 0)
		this->bulletUpTimer -= 0.1f;
	else
		this->player->setAttackCooldown(10.f);

	if (this->movementUpTimer > 0)
		this->movementUpTimer -= 0.1f;
	else
		this->player->setMovementSpeed(this->window->getSize().x * 0.25f);
}

void GameState::updateBuilding()
{
	// Change color
	if (this->buildingColorChange)
	{
		buildingColorTimer++;

		if (this->buildingColorTimer >= 20.f)
		{
			this->building->setColor(sf::Color(255, 255, 255, 255));
			this->buildingColorTimer = 0;
			this->buildingColorChange = false;
		}
	}
}

void GameState::updateBullets(const float& dt)
{
	unsigned counter = 0;
	for (auto *bullet : this->bullets)
	{
		bullet->update(dt);

		// Bullet culling
		if (bullet->getPos().x < 0 || bullet->getPos().x > this->window->getSize().x || 
			bullet->getPos().y < 0 || bullet->getPos().y > this->window->getSize().y)
		{
			delete bullets[counter];
			this->bullets.erase(this->bullets.begin() + counter);
		}
		counter++;
	}
}

void GameState::updateEnemies(const float& dt)
{
	// Set spawn timer based on score
	if (this->score < 5000)
	{
		this->spawnTimerMax = 150.f - ((this->score + 1) / 10.f);
		if (this->spawnTimerMax < 35.f)
			this->spawnTimerMax = 35.f;
	}
	else if (this->score >= 5000 && this->score < 10000)
	{
		this->spawnTimerMax = 32.f;
	}
	else
	{
		this->spawnTimerMax = 29.f;
	}

	// Spawning
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax && this->score < this->scoreWin)
	{
		this->enemies.push_back(new Enemy(this->window));
		this->spawnTimer = 0.f;
	}

	// Update
	unsigned counter = 0;
	for (auto *enemy : this->enemies)
	{
		enemy->update(dt);

		// Enemy culling
		if (enemy->getBounds().top > this->window->getSize().y)
		{
			// Delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}
		// Enemy player collision
		else if(enemy->getBounds().intersects(this->player->getBounds()))
		{
			this->enemyHit.play();

			this->player->setColor(sf::Color(255, 0, 0, 255));
			this->playerColorChange = true;

			this->player->loseHp(this->enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}

		counter++;
	}
}

void GameState::updateCombat(const float& dt)
{
	// Bullet & enemy collision
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && !enemy_deleted; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				this->bulletHit.play();

				this->score += this->enemies[i]->getPoints();
				this->enemies[i]->loseHp(this->player->getDamage());

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				this->enemies[i]->getShoot();

				if (this->enemies[i]->getHp() <= 0)
				{
					delete this->enemies[i];
					this->enemies.erase(this->enemies.begin() + i);

					enemy_deleted = true;
				}
			}

		}
	}

	// Enemy & building collision
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		if (this->enemies[i]->getBounds().top > this->building->getBounds().top)
		{
			// Change color
			this->building->setColor(sf::Color(240, 161, 161, 255));
			this->buildingColorChange = true;

			this->building->loseHp(this->enemies[i]->getDamage());

			delete this->enemies[i];
			this->enemies.erase(this->enemies.begin() + i);
		}
	}
}

void GameState::update(const float& dt)
{
	if (this->player->getHp() <= 0 || this->building->getHp() <= 0)
	{
		this->gameOver();
	}
	else
	{
		if (this->score >= this->scoreWin)
		{
			this->gameWon();
		}

		this->updateMousePositions();

		if (!this->paused)
		{
			this->updateInput(dt, this->mousePosWindow);
			this->player->update();
			this->updatePlayer();
			this->updateItems();
			this->updatePowerUps();
			this->powerUps.updateAll();
			this->updateBuilding();
			this->updateBullets(dt);
			this->updateEnemies(dt);
			this->updateCombat(dt);
			this->updateGUI();
		}
		else
		{
			this->pauseMenu->update(this->mousePosWindow);
			this->updatePauseMenu();
		}
	}
}

void GameState::gameOver()
{
	this->saveHighScore();
	this->restart();
	this->states->push(new GameOver(this->window, this->states, this->finalScore));
}

void GameState::gameWon()
{
	if (this->score > this->scoreWin)
	{
		this->score = this->scoreWin;
		this->finalScore = this->score;
	}
	
	this->winTimer -= 0.1f;

	if (this->winTimer <= 0.f)
	{
		this->saveHighScore();
		this->states->push(new GameWin(this->window, this->states));
	}
}

void GameState::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->container);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
	this->window->draw(this->buildingHpBarBack);
	this->window->draw(this->buildingHpBar);
	this->window->draw(this->playerLifeText);
	this->window->draw(this->buildingLifeText);
	this->window->draw(this->powerUp1);
	this->window->draw(this->powerUp2);
	this->window->draw(this->powerUp3);

	this->powerUps.renderAll(this->window);
	if (this->damageUpTimer > 0.f)
	{
		this->window->draw(this->damageUpText);
	}

	if (this->bulletUpTimer > 0.f)
	{
		this->window->draw(this->bulletUpText);
	}

	if (this->movementUpTimer > 0.f)
	{
		this->window->draw(this->movementUpText);
	}
}

void GameState::renderWorld()
{
	this->window->draw(this->worldBackground);
}

void GameState::render(sf::RenderTarget* target)
{
    // Draw world
	this->renderWorld();

	// Draw all the stuffs
	for (auto *item : this->items)
	{
		item->render(this->window);
	}

	for (auto *bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	this->player->render(*this->window);

	for (auto *enemy : this->enemies)
	{
		enemy->render(this->window);
	}

	this->building->render(*this->window);

	this->renderGUI();

	// Pause
	if (this->paused)
	{
		this->pauseMenu->render(*this->window);
	}
}