#ifndef HEXXAGON_MULTIPLAYER_STATE_H
#define HEXXAGON_MULTIPLAYER_STATE_H


#include "Game_State.h"
#include "../Hex.h"
#include "../Board.h"
#include "../Player.h"
#include "../ResourceManager.h"
#include "../GameGUI.h"

class Board;
class GameGUI;

class Multiplayer_State : public Game_State
{
public:
    Multiplayer_State(GameStates gameState, int difficultyLevel)
            : m_layout(LAYOUT_POINTY, sf::Vector2f(16, 16), sf::Vector2f(200, 150)), m_boardSize(3),
              m_gameType(gameState), m_time(0.0f), m_difficultyLevel(difficultyLevel){};

    void init(int screenWidth, int screenHeight, ResourceManager* resourceManager, int* diff1, int* diff2) override;
    void processInput(sf::RenderWindow &window) override;
    void update(const sf::Time &time) override;
    void draw(sf::RenderWindow &window) override;
    void next() override;
    GameStates shouldSwitch() override;

private:
    void makeMove(sf::RenderWindow &window);
    bool handleMove(Player& player, Player& enemy, sf::RenderWindow &window);
    void setGUIAfterMove(Player& player);
    void setGUIAfterGameOver();

private:
    int m_boardSize;
    int m_difficultyLevel;
    bool m_turn;
    bool m_isGameOver;
    float m_time;

    GameStates m_gameType;
    GameStates m_shouldSwitch;

    Board* m_board;
    GameGUI* m_gameGUI;
    Layout m_layout;
    Player* m_player1;
    Player* m_player2;

};


#endif
