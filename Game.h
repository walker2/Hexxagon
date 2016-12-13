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
/**
 * Class that initializes all the systems of engine and draws and runs game loop for all interface classes
 */
class Game
{
public:
    Game();
    ~Game() {};

    /**
     * Runs the game, calls initSystems and gameLoop
     */
    void run();
private:
    /**
     * Function creates the game window, sets intro state and initializes it
     */
    void initSystems();
    /**
     * While window is open this function processes input, updates and switches states
     */
    void gameLoop();
    /**
     * Clear the screen and execute the current states draw function
     */
    void draw();

private:
    int m_screenWidth;  ///< Width of the screen
    int m_screenHeight; ///< Height of the screen
    int m_diff1 = 1; ///< Difficulty for the first computer player
    int m_diff2 = 1; ///< SDifficulty for the second computer player

    sf::Clock m_clock;
    sf::RenderWindow m_window;

    Game_State* m_state; ///< Pointer to interface class
    ResourceManager m_resourceManager; ///< Object of ResourceManager class for loading and caching textures and fonts
};



#endif
