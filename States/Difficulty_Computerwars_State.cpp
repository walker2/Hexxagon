#include <iostream>
#include "Difficulty_Computerwars_State.h"

void Difficulty_Computerwars_State::init(int screenWidth, int screenHeight, ResourceManager *resourceManager, int* diff1, int* diff2)
{
    m_diff1 = diff1;
    m_diff2 = diff2;
    m_shouldSwitch = GameStates::NONE;

    m_introTexture = resourceManager->getImage("media/images/HEXX_LOGO.png");
    m_introSprite.setTexture(m_introTexture);
    m_introSprite.setOrigin(m_introTexture.getSize().x / 2.0f, m_introTexture.getSize().y / 2.0f);

    m_introSprite.setPosition(400, 100);

    m_buttonSize = sf::Vector2f(200.0f, 64.0f);
    m_buttonPos = sf::Vector2f(200.0f, 200.0f);
    m_buttonPadding = 16;

    std::string str[5];
    str[0] = "COMPUTER 1: ";
    str[1] = "EASY";
    str[2] = "MEDIUM";
    str[3] = "HARD";
    str[4] = "Back";

    for (int i = 0; i < 5; ++i)
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
    m_buttonPos = sf::Vector2f(600.0f, 200.0f);
    str[0] = "COMPUTER 2: ";
    str[1] = "EASY";
    str[2] = "MEDIUM";
    str[3] = "HARD";
    str[4] = "Accept";

    for (int i = 0; i < 5; ++i)
    {

        sf::Vector2f buttonPosition(m_buttonPos.x, m_buttonPos.y + (i * (m_buttonSize.y + m_buttonPadding)));

        m_rects[i + 5].setSize(m_buttonSize);
        m_rects[i + 5].setFillColor(sf::Color(236, 240, 241));

        m_rects[i + 5].setOrigin(m_buttonSize.x / 2.0f, m_buttonSize.y / 2.0f);
        m_rects[i + 5].setPosition(buttonPosition);

        m_labels[i + 5].setFont(resourceManager->getFont("media/fonts/roboto_black.ttf"));
        m_labels[i + 5].setColor(sf::Color(231, 76, 60));
        m_labels[i + 5].setString(sf::String(str[i]));
        m_labels[i + 5].setCharacterSize(32);

        sf::FloatRect rect = m_labels[i + 5].getLocalBounds();
        m_labels[i + 5].setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);

        m_labels[i + 5].setPosition(buttonPosition);
    }
}

void Difficulty_Computerwars_State::processInput(sf::RenderWindow &window)
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
        }
    }
}

void Difficulty_Computerwars_State::update(const sf::Time &time)
{

}

void Difficulty_Computerwars_State::draw(sf::RenderWindow &window)
{
    window.draw(m_introSprite);
    window.draw(m_labels[0]);
    for (int i = 1; i < 5; ++i)
    {
        window.draw(m_rects[i]);
        window.draw(m_labels[i]);
    }
    window.draw(m_labels[5]);
    for (int i = 6; i < 10; ++i)
    {
        window.draw(m_rects[i]);
        window.draw(m_labels[i]);
    }

}

void Difficulty_Computerwars_State::next()
{
    if (*m_diff1 != 0 && *m_diff2 != 0)
        m_shouldSwitch = GameStates::COMPUTERWARS;
    else
        std::cout << "You should choose difficulty \n";
}

GameStates Difficulty_Computerwars_State::shouldSwitch()
{
    return m_shouldSwitch;
}

void Difficulty_Computerwars_State::mouseClick(sf::RenderWindow &window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    float halfX = m_buttonSize.x / 2.0f;
    float halfY = m_buttonSize.y / 2.0f;

    for (int i = 1; i < 10; ++i)
    {
        if (mousePos.x >= m_rects[i].getPosition().x - halfX &&
            mousePos.x <= m_rects[i].getPosition().x + halfX &&
            mousePos.y >= m_rects[i].getPosition().y - halfY &&
            mousePos.y <= m_rects[i].getPosition().y + halfY)
        {
            switch (i)
            {
                case 1:
                    *m_diff1 = 1;
                    m_rects[1].setOutlineColor(sf::Color::Red);
                    m_rects[1].setOutlineThickness(3);
                    m_rects[2].setOutlineColor(sf::Color::Transparent);
                    m_rects[3].setOutlineColor(sf::Color::Transparent);
                    break;
                case 2:
                    *m_diff1 = 2;
                    m_rects[2].setOutlineColor(sf::Color::Red);
                    m_rects[2].setOutlineThickness(3);
                    m_rects[1].setOutlineColor(sf::Color::Transparent);
                    m_rects[3].setOutlineColor(sf::Color::Transparent);
                    break;
                case 3:
                    *m_diff1 = 3;
                    m_rects[3].setOutlineColor(sf::Color::Red);
                    m_rects[3].setOutlineThickness(3);
                    m_rects[1].setOutlineColor(sf::Color::Transparent);
                    m_rects[2].setOutlineColor(sf::Color::Transparent);
                    break;
                case 4:
                    m_shouldSwitch = GameStates::MENU;
                    break;
                case 6:
                    *m_diff2 = 1;
                    m_rects[6].setOutlineColor(sf::Color::Red);
                    m_rects[6].setOutlineThickness(3);
                    m_rects[7].setOutlineColor(sf::Color::Transparent);
                    m_rects[8].setOutlineColor(sf::Color::Transparent);
                    break;
                case 7:
                    *m_diff2 = 2;
                    m_rects[7].setOutlineColor(sf::Color::Red);
                    m_rects[7].setOutlineThickness(3);
                    m_rects[6].setOutlineColor(sf::Color::Transparent);
                    m_rects[8].setOutlineColor(sf::Color::Transparent);
                    break;
                case 8:
                    *m_diff2 = 3;
                    m_rects[8].setOutlineColor(sf::Color::Red);
                    m_rects[8].setOutlineThickness(3);
                    m_rects[6].setOutlineColor(sf::Color::Transparent);
                    m_rects[7].setOutlineColor(sf::Color::Transparent);
                    break;
                case 9:
                    next();
                    break;
            }
        }
    }
}
