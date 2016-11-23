#include "Board.h"

void Board::init(int size, sf::Color hexColor, sf::Color outlineColor, Layout& layout)
{
    setHexagonalShape(size);

    for (auto itr = m_board.begin(); itr != m_board.end(); ++itr)
    {
        std::vector<sf::Vector2f> corners = itr->first.polygon_corners(layout);


        itr->second.convex.setFillColor(hexColor);
        itr->second.convex.setOutlineColor(outlineColor);
        itr->second.convex.setOutlineThickness(2);
        itr->second.convex.setOrigin(0, 0);
        itr->second.convex.setPosition(itr->first.toPixel(layout).x, itr->first.toPixel(layout).y);

        itr->second.circle.setOrigin(8, 8);
        itr->second.circle.setPosition({ itr->second.convex.getPosition().x * 2, itr->second.convex.getPosition().y * 2 });
        itr->second.circle.setFillColor({ 0, 0, 0, 0 });

        itr->second.convex.setPoint(0, sf::Vector2f(corners[0].x, corners[0].y));
        itr->second.convex.setPoint(1, sf::Vector2f(corners[1].x, corners[1].y));
        itr->second.convex.setPoint(2, sf::Vector2f(corners[2].x, corners[2].y));
        itr->second.convex.setPoint(3, sf::Vector2f(corners[3].x, corners[3].y));
        itr->second.convex.setPoint(4, sf::Vector2f(corners[4].x, corners[4].y));
        itr->second.convex.setPoint(5, sf::Vector2f(corners[5].x, corners[5].y));
    }
}

void Board::setHexagonalShape(int map_radius)
{
    HexImage image(sf::ConvexShape(6), sf::CircleShape(8));
    for (int q = -map_radius; q <= map_radius; q++)
    {
        int r1 = std::max(-map_radius, -q - map_radius);
        int r2 = std::min(map_radius, -q + map_radius);
        for (int r = r1; r <= r2; r++)
        {
            m_board.insert({Hex(q, r, -q - r), image});
        }
    }
}

void Board::draw(sf::RenderWindow &window)
{
    for (auto itr = m_board.begin(); itr != m_board.end(); ++itr)
    {
        window.draw(itr->second.convex);
        window.draw(itr->second.circle);
    }
}

void Board::setAllConvexColor(sf::Color color)
{
    for (auto itr2 = m_board.begin(); itr2 != m_board.end(); ++itr2)
    {
        itr2->second.convex.setFillColor(color);
    }
}

void Board::placeHex(std::unordered_map<Hex, HexImage>::iterator hex, Player& player, Player& enemy)
{
    std::vector<Hex> hxs = hex->first.range(1);
    for (auto itr = hxs.begin(); itr != hxs.end(); ++itr)
    {
        auto hx = m_board.find(*itr);
        if (hx != m_board.end() && hx->second.circle.getFillColor() == enemy.getColor())
        {
            hx->second.circle.setFillColor(player.getColor());

            player.addPoints(1);
            player.addToList(hx);
            enemy.extractPoints(1);
            enemy.removeFromList(hx);
        }

    }
}

void Board::showAvailableMoves(std::unordered_map<Hex, HexImage>::iterator hex)
{
    std::vector<Hex> hxs = hex->first.range(2);
    for (auto itr = hxs.begin(); itr != hxs.end(); ++itr)
    {
        auto hx = m_board.find(*itr);
        if (hx != m_board.end())
        {
            if (hx->first.distance(hex->first) <= 1)
            {
                hx->second.convex.setFillColor(sf::Color(156, 155, 122));
            }
            else
            {
                hx->second.convex.setFillColor(sf::Color(255, 211, 147));
            }

        }
    }
}
