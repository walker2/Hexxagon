#ifndef HEXXAGON_PLAYER_H
#define HEXXAGON_PLAYER_H

#include "SFML/Graphics.hpp"
#include <unordered_map>
#include <list>
#include "Hex.h"
#include "HexHash.h"

class Player
{
public:
    Player(HexInfo::PlayerType playerType, int points, std::string name, bool isAI, int difficulty)
            : m_playerType(playerType), m_points(points), m_name(name), m_AI(isAI), m_difficulty(difficulty) {};

    void addPoints(int num) { m_points += num; };
    void addToList(std::unordered_map<Hex, HexInfo>::iterator& it) { m_hexesList.push_back(it); };
    void extractPoints(int num) { m_points -= num; }
    void removeFromList(std::unordered_map<Hex, HexInfo>::iterator& it) { m_hexesList.remove(it); };

    std::list<std::unordered_map<Hex, HexInfo>::iterator>& getList() { return m_hexesList; };
    HexInfo::PlayerType getPlayerType() { return m_playerType; };
    int getPoints() { return m_points; };
    int getDifficulty() { return m_difficulty; };
    bool isAI() { return m_AI; };
    std::string getName() { return m_name; };

private:
    bool m_AI;
    int m_points;
    int m_difficulty;

    std::string m_name;
    std::list<std::unordered_map<Hex, HexInfo>::iterator> m_hexesList;
    HexInfo::PlayerType  m_playerType;

};

#endif
