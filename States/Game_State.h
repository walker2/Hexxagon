#ifndef HEXXAGON_BASE_STATE_H
#define HEXXAGON_BASE_STATE_H

#include "SFML/Graphics.hpp"
#include "GameStates.h"

class Game_State
{
public:
    virtual void init(int screenWidth, int screenHeight) = 0;
    virtual void processInput(sf::RenderWindow &window) = 0;
    virtual void update(const sf::Time& time) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
    virtual GameStates shouldSwitch() = 0;
    virtual void next() = 0;
};


#endif //HEXXAGON_BASE_STATE_H
