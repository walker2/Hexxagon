#ifndef HEXXAGON_MULTIPLAYER_STATE_H
#define HEXXAGON_MULTIPLAYER_STATE_H


#include "Game_State.h"
#include "../Hex.h"
#include "../Board.h"
#include "../Player.h"
#include "../ResourceManager.h"

struct Move
{
    Move() {};
    Move(int _score) : score(_score) {};
    int score;
    std::unordered_map<Hex, HexImage>::iterator it;
    std::unordered_map<Hex, HexImage>::iterator prev_it;
    bool isJump = false;
};

class Multiplayer_State : public Game_State
{
public:
    Multiplayer_State(bool isAIgame) : m_layout(LAYOUT_POINTY, sf::Vector2f(16, 16), sf::Vector2f(200, 150)), m_boardSize(3),
        m_isAIgame(isAIgame){};
    void init(int screenWidth, int screenHeight) override;
    void processInput(sf::RenderWindow &window) override;
    void update(const sf::Time &time) override;
    void draw(sf::RenderWindow &window) override;
    GameStates shouldSwitch() override;
    void next() override;

private:
    void makeMove(sf::RenderWindow &window);
    bool handleMove(Player& player, Player& enemy, sf::RenderWindow &window);
    void handleAIMove(Player& player, Player& enemy);
    bool isGameOver(Player& player);
    void setGUIAfterMove(Player& player, Player& enemy);
    void setGUIAfterGameOver(Player& player, Player& enemy);
    Move getBestAIMove(Player & player, Player & enemy, int depth, Move alpha, Move beta);

private:
    int m_boardSize;
    bool m_turn;
    bool m_isAIgame;
    bool m_isGameOver;

    GameStates m_shouldSwitch;
    Board* m_board;
    Layout m_layout;
    Player* m_player1;
    Player* m_player2;
    ResourceManager m_resourceManager;

    sf::Text m_labels[4];
    sf::Font m_font;

    std::unordered_map<Hex, HexImage>::iterator m_prevHex;
};


#endif
