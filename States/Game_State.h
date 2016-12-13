#ifndef HEXXAGON_BASE_STATE_H
#define HEXXAGON_BASE_STATE_H

#include "SFML/Graphics.hpp"
#include "GameStates.h"
#include "../ResourceManager.h"
/**
 * Interface for all states
 */
class Game_State
{
public:
    /**
     * Function that inits the current game state
     * @param screenWidth Width of the screen
     * @param screenHeight Height of the screen
     * @param resourceManager ResourceManager object pointer for handling loading and caching textures and fonts
     * @param diff1 Difficulty of the first computer player
     * @param diff2 Difficulty of the second computer player
     */
    virtual void init(int screenWidth, int screenHeight, ResourceManager* resourceManager, int* diff1, int* diff2) = 0;
    /**
     * Function that processes input from the player
     * @param window Window to get input from
     */
    virtual void processInput(sf::RenderWindow &window) = 0;
    /**
     * Function that updates objects in state based on time
     * @param time Delta time
     */
    virtual void update(const sf::Time& time) = 0;
    /**
     * Function for rendering to the screen
     * @param window Window to render
     */
    virtual void draw(sf::RenderWindow &window) = 0;
    /**
     * Function that checks if should switch
     * @return Game State we should switch
     */
    virtual GameStates shouldSwitch() = 0;
    /**
     * Function for setting up for the next state
     */
    virtual void next() = 0;
};


#endif //HEXXAGON_BASE_STATE_H
