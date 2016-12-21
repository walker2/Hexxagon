#ifndef HEXXAGON_BOARD_H
#define HEXXAGON_BOARD_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Hex.h"
#include "HexHash.h"
#include "Player.h"
#include "States/Multiplayer_State.h"
/**
 * Structure for storing Moves
 */
struct Move
{
    Move() {};
    Move(int _score) : score(_score) {};
    int score;  ///< Move score
    std::unordered_map<Hex, HexInfo>::iterator it;  ///< Iterator to hex for performing this move
    std::unordered_map<Hex, HexInfo>::iterator prev_it;  ///< Iterator to previous hex
    bool isJump = false; ///< Flag if move is jump
};
/**
 * Class for storing and calculation game board
 */
class Board
{
public:
    /**
     * Function for initialization of game board, sets shape of board and starting player Hexes
     * @param size Size of the board
     * @param player1 First player
     * @param player2 Second player
     */
    void init(int size, Player& player1, Player& player2);
    /**
     * Function for setting inRangeOne and inRangeTwo of HexInfo to false
     */
    void setAllHexesToFree();
    /**
     * Function for placing hexes on board
     * @param player Friendly player
     * @param enemy Enemy player
     */
    void placeHex(std::unordered_map<Hex, HexInfo>::iterator, Player& player, Player& enemy);
    /**
     * Function for showing all available moves from the hex
     * @param hex The hex
     */
    void showAvailableMoves(std::unordered_map<Hex, HexInfo>::iterator hex);
    /**
     * Function that handles non-computer players moves
     * @param player Friendly player
     * @param enemy Enemy player
     * @param localPosition Current position of the mouse
     * @param layout Layout type
     * @return true if move is done correctly
     */
    bool handleMove(Player &player, Player &enemy, sf::Vector2i localPosition, Layout layout);
    /**
     * Function that handles computer moves
     * @param player Friendly player
     * @param enemy Enemy player
     */
    void handleAIMove(Player &player, Player &enemy);
    /**
     * Function for computing best move for AI
     * @param player Friendly player
     * @param enemy Enemy player
     * @param depth Depth of the recursion
     * @param alpha Alpha value
     * @param beta Beta value
     * @param startPoints Number of points from start of this function
     * @return best Move
     */
    Move getBestAIMove(Player &player, Player &enemy, int depth, Move alpha, Move beta, int startPoints);
    /**
     * Function for calculating if game is over
     * @param player Player
     * @return true if game is over
     */
    bool isGameOver(Player &player);
    /**
     * Function for selecting right hex, sets m_selectedHex
     */
    void selectRightHex();
    /**
    * Function for selecting left hex, sets m_selectedHex
    */
    void selectLeftHex();
    /**
    * Function for selecting top hex, sets m_selectedHex
    */
    void selectUpHex();
    /**
    * Function for selecting bottom hex, sets m_selectedHex
    */
    void selectDownHex();

    /**
     * Function for getting currently selected hex
     * @return iterator to currently selected hex
     */
    std::unordered_map<Hex, HexInfo>::iterator getSelectedHex() { return m_selectedHex; };
    /**
     * Function for getting game board
     * @return game board
     */
    std::unordered_map<Hex, HexInfo>& getBoard() { return m_board; };

private:
    void setHexagonalShape(int map_radius);

private:
    std::unordered_map<Hex, HexInfo> m_board; ///< Game board container
    std::unordered_map<Hex, HexInfo>::iterator m_prevHex; ///< Iterator to previous hex
    std::unordered_map<Hex, HexInfo>::iterator m_selectedHex; ///< Iterator to currently selected hex

};


#endif //HEXXAGON_BOARD_H
