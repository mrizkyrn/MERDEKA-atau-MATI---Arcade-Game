#ifndef GAME_H
#define GAME_H

#include "IntroState.h"

class Game
{
private:
	// Window
	sf::RenderWindow* window;
	sf::VideoMode windowBounds;

	// Game musics
	sf::Music menu_music;
	sf::Music game_music;

	// Delta time
	sf::Clock deltaClock;
	float dt;

	// States
	std::stack<State*> states;

	// Private functions
	void initWindow();
	void initStates();


public:
	// Constructor & Destructor
	Game();
	virtual ~Game();

	// Functions
	void run();

	void updatePollEvents();
	void updateDeltaTime();
	void update();

	void render();
};



#endif