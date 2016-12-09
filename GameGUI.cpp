#include <iostream>
#include "GameGUI.h"

GameGUI::GameGUI()
{
    if (!buffer.loadFromFile("media/sounds/to_the_moon.ogg"))
    {
        std::cout << "Music can't be loaded" << std::endl;
    }
    std::cout << buffer.getSampleRate() << std::endl;

    m_music.setBuffer(buffer);
    m_music.setLoop(true);
    m_music.play();
}

GameGUI::~GameGUI()
{

    m_music.stop();
}

void GameGUI::drawBoard(Board& hexBoard, sf::Color hexColor, sf::Color outlineColor, Layout &layout,
                        sf::Color& player1Color, sf::Color& player2Color, sf::RenderWindow& window)
{

    for (auto &hex : hexBoard.getBoard())
    {
        std::vector<sf::Vector2f> corners = hex.first.polygon_corners(layout);
        sf::ConvexShape convexShape(6);
        sf::CircleShape circleShape(8);

        convexShape.setFillColor(hexColor);
        convexShape.setOutlineColor(outlineColor);
        convexShape.setOutlineThickness(2);
        convexShape.setOrigin(0, 0);
        convexShape.setPosition(hex.first.toPixel(layout).x, hex.first.toPixel(layout).y);

        convexShape.setPoint(0, sf::Vector2f(corners[0].x, corners[0].y));
        convexShape.setPoint(1, sf::Vector2f(corners[1].x, corners[1].y));
        convexShape.setPoint(2, sf::Vector2f(corners[2].x, corners[2].y));
        convexShape.setPoint(3, sf::Vector2f(corners[3].x, corners[3].y));
        convexShape.setPoint(4, sf::Vector2f(corners[4].x, corners[4].y));
        convexShape.setPoint(5, sf::Vector2f(corners[5].x, corners[5].y));

        if (hex.second.inRangeOne)
        {
            convexShape.setFillColor(sf::Color(156, 155, 122));
        }
        else if (hex.second.inRangeTwo)
        {
            convexShape.setFillColor(sf::Color(255, 211, 147));
        }


        circleShape.setOrigin(8, 8);
        circleShape.setPosition({ convexShape.getPosition().x * 2, convexShape.getPosition().y * 2 });

        switch (hex.second.attachedToPlayer)
        {
            case HexInfo::PlayerType::PLAYER1:
                circleShape.setFillColor(player1Color);
                break;
            case HexInfo::PlayerType::PLAYER2:
                circleShape.setFillColor(player2Color);
                break;
            case HexInfo::PlayerType ::NONE:
                circleShape.setFillColor(sf::Color::Transparent);
                break;
        }
        if (hex.first == hexBoard.getSelectedHex()->first)
        {
            convexShape.setOutlineThickness(4);
            convexShape.setOutlineColor(sf::Color(231, 76, 60));
            m_selectedShape = std::make_pair(convexShape, circleShape);
        }
        else
        {
            window.draw(convexShape);
            window.draw(circleShape);
        }
    }
    window.draw(m_selectedShape.first);
    window.draw(m_selectedShape.second);
}

void GameGUI::createLabel(std::string text, std::string fontPath, sf::Color color, ResourceManager *resourceManager,
                       sf::Vector2f position, int charSize)
{
    sf::Text label;
    label.setString(text);
    label.setColor(color);
    label.setFont(resourceManager->getFont(fontPath));
    label.setCharacterSize(charSize);
    sf::FloatRect rect = label.getLocalBounds();
    label.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
    label.setPosition(position);
    m_labels.emplace_back(label);
}

void GameGUI::changeLabelText(int num, std::string text)
{
    m_labels[num].setString(text);
}

void GameGUI::changeLabelColor(int num, sf::Color color)
{
    m_labels[num].setColor(color);
}

void GameGUI::drawLabels(sf::RenderWindow& window)
{
    for (auto &label : m_labels)
    {
        sf::FloatRect rect = label.getLocalBounds();
        label.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
        window.draw(label);
    }
}

void GameGUI::drawBackground(sf::RenderWindow &window, float time)
{

    sf::Texture texture;
    if (!texture.loadFromFile("Shaders/background.jpg"))
        window.close();

    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::Shader shader;
    if (!shader.loadFromFile("Shaders/galaxy.frag", sf::Shader::Fragment))
        window.close();

    static int music;
    static const int NUM_SAMPLES = 16; //How many frames we average
    static float frameTimes[NUM_SAMPLES];
    static int currentFrame = 0;

    music += m_music.getPlayingOffset().asSeconds();
    frameTimes[currentFrame % NUM_SAMPLES] = std::abs(buffer.getSamples()[music] % 10);

    int count;
    currentFrame++;
    if (currentFrame < NUM_SAMPLES)
        count = currentFrame;
    else
        count = NUM_SAMPLES;

    float frameTimeAverage = 0;
    for (int i = 0; i < count; i++)
    {
        frameTimeAverage += frameTimes[i];
    }

    frameTimeAverage /= count;


    shader.setParameter("u_resolution", sf::Vector3f(800, 600, 0));
    shader.setParameter("u_time", time);
    shader.setParameter("u_music", frameTimeAverage);


    window.draw(sprite, &shader);
}






