#ifndef HEXXAGON_GAMEGUI_H
#define HEXXAGON_GAMEGUI_H

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "Board.h"

class Board;
/**
 * Class for handling all the game GUI
 */
class GameGUI
{
public:
    GameGUI();
    ~GameGUI();
    /**
     * Function for drawing the board
     * @param hexBoard Board that should be drawn
     * @param hexColor Background color of hexes
     * @param outlineColor Color of ouline around hexes
     * @param layout Layout type
     * @param player1Color Color of the first player
     * @param player2Color Color of the second player
     * @param window Window for rendering
     */
    void drawBoard(Board& hexBoard, sf::Color hexColor, sf::Color outlineColor, Layout &layout,
                   sf::Color& player1Color, sf::Color& player2Color, sf::RenderWindow& window);
    /**
     * Function for creating label from text and path to font
     * @param text Text for label
     * @param fontPath Font that will be used
     * @param color Color of label
     * @param resourceManager ResourceManager object pointer for getting fonts
     * @param position Position in screen coordinates
     * @param charSize Size of characters
     */
    void createLabel(std::string text, std::string fontPath, sf::Color color, ResourceManager *resourceManager,
                     sf::Vector2f position, int charSize);
    /**
     * Function for changing text of label
     * @param num Number of label
     * @param text Text that will be shown
     */
    void changeLabelText(int num, std::string text);
    /**
     * Function for changing label color
     * @param num Number of label
     * @param color Color that will be shown
     */
    void changeLabelColor(int num, sf::Color color);
    /**
     * Function for drawing all labels on screen
     * @param window Window for rendering
     */
    void drawLabels(sf::RenderWindow& window);
    /**
     * Function for drawing background
     * @param window Window for rendering
     * @param time Float of timePassed since last envoking of this function
     */
    void drawBackground(sf::RenderWindow& window, float time);

private:
    std::vector<sf::Text> m_labels;
    sf::Sound m_music;
    sf::SoundBuffer buffer;
    std::pair<sf::ConvexShape, sf::CircleShape> m_selectedShape; //Should be drawn on top of all
};


#endif
