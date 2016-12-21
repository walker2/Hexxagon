#ifndef HEXXAGON_PLAYER_H
#define HEXXAGON_PLAYER_H

#include "SFML/Graphics.hpp"
#include <unordered_map>
#include <list>
#include "Hex.h"
#include "HexHash.h"
/**
 * Class for player's info, like points, difficulty and current hexes
 */
class Player
{
public:
    /**
     * Player constructor
     * @param playerType One of types from enum HexInfo::PlayerType
     * @param points Number of starting points
     * @param name Name of player
     * @param isAI Boolean if player is AI
     * @param difficulty Difficulty of player (for AI players)
     */
    Player(HexInfo::PlayerType playerType, int points, std::string name, bool isAI, int difficulty)
            : m_playerType(playerType), m_points(points), m_name(name), m_AI(isAI), m_difficulty(difficulty) {};

    /**
     * Function for adding points to player
     * @param num Number of point to add
     */
    void addPoints(int num) { m_points += num; };
    /**
     * Function for adding new hex iterator to list of players hexes
     * @param it Iterator for hex we should add
     */
    void addToList(std::unordered_map<Hex, HexInfo>::iterator& it) { m_hexesList.push_back(it); };
    /**
     * Function for extracting points from player
     * @param num Number of point to add
     */
    void extractPoints(int num) { m_points -= num; }
    /**
     * Function for removing existing hex iterator from list of players hexes
     * @param it Iterator for hex we should remove
     */
    void removeFromList(std::unordered_map<Hex, HexInfo>::iterator& it) { m_hexesList.remove(it); };

    /**
     * Function for returning list of players hexes
     * @return list of players hexes
     */
    std::list<std::unordered_map<Hex, HexInfo>::iterator>& getList() { return m_hexesList; };
    /**
     * Function for returning players type
     * @return Player type from enum PlayerType
     */
    HexInfo::PlayerType getPlayerType() { return m_playerType; };
    /**
     * Function for returning players current points
     * @return number of points
     */
    int getPoints() { return m_points; };
    /**
    * Function for returning players current difficulty
    * @return players difficulty
    */
    int getDifficulty() { return m_difficulty; };
    /**
    * Function for returning players AI state
    * @return boolean isAI
    */
    bool isAI() { return m_AI; };
    /**
   * Function for returning players name
   * @return players name
   */
    std::string getName() { return m_name; };

private:
    bool m_AI; ///< Flag for setting player to AI
    int m_points; ///< Current points of the player
    int m_difficulty; ///< Current difficulty (depth of the recursion) for computer player

    std::string m_name; ///< Name of the player
    std::list<std::unordered_map<Hex, HexInfo>::iterator> m_hexesList; ///< List of all hexes that player has
    HexInfo::PlayerType  m_playerType; ///< Player type

};

#endif
