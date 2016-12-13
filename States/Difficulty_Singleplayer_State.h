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
    void mouseClick(sf::RenderWindow &window);

private:
    int* m_diff;
    int m_selected = 0;
    GameStates m_shouldSwitch;
    unsigned int m_buttonPadding;

    sf::Font m_font;
    sf::Texture m_introTexture;
    sf::Sprite m_introSprite;
    sf::Vector2f m_buttonSize;
    sf::Vector2f m_buttonPos;
    sf::RectangleShape m_rects[10];
    sf::Text m_labels[8];
};


#endif
