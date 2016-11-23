
#ifndef HEXXAGON_INTRO_STATE_H
#define HEXXAGON_INTRO_STATE_H

#include "Game_State.h"
#include "GameStates.h"
#include "../ResourceManager.h"


class Intro_State : public Game_State
{
public:
    Intro_State() {};
    ~Intro_State();

    void init(int screenWidth, int screenHeight) override;
    void processInput(sf::RenderWindow &window) override;
    void update(const sf::Time& time) override;
    void draw(sf::RenderWindow &window) override;
    void next() override;
    GameStates shouldSwitch() override;

private:
    GameStates m_shouldSwitch;
    ResourceManager m_resourceManager;

    sf::Texture m_introTexture;
    sf::Sprite m_introSprite;
    sf::Font m_font;
    sf::Text m_text;
    float m_timePassed;
};


#endif