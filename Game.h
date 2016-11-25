#ifndef HEXXAGON_GAME_H
#define HEXXAGON_GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Board.h"
#include "States/Game_State.h"
#include "States/Intro_State.h"
#include "States/Menu_State.h"
#include "States/Multiplayer_State.h"
#include "ResourceManager.h"



static Intro_State intro_state;
static Menu_State menu_state;
static Multiplayer_State multiplayer_state(false);
static Multiplayer_State singleplayer_state(true);

class Game
{
public:
    Game();
    ~Game() {};

    void run();

private:
    void initSystems();
    void processInput();
    void gameLoop();
    void draw();

private:
    int m_screenWidth;
    int m_screenHeight;

    sf::Clock m_clock;
    sf::RenderWindow m_window;

    Game_State* m_state;
    ResourceManager m_resourceManager;
    std::vector<Game_State*> m_gameStates;
};



#endif
