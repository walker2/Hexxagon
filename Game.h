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
#include "States/Difficulty_Singleplayer_State.h"
#include "States/Difficulty_Computerwars_State.h"

static Intro_State intro_state;
static Menu_State menu_state;
static Difficulty_Singleplayer_State difficulty_singleplayer_state;
static Difficulty_Computerwars_State difficulty_computerwars_state;
static Multiplayer_State multiplayer_state(GameStates::MULTIPLAYER, 3);
static Multiplayer_State singleplayer_state(GameStates::SINGLEPLAYER, 3);
static Multiplayer_State computer_wars(GameStates::COMPUTERWARS, 3);

class Game
{
public:
    Game();
    ~Game() {};

    void run();

private:
    void initSystems();
    void gameLoop();
    void draw();

private:
    int m_screenWidth;
    int m_screenHeight;
    int m_diff1 = 1;
    int m_diff2 = 1;

    sf::Clock m_clock;
    sf::RenderWindow m_window;

    Game_State* m_state;
    ResourceManager m_resourceManager;
};



#endif
