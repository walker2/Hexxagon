#ifndef HEXXAGON_GAMEGUI_H
#define HEXXAGON_GAMEGUI_H

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "Board.h"

class Board;

class GameGUI
{
public:
    GameGUI();
    ~GameGUI();
    void drawBoard(Board& hexBoard, sf::Color hexColor, sf::Color outlineColor, Layout &layout,
                   sf::Color& player1Color, sf::Color& player2Color, sf::RenderWindow& window);
    void createLabel(std::string text, std::string fontPath, sf::Color color, ResourceManager *resourceManager,
                     sf::Vector2f position, int charSize);
    void changeLabelText(int num, std::string text);
    void changeLabelColor(int num, sf::Color color);
    void drawLabels(sf::RenderWindow& window);
    void drawBackground(sf::RenderWindow& window, float time);

private:
    std::vector<sf::Text> m_labels;
    sf::Sound m_music;
    sf::SoundBuffer buffer;
};


#endif
