#include "Multiplayer_State.h"
#include <iostream>

#define PL1CLR sf::Color(52, 152, 219)
#define PL2CLR sf::Color(231, 76, 60)

void Multiplayer_State::init(int screenWidth, int screenHeight, ResourceManager* resourceManager, int* diff1, int* diff2)
{

    m_board = new Board();
    m_gameGUI = new GameGUI();

    switch (m_gameType)
    {
        case GameStates::MULTIPLAYER:
            m_player1 = new Player(HexInfo::PlayerType::PLAYER1, 1, "PLAYER 1", 0, 3);
            m_player2 = new Player(HexInfo::PlayerType::PLAYER2, 1, "PLAYER 2", 0, 3);
            break;
        case GameStates::SINGLEPLAYER:
            m_player1 = new Player(HexInfo::PlayerType::PLAYER1, 1, "PLAYER 1", 0, *diff1);
            m_player2 = new Player(HexInfo::PlayerType::PLAYER2, 1, "COMPUTER", 1, *diff1);
            break;
        case GameStates::COMPUTERWARS:
            m_player1 = new Player(HexInfo::PlayerType::PLAYER1, 1, "COMPUTER 1", 1, *diff1);
            m_player2 = new Player(HexInfo::PlayerType::PLAYER2, 1, "COMPUTER 2", 1, *diff2);
            break;
    }
    std::cout << m_player1->getDifficulty() << std::endl;
    std::cout << m_player2->getDifficulty() << std::endl;
    m_shouldSwitch = GameStates::NONE;
    m_turn = 0;
    m_isGameOver = false;

    m_board->init(3, *m_player1, *m_player2);
    sf::Color color1 = PL1CLR;
    sf::Color color2 = PL2CLR;
    m_gameGUI->createLabel("1", "media/fonts/roboto_black.ttf", color1, resourceManager, {50.0f, 25.0f}, 48);
    m_gameGUI->createLabel(m_player1->getName() + " TURN", "media/fonts/roboto_black.ttf", color1, resourceManager, {400.0f, 25.0f}, 32);
    m_gameGUI->createLabel("1", "media/fonts/roboto_black.ttf", color2, resourceManager, {750.0f, 25.0f}, 48);
    m_gameGUI->createLabel("FFFFFFFFFFFFFFFFF", "media/fonts/arial.ttf", sf::Color::Transparent, resourceManager, {400.0f, 500.0f}, 24);
}

void Multiplayer_State::processInput(sf::RenderWindow &window)
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Button::Left && !m_isGameOver)
                {
                    makeMove(window);
                }
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                    case sf::Keyboard::Right:
                        m_board->selectRightHex();
                        break;
                    case sf::Keyboard::Left:
                        m_board->selectLeftHex();
                        break;
                    case sf::Keyboard::Up:
                        m_board->selectUpHex();
                        break;
                    case sf::Keyboard::Down:
                        m_board->selectDownHex();
                        break;
                    case sf::Keyboard::Space:
                        if (!m_isGameOver)
                        {
                            makeMove(window);
                            m_keyboardInput = true;
                        }
                        break;
                    case sf::Keyboard::Escape:
                        if (m_isGameOver)
                        {
                            next();
                        }
                        break;
                    case sf::Keyboard::BackSpace:
                    {
                        delete m_board;
                        delete m_gameGUI;
                        delete m_player1;
                        delete m_player2;
                        m_shouldSwitch = GameStates::MENU;
                    }
                }
                break;
        }
    }
}

void Multiplayer_State::update(const sf::Time &time)
{
    m_time += time.asSeconds();
}

void Multiplayer_State::draw(sf::RenderWindow &window)
{
    sf::Color color1 = PL1CLR;
    sf::Color color2 = PL2CLR;

    m_gameGUI->drawBackground(window, m_time);
    m_gameGUI->drawBoard(*m_board, sf::Color(236, 240, 241), sf::Color::Black, m_layout, color1, color2, window);
    m_gameGUI->drawLabels(window);
}

GameStates Multiplayer_State::shouldSwitch()
{
    return m_shouldSwitch;
}

void Multiplayer_State::next()
{
    delete m_board;
    delete m_gameGUI;
    delete m_player1;
    delete m_player2;
    m_shouldSwitch = GameStates::INTRO;
}

void Multiplayer_State::makeMove(sf::RenderWindow &window)
{
    if (!m_turn && !m_isGameOver)
    {
        if (handleMove(*m_player1, *m_player2, window))
        {
            setGUIAfterMove(*m_player2);
        }
        if (m_board->isGameOver(*m_player1) || m_board->isGameOver(*m_player2))
        {
            setGUIAfterGameOver();
        }
    }
    else
    {
        if (handleMove(*m_player2, *m_player1, window))
        {
            setGUIAfterMove(*m_player1);
        }
        if (m_board->isGameOver(*m_player2) || m_board->isGameOver(*m_player1))
        {
            setGUIAfterGameOver();
        }
    }
}

bool Multiplayer_State::handleMove(Player &player, Player &enemy, sf::RenderWindow &window)
{
    if(player.isAI())
    {
        m_board->handleAIMove(player, enemy);
        return true;
    }
    else if (!m_keyboardInput)
    {
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        return m_board->handleMove(player, enemy, localPosition, m_layout);
    }
    else
    {
        return m_board->handleMove(player, enemy, sf::Vector2i(-1, -1), m_layout);
    }
}

void Multiplayer_State::setGUIAfterMove(Player& player)
{
    m_turn = !m_turn;

    m_gameGUI->changeLabelText(0, std::to_string(m_player1->getPoints()));
    m_gameGUI->changeLabelText(1, player.getName() + " TURN");
    m_gameGUI->changeLabelText(2, std::to_string(m_player2->getPoints()));

    switch (player.getPlayerType())
    {
        case HexInfo::PlayerType::PLAYER1:
            m_gameGUI->changeLabelColor(1, PL1CLR);
            break;
        case HexInfo::PlayerType::PLAYER2:
            m_gameGUI->changeLabelColor(1, PL2CLR);
            break;
    }
}

void Multiplayer_State::setGUIAfterGameOver()
{

    if (m_player1->getPoints() < m_player2->getPoints())// + (m_boardSize * 12  - (m_player2->getPoints() + m_player1->getPoints())))
    {
        m_gameGUI->changeLabelText(1, m_player2->getName() + " WINS");
        m_gameGUI->changeLabelColor(1, PL2CLR);
    }
    else
    {
        m_gameGUI->changeLabelText(1, m_player1->getName() + " WINS");
        m_gameGUI->changeLabelColor(1, PL1CLR);
    }

    m_gameGUI->changeLabelColor(3, sf::Color::White);
    m_gameGUI->changeLabelText(3, "Press SPACE to start again");
    m_isGameOver = true;

}