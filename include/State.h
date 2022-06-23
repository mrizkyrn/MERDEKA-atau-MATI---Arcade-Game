#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Stack>
#include <iostream>

class State
{
protected:
    std::stack<State*>* states;
    sf::RenderWindow* window;

    bool quit;
    bool mainMenu;
    bool paused;
    bool playMenuMusic;
    bool playGameMusic;  
    
    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;

public:
    // Constructor & Destructor
    State(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~State();

    // Accessor
    const bool& getQuit() const;
    const bool& getMainMenu() const;
    const bool& getPaused() const;
    const bool& getMenuMusic() const;
    const bool& getGameMusic() const;
    
    // Functions
    void endState();
    virtual void updateMousePositions();
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};


#endif