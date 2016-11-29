#ifndef HEXXAGON_PLAYER_H
#define HEXXAGON_PLAYER_H

#include "SFML/Graphics.hpp"
#include <unordered_map>
#include <list>
#include "Hex.h"
#include "HexHash.h"

//using hex_iterator = std::unordered_map<Hex, HexImage>::iterator;
class Player
{
public:
    Player(HexInfo::PlayerType playerType, int _points, std::string _name, bool isAI)
            : m_playerType(playerType), points(_points), name(_name), AI(isAI) {};


    HexInfo::PlayerType getPlayerType() { return m_playerType; };
    int getPoints() { return points; }
    bool isAI() { return AI; }
    std::string getName() { return name; }

    void addPoints(int num) { points += num; }
    void extractPoints(int num) { points -= num; }
    void setToAI() { AI = true; }

    std::list<std::unordered_map<Hex, HexInfo>::iterator>& getList() { return hexesList; }
    void addToList(std::unordered_map<Hex, HexInfo>::iterator& it) { hexesList.push_back(it); }
    void removeFromList(std::unordered_map<Hex, HexInfo>::iterator& it) { hexesList.remove(it); }
private:
    HexInfo::PlayerType  m_playerType;
    bool AI;
    int points;
    std::string name;
    std::list<std::unordered_map<Hex, HexInfo>::iterator> hexesList;

};

#endif
