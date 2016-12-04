#ifndef HEXXAGON_BOARD_H
#define HEXXAGON_BOARD_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Hex.h"
#include "HexHash.h"
#include "Player.h"
#include "States/Multiplayer_State.h"

struct Move
{
    Move() {};
    Move(int _score) : score(_score) {};
    int score;
    std::unordered_map<Hex, HexInfo>::iterator it;
    std::unordered_map<Hex, HexInfo>::iterator prev_it;
    bool isJump = false;
};

class Board
{
public:

    void init(int size, Player& player1, Player& player2);
    void setAllHexesToFree();
    void placeHex(std::unordered_map<Hex, HexInfo>::iterator, Player& player, Player& enemy);
    void showAvailableMoves(std::unordered_map<Hex, HexInfo>::iterator hex);
    bool handleMove(Player &player, Player &enemy, sf::Vector2i localPosition, Layout layout);
    void handleAIMove(Player &player, Player &enemy);
    Move getBestAIMove(Player &player, Player &enemy, int depth, Move alpha, Move beta, int startPoints);
    bool isGameOver(Player &player);


    std::unordered_map<Hex, HexInfo>& getBoard() { return m_board; };

private:
    void setHexagonalShape(int map_radius);

private:
    std::unordered_map<Hex, HexInfo> m_board;
    std::unordered_map<Hex, HexInfo>::iterator m_prevHex;

};


#endif //HEXXAGON_BOARD_H
