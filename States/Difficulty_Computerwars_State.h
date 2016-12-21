#ifndef HEXXAGON_DIFFICULTY_MULTIPLAYER_STATE_H
#define HEXXAGON_DIFFICULTY_MULTIPLAYER_STATE_H


#include "Game_State.h"
/**
 * Class for choosing difficulties for two computer players
 */
class Difficulty_Computerwars_State : public Game_State
{
public:
    Difficulty_Computerwars_State() {};
    ~Difficulty_Computerwars_State() {};
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
    /**
     * Function for handling space button presses
     */
    void spacePressed();

private:
    int* m_diff1; ///< Difficulty level for first computer player
    int* m_diff2; ///< Difficulty level for second computer player
    int m_selected = 1;
    int m_selCol1 = 1; ///< Rect currently selected in left column
    int m_selCol2 = 6; ///< Rect currently selected in right column

    GameStates m_shouldSwitch; ///< State we should switch to
    unsigned int m_buttonPadding; ///< Padding between buttons

    sf::Font m_font;
    sf::Texture m_introTexture;
    sf::Sprite m_introSprite;
    sf::Vector2f m_buttonSize;
    sf::Vector2f m_buttonPos;
    sf::RectangleShape m_rects[10]; ///< Array of all rect shapes
    sf::Text m_labels[10]; ///< Array of all text labels
};


#endif
