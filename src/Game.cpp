#include "Game.h"

// Private functions
void Game::initWindow()
{
	std::string title = "MERDEKA atau MATI! - Arcade Game";
	this->windowBounds = sf::VideoMode::getDesktopMode();
	this->window = new sf::RenderWindow(this->windowBounds, title, sf::Style::Fullscreen);

	// windowBounds.width = 800;
	// windowBounds.height = 480;
	// this->window = new sf::RenderWindow(this->windowBounds, title, sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(90);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initStates()
{
	this->states.push(new IntroState(this->window, &this->states));
}

// Constructor & Destructor
Game::Game()
{
	// music
	if (!this->menu_music.openFromFile("Resources/Musics/mainmenu_music.wav"))
	{
		std::cout << "Failed to load music" << std::endl;
	}
	this->menu_music.setLoop(true);

	if (!this->game_music.openFromFile("Resources/Musics/game_music.wav"))
	{
		std::cout << "Failed to load music" << std::endl;
	}
	this->game_music.setLoop(true);
	this->game_music.setVolume(20.0f);

	this->dt = 0;
	this->initWindow();
	this->initStates();
}

Game::~Game()
{
	// Delete window
	delete this->window;

	// Delete states
	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

// Functions
void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDeltaTime();
		this->update();
		this->render();
	}
}

void Game::updatePollEvents()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::updateDeltaTime()
{
	this->dt = this->deltaClock.restart().asSeconds();
}

void Game::update()
{
	this->updatePollEvents();
	
	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit())
		{
			delete this->states.top();
			this->states.pop();
		}

		// back to main menu
		if (this->states.top()->getMainMenu())
		{
			while (this->states.size() > 2)
			{
				delete this->states.top();
				this->states.pop();
			}
		}

		// music
		if (this->states.top()->getMenuMusic() && !this->menu_music.getStatus())
			this->menu_music.play();
		else if (!this->states.top()->getMenuMusic() && this->menu_music.getStatus())
			this->menu_music.stop();

		if (this->states.top()->getGameMusic() && !this->game_music.getStatus())
			this->game_music.play();
		else if (!this->states.top()->getGameMusic() && this->game_music.getStatus())
			this->game_music.stop();

		if (this->states.top()->getPaused())
			this->game_music.setVolume(5.f);
		else
			this->game_music.setVolume(25.0f);
	}

	// Application is closed
	else
	{
		this->window->close();
	}
}

void Game::render()
{
	this->window->clear();

	if (!this->states.empty())
	{
		this->states.top()->render();
	}

	this->window->display();
}