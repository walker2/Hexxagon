#ifndef HEXXAGON_BOARD_H
#define HEXXAGON_BOARD_H
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Hex.h"
#include "HexHash.h"
#include "Player.h"

class Board
{
public:
    void init(int size, sf::Color hexColor, sf::Color outlineColor, Layout& layout);
    void draw(sf::RenderWindow &window);
    void setAllConvexColor(sf::Color color);
    void placeHex(std::unordered_map<Hex, HexImage>::iterator, Player& player, Player& enemy);
    void showAvailableMoves(std::unordered_map<Hex, HexImage>::iterator hex);

    std::unordered_map<Hex, HexImage>& getBoard() { return m_board; };

private:
    void setHexagonalShape(int map_radius);
private:
    std::unordered_map<Hex, HexImage> m_board;
};


#endif //HEXXAGON_BOARD_H
