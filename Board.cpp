#include "Board.h"
#include "States/Multiplayer_State.h"

void Board::init(int size, Player& player1, Player& player2)
{
    setHexagonalShape(size);
    Hex h1(size, 0, -size);
    Hex h2(-size, 0, size);

    auto player1Hex = m_board.find(h1);
    auto player2Hex= m_board.find(h2);

    if (player1Hex != m_board.end())
    {
        player1Hex->second.attachedToPlayer = player1.getPlayerType();
        player1.addToList(player1Hex);
    }

    if (player2Hex != m_board.end())
    {
        player2Hex->second.attachedToPlayer = player2.getPlayerType();
        player2.addToList(player2Hex);
    }
}

void Board::setHexagonalShape(int map_radius)
{
    HexInfo info;
    for (int q = -map_radius; q <= map_radius; q++)
    {
        int r1 = std::max(-map_radius, -q - map_radius);
        int r2 = std::min(map_radius, -q + map_radius);
        for (int r = r1; r <= r2; r++)
        {
            m_board.insert({Hex(q, r, -q - r), info});
        }
    }
}

void Board::setAllHexesToFree()
{
    for (auto itr2 = m_board.begin(); itr2 != m_board.end(); ++itr2)
    {
        itr2->second.inRangeOne = false;
        itr2->second.inRangeTwo = false;
    }
}

void Board::placeHex(std::unordered_map<Hex, HexInfo>::iterator hex, Player& player, Player& enemy)
{
    std::vector<Hex> hxs = hex->first.range(1);
    for (auto itr = hxs.begin(); itr != hxs.end(); ++itr)
    {
        auto hx = m_board.find(*itr);
        if (hx != m_board.end() && hx->second.attachedToPlayer == enemy.getPlayerType())
        {
            hx->second.attachedToPlayer = player.getPlayerType();
            player.addPoints(1);
            player.addToList(hx);

            enemy.extractPoints(1);
            enemy.removeFromList(hx);
        }

    }
}

void Board::showAvailableMoves(std::unordered_map<Hex, HexInfo>::iterator hex)
{
    std::vector<Hex> hxs = hex->first.range(2);
    for (auto itr = hxs.begin(); itr != hxs.end(); ++itr)
    {
        auto hx = m_board.find(*itr);
        if (hx != m_board.end())
        {
            if (hx->first.distance(hex->first) <= 1)
            {
                hx->second.inRangeOne = true;
            }
            else
            {
                hx->second.inRangeTwo = true;
            }

        }
    }
}
