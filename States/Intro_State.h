
#ifndef HEXXAGON_INTRO_STATE_H
#define HEXXAGON_INTRO_STATE_H

#include "Game_State.h"
#include "GameStates.h"
#include "../ResourceManager.h"

/**
 * Class for showing intro, switches to Menu_State
 */
class Intro_State : public Game_State
{
public:
    Intro_State() {};
    ~Intro_State();

    void init(int screenWidth, int screenHeight, ResourceManager* resourceManager, int* diff1, int* diff2) override;
    void processInput(sf::RenderWindow &window) override;
    void update(const sf::Time& time) override;
    void draw(sf::RenderWindow &window) override;
    void next() override;
    GameStates shouldSwitch() override;

private:
    GameStates m_shouldSwitch; ///< State we should switch to

    sf::Texture m_introTexture;
    sf::Sprite m_introSprite;
    sf::Font m_font;
    sf::Text m_text;
    float m_timePassed; ///< Time passed since first init of the object
};


#endif
