#ifndef HEXXAGON_BOARD_H
#define HEXXAGON_BOARD_H
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Hex.h"
#include "HexHash.h"
#include "Player.h"
#include "States/Multiplayer_State.h"

class Board
{
public:

    void init(int size, Player& player1, Player& player2);
    void setAllHexesToFree();
    void placeHex(std::unordered_map<Hex, HexInfo>::iterator, Player& player, Player& enemy);
    void showAvailableMoves(std::unordered_map<Hex, HexInfo>::iterator hex);

    std::unordered_map<Hex, HexInfo>& getBoard() { return m_board; };

private:
    void setHexagonalShape(int map_radius);
private:
    std::unordered_map<Hex, HexInfo> m_board;
};


#endif //HEXXAGON_BOARD_H
