#ifndef HEXXAGON_MENU_STATE_H
#define HEXXAGON_MENU_STATE_H


#include "Game_State.h"
#include "../ResourceManager.h"

class Menu_State : public Game_State
{
public:
    Menu_State() {};
    ~Menu_State() {};

    void init(int screenWidth, int screenHeight) override ;
    void processInput(sf::RenderWindow &window) override;
    void update(const sf::Time& time) override;
    void draw(sf::RenderWindow &window) override;
    void next() override;
    GameStates shouldSwitch() override;

private:
    void mouseClick(sf::RenderWindow &window);

private:
    GameStates m_shouldSwitch;
    unsigned int m_buttonPadding;
    ResourceManager m_resourceManager;

    sf::Font m_font;
    sf::Texture m_introTexture;
    sf::Sprite m_introSprite;
    sf::Vector2f m_buttonSize;
    sf::Vector2f m_buttonPos;
    sf::RectangleShape m_rects[3];
    sf::Text m_labels[3];
};


#endif
