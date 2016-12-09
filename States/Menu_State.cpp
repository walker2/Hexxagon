#include "Menu_State.h"

void Menu_State::init(int screenWidth, int screenHeight, ResourceManager* resourceManager, int* diff1, int* diff2)
{
    m_shouldSwitch = GameStates::NONE;

    m_introTexture = resourceManager->getImage("media/images/HEXX_LOGO.png");
    m_introSprite.setTexture(m_introTexture);
    m_introSprite.setOrigin(m_introTexture.getSize().x / 2.0f, m_introTexture.getSize().y / 2.0f);

    m_introSprite.setPosition(400, 100);

    m_buttonSize = sf::Vector2f(400.0f, 64.0f);
    m_buttonPos = sf::Vector2f(400.0f, 250.0f);
    m_buttonPadding = 16;

    std::string str[4];
    str[0] = "Player vs Player";
    str[1] = "Player vs Computer";
    str[2] = "Computer vs Computer";
    str[3] = "Exit";

    for (int i = 0; i < 4; ++i)
    {
        sf::Vector2f buttonPosition(m_buttonPos.x, m_buttonPos.y + (i * (m_buttonSize.y + m_buttonPadding)));
        m_rects[i].setSize(m_buttonSize);
        m_rects[i].setFillColor(sf::Color(236, 240, 241));

        m_rects[i].setOrigin(m_buttonSize.x / 2.0f, m_buttonSize.y / 2.0f);
        m_rects[i].setPosition(buttonPosition);

        m_labels[i].setFont(resourceManager->getFont("media/fonts/roboto_black.ttf"));
        m_labels[i].setColor(sf::Color(231, 76, 60));
        m_labels[i].setString(sf::String(str[i]));
        m_labels[i].setCharacterSize(32);

        sf::FloatRect rect = m_labels[i].getLocalBounds();
        m_labels[i].setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);

        m_labels[i].setPosition(buttonPosition);
    }
}

void Menu_State::processInput(sf::RenderWindow &window)
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonReleased:
                if (event.key.code == sf::Mouse::Button::Left)
                {
                    mouseClick(window);
                }
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                    case sf::Keyboard::Up:
                        if (m_selected == 0)
                            m_selected = 3;
                        else
                            m_selected--;
                        break;
                    case sf::Keyboard::Down:
                        if (m_selected == 3)
                            m_selected = 0;
                        else
                            m_selected++;
                        break;
                    case sf::Keyboard::Space:
                        next();
                        break;
                }
                break;
        }
    }
}

void Menu_State::update(const sf::Time &time)
{

}

void Menu_State::draw(sf::RenderWindow &window)
{
    window.draw(m_introSprite);
    for (int i = 0; i < 4; ++i)
    {
        if (m_selected == i)
        {
            sf::RectangleShape shape(m_rects[i]);
            shape.setOutlineColor(sf::Color(231, 76, 60));
            shape.setOutlineThickness(3);
            window.draw(shape);
        }
        else
        {
            window.draw(m_rects[i]);
        }

        window.draw(m_labels[i]);
    }
}

void Menu_State::next()
{
    switch (m_selected)
    {
        case 0:
            m_shouldSwitch = GameStates::MULTIPLAYER;
            break;
        case 1:
            m_shouldSwitch = GameStates::DIFFICULTY_SINGLEPLAYER;
            break;
        case 2:
            m_shouldSwitch = GameStates::DIFFICULTY_COMPUTERWARS;
            break;
        case 3:
            m_shouldSwitch = GameStates::EXIT;
            break;
    }
}

GameStates Menu_State::shouldSwitch()
{
    return m_shouldSwitch;
}

void Menu_State::mouseClick(sf::RenderWindow &window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    float halfX = m_buttonSize.x / 2.0f;
    float halfY = m_buttonSize.y / 2.0f;

    for (int i = 0; i < 4; ++i)
    {
        if (mousePos.x >= m_rects[i].getPosition().x - halfX &&
            mousePos.x <= m_rects[i].getPosition().x + halfX &&
            mousePos.y >= m_rects[i].getPosition().y - halfY &&
            mousePos.y <= m_rects[i].getPosition().y + halfY)
        {
            if (i == 0)
            {
                m_shouldSwitch = GameStates::MULTIPLAYER;
            }
            else if (i == 1)
            {
                m_shouldSwitch = GameStates::DIFFICULTY_SINGLEPLAYER;
            }
            else if (i == 2)
            {
                m_shouldSwitch = GameStates::DIFFICULTY_COMPUTERWARS;
            }
            else if (i == 3)
            {
                m_shouldSwitch = GameStates::EXIT;
            }
        }
    }
}
