#include "Game.h"


Game::Game(): m_screenWidth(800),
              m_screenHeight(600)
{

};

void Game::run()
{
    initSystems();
    gameLoop();
}

void Game::initSystems()
{
    m_window.create(sf::VideoMode(m_screenWidth, m_screenHeight, 32), "GAME", sf::Style::Default);
    m_state = &intro_state;
    m_state->init(m_screenWidth, m_screenHeight, &m_resourceManager);
}

void Game::processInput()
{

}

void Game::gameLoop()
{
    while (m_window.isOpen())
    {
        sf::Time elapsed = m_clock.restart();

        m_state->processInput(m_window);
        m_state->update(elapsed);

        switch (m_state->shouldSwitch())
        {
            case GameStates::INTRO:
                m_state = &intro_state;
                m_state->init(m_screenWidth, m_screenHeight, &m_resourceManager);
                break;
            case GameStates::MENU:
                m_state = &menu_state;
                m_state->init(m_screenWidth, m_screenHeight, &m_resourceManager);
                break;
            case GameStates::MULTIPLAYER:
                m_state = &multiplayer_state;
                m_state->init(m_screenWidth, m_screenHeight, &m_resourceManager);
                break;
            case GameStates::SINGLEPLAYER:
                m_state = &singleplayer_state;
                m_state->init(m_screenWidth, m_screenHeight, &m_resourceManager);
                break;
            case GameStates::EXIT:
                m_window.close();
                break;
            case GameStates::NONE:
                break;
        }
        draw();
    }
}

void Game::draw()
{
    m_window.clear(sf::Color(44, 62, 80));

    m_state->draw(m_window);

    m_window.display();
}
