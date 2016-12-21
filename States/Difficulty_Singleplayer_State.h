#ifndef HEXXAGON_DIFFICULTY_STATE_H
#define HEXXAGON_DIFFICULTY_STATE_H


#include "Game_State.h"
/**
 * Class for choosing difficulty for singleplayer game
 */
class Difficulty_Singleplayer_State : public Game_State
{
public:
    Difficulty_Singleplayer_State() {};
    ~Difficulty_Singleplayer_State() {};
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
    int* m_diff; ///< Difficulty level for computer player
    int m_selected = 0; ///< Number of currently selected rect
    GameStates m_shouldSwitch; ///< State we should switch to
    unsigned int m_buttonPadding; ///< Padding between buttons

    sf::Font m_font;
    sf::Texture m_introTexture;
    sf::Sprite m_introSprite;
    sf::Vector2f m_buttonSize;
    sf::Vector2f m_buttonPos;
    sf::RectangleShape m_rects[10]; ///< Array of all rect shapes
    sf::Text m_labels[8]; ///< Array of all text labels
};


#endif
