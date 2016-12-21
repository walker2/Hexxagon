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
/**
 * Class for handling all the players input during the game
 */
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
    /**
     * Function that controls all players turns
     * @param window Window to get input from
     */
    void makeMove(sf::RenderWindow &window);
    /**
     * Function that handles current input based on if Player is AI or not
     * @param player Friendly player
     * @param enemy Enemy player
     * @param window Window to get input from
     * @return true if move is done
     */
    bool handleMove(Player& player, Player& enemy, sf::RenderWindow &window);
    /**
     * Function that controls GUI behaviour after successful move
     * @param player Player who just done the move
     */
    void setGUIAfterMove(Player& player);
    /**
     * Function that sets and control GUI behaviour after the game is over
     */
    void setGUIAfterGameOver();

private:
    int m_boardSize; ///< Size of the game board
    int m_difficultyLevel; ///< Difficulty level for our computer player
    bool m_keyboardInput = false; ///< Flag that shows if we getting input from keyboard
    bool m_turn; ///< Flag for current turn
    bool m_isGameOver; ///< Flag, true if game is over
    float m_time; ///< Elapsed time

    GameStates m_gameType; ///< Current type of game (singleplayer, multiplayer etc.)
    GameStates m_shouldSwitch; ///< State we should switch to

    Board* m_board; ///< Pointer to board
    GameGUI* m_gameGUI; ///< Pointer to game gui
    Layout m_layout; ///< Layout type
    Player* m_player1; ///< Pointer to the first player
    Player* m_player2; ///< Pointer to the second player

};


#endif
