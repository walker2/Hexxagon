#include "Intro_State.h"
#include "../Game.h"

Intro_State::~Intro_State()
{

}

void Intro_State::init(int screenWidth, int screenHeight, ResourceManager* resourceManager)
{
    m_shouldSwitch = GameStates::NONE;
    m_timePassed = 0;

    m_introTexture = resourceManager->getImage("media/images/HEXX_LOGO.png");

    m_introSprite.setTexture(m_introTexture);
    m_introSprite.setOrigin(m_introTexture.getSize().x / 2.0f, m_introTexture.getSize().y / 2.0f);

    m_introSprite.setPosition(screenWidth / 2.0f, 0);


    m_text.setColor(sf::Color(236, 240, 241));
    m_text.setFont(resourceManager->getFont("media/fonts/roboto_black.ttf"));
    m_text.setString({ " Press SPACE to continue " });
    m_text.setCharacterSize(20);
    sf::FloatRect textRect = m_text.getLocalBounds();
    m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    m_text.setPosition(screenWidth / 2.0f, screenHeight / 1.5f);
}

void Intro_State::update(const sf::Time &time)
{
    if (m_timePassed < 1.0f)
    { // Less than one second
        m_timePassed += time.asSeconds();
        m_introSprite.setPosition(m_introSprite.getPosition().x,
                                  m_introSprite.getPosition().y + (200 * time.asSeconds()));
    }

}

void Intro_State::draw(sf::RenderWindow &window)
{
    window.draw(m_introSprite);
    if (m_timePassed >= 1.0f)
    {
        window.draw(m_text);
    }
}

void Intro_State::next()
{
    if (m_timePassed >= 1.0f)
    {
        m_shouldSwitch = GameStates::MENU;
    }
}

void Intro_State::processInput(sf::RenderWindow &window)
{

    sf::Event event;
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Space)
                {
                    next();
                }
        }
    }

}

GameStates Intro_State::shouldSwitch()
{
    return m_shouldSwitch;
}


