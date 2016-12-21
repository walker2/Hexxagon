#ifndef HEXXAGON_MENU_STATE_H
#define HEXXAGON_MENU_STATE_H


#include "Game_State.h"
#include "../ResourceManager.h"
/**
 * Class for handling decision making of the player, can switch to all other states except intro
 */
class Menu_State : public Game_State
{
public:
    Menu_State()  {};
    ~Menu_State() {};

    void init(int screenWidth, int screenHeight, ResourceManager* resourceManager, int* diff1, int* diff2) override ;
    void processInput(sf::RenderWindow &window) override;
    void update(const sf::Time& time) override;
    void draw(sf::RenderWindow &window) override;
    void next() override;
    GameStates shouldSwitch() override;

private:
    /**
     * Function that handles mouse clicking on current RenderWindow
     * @param window Window to get input from
     */
    void mouseClick(sf::RenderWindow &window);

private:
    int m_selected = 0; ///< Selected rect number
    GameStates m_shouldSwitch; ///< State we should switch to
    unsigned int m_buttonPadding; ///< Padding between buttons

    sf::Font m_font; ///< Font for all the labels
    sf::Texture m_introTexture;
    sf::Sprite m_introSprite;
    sf::Vector2f m_buttonSize;
    sf::Vector2f m_buttonPos;
    sf::RectangleShape m_rects[4]; ///< Array of all rect shapes
    sf::Text m_labels[4]; ///< Array of all text labels
};


#endif
