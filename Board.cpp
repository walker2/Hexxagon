#include <chrono>
#include <iostream>
#include "Board.h"
#include "States/Multiplayer_State.h"

void Board::init(int size, Player& player1, Player& player2)
{
    setHexagonalShape(size);
    Hex h1(-size, 0, size);
    Hex h2(size, 0, -size);

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

    m_selectedHex = player1Hex;
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

bool Board::handleMove(Player &player, Player &enemy, sf::Vector2i localPosition, Layout layout)
{
    auto hx = m_board.find(pixel_to_hex(layout, sf::Vector2f(localPosition.x, localPosition.y)));
    if (localPosition == sf::Vector2i(-1, -1))
    {
        hx = m_selectedHex;
    }

    if (hx != m_board.end())
    {
        m_selectedHex = hx;
        if (hx->second.inRangeOne && hx->second.attachedToPlayer == HexInfo::PlayerType::NONE)
        {
            hx->second.attachedToPlayer = player.getPlayerType();

            player.addPoints(1);
            player.addToList(hx);

            setAllHexesToFree();
            placeHex(hx, player, enemy);
            return true;
        }
        else if (hx->second.inRangeTwo && hx->second.attachedToPlayer == HexInfo::PlayerType::NONE)
        {
            m_prevHex->second.attachedToPlayer = HexInfo::PlayerType::NONE;
            hx->second.attachedToPlayer = player.getPlayerType();

            player.removeFromList(m_prevHex);
            player.addToList(hx);

            setAllHexesToFree();
            placeHex(hx, player, enemy);
            return true;
        }
        setAllHexesToFree();

        if (hx->second.attachedToPlayer != player.getPlayerType())
        {
            return false;
        }
        else
        {
            showAvailableMoves(hx);
            m_prevHex = hx;
        }
    }
    return false;
}

bool Board::isGameOver(Player &player)
{
    if (player.getPoints() == 0)
        return true;

    for (auto elem : player.getList())
    {
        std::vector<Hex> hxs = elem->first.range(2);
        for (auto itr = hxs.begin(); itr != hxs.end(); ++itr)
        {
            auto hex = m_board.find(*itr);
            if (hex != m_board.end())
            {
                if (hex->second.attachedToPlayer == HexInfo::PlayerType::NONE)
                    return false;
            }
        }
    }
    return true;
}

void Board::handleAIMove(Player &player, Player &enemy)
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();



    Move aiMove;
    aiMove = getBestAIMove(player, enemy, player.getDifficulty(), Move(-10000), Move(10000), player.getPoints());

    if(aiMove.score == -10000)
    {
        aiMove = getBestAIMove(player, enemy, 1, Move(-10000), Move(10000), player.getPoints());
    }


    aiMove.it->second.attachedToPlayer = player.getPlayerType();
    if (aiMove.isJump)
    {
        aiMove.prev_it->second.attachedToPlayer = HexInfo::PlayerType::NONE;
        player.extractPoints(1);
        player.removeFromList(aiMove.prev_it);
    }
    player.addPoints(1);
    player.addToList(aiMove.it);

    placeHex(aiMove.it, player, enemy);
    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
}

Move Board::getBestAIMove(Player &player, Player &enemy, int depth, Move alpha, Move beta, int startPoints)
{
    if (depth == 0)
    {
        //return Move(10 * (player.getPoints() - startPoints));
        return Move(player.getPoints() - enemy.getPoints());
    }

    //Create Move with minimal score
    Move max(-10000);
    auto list = player.getList();
    //For every element in player element list
    for (auto elem : list)
    {
        //Take range of 2 around the current element and form vector of Hex objects
        std::vector<Hex> hxs = elem->first.range(2);
        for (auto itr = hxs.begin(); itr != hxs.end(); ++itr)
        {
            //Find the objects in board
            auto hex = m_board.find(*itr);
            if (hex != m_board.end())
            {

                //Check if we can go to the this hex
                if (hex->second.attachedToPlayer == HexInfo::PlayerType::NONE)
                {
                    //Create empty move
                    Move move(0);

                    //If distance between element in players list and current hex better than 1
                    if (hex->first.distance(elem->first) > 1)
                    {
                        //It was jump, extracting points and removing element from players list
                        player.extractPoints(1);
                        player.removeFromList(elem);
                        move.prev_it = elem;
                        move.isJump = true;
                    }

                    //Set current hex to players list
                    hex->second.attachedToPlayer = player.getPlayerType();
                    player.addPoints(1);
                    player.addToList(hex);

                    //After placing hex on board we should turn other hexes in range of 1 to players color
                    std::vector<Hex> hexs = hex->first.range(1);
                    std::vector<std::unordered_map<Hex, HexInfo>::iterator> used_hexes;

                    //Iterating through all adjacent hexes
                    for (auto itr1 = hexs.begin(); itr1 != hexs.end(); ++itr1)
                    {
                        auto hes = m_board.find(*itr1);
                        //Check if hex is belongs to the enemy
                        if (hes != m_board.end() && hes->second.attachedToPlayer == enemy.getPlayerType())
                        {
                            //Take all hexes around
                            hes->second.attachedToPlayer = player.getPlayerType();
                            player.addPoints(1);
                            player.addToList(hes);
                            enemy.extractPoints(1);
                            enemy.removeFromList(hes);
                            used_hexes.push_back(hes);
                        }
                    }

                    //Compute minus alpha and minus beta moves
                    Move minus_alpha = alpha;
                    minus_alpha.score = - minus_alpha.score;
                    Move minus_beta = beta;
                    minus_beta.score = - minus_beta.score;


                    move.it = hex;
                    //Set current move score by starting recursion
                    move.score = - getBestAIMove(enemy, player, depth - 1, minus_beta, minus_alpha, startPoints).score;

                    //Maximize from all children nodes
                    if (move.score > max.score)
                    {
                        max = move;
                    }

                    if (max.score == move.score && max.isJump && !move.isJump)
                    {
                        max = move;
                    }


                    //Return the board to it's previous state
                    hex->second.attachedToPlayer = HexInfo::PlayerType::NONE;
                    player.extractPoints(1);
                    player.removeFromList(hex);

                    //Iterate through list of used_hexes in this turn setting them all to previous state
                    for (auto u_hex : used_hexes)
                    {
                        u_hex->second.attachedToPlayer = enemy.getPlayerType();
                        enemy.addPoints(1);
                        enemy.addToList(u_hex);
                        player.extractPoints(1);
                        player.removeFromList(u_hex);
                    }

                    //Check if there was a jump and set all to normal
                    if (hex->first.distance(elem->first) > 1)
                    {
                        player.addPoints(1);
                        player.addToList(elem);
                    }

                    //Check if score of current move is better than score of alpha move
                    if (move.score > alpha.score)
                        alpha = move;

                    //Check if score of alpha move is better or equal to beta move score and return alpha
                    if (alpha.score > beta.score)
                        return alpha;

                }
            }
        }
    }
    return max;
}

void Board::selectRightHex()
{
    auto hex = m_board.find(Hex(m_selectedHex->first.q + 1, m_selectedHex->first.r, m_selectedHex->first.s - 1));
    if (hex != m_board.end())
    {
        m_selectedHex = hex;
    }
}

void Board::selectLeftHex()
{
    auto hex = m_board.find(Hex(m_selectedHex->first.q - 1, m_selectedHex->first.r, m_selectedHex->first.s + 1));
    if (hex != m_board.end())
    {
        m_selectedHex = hex;
    }
}

void Board::selectUpHex()
{
    auto hex = m_board.find(Hex(m_selectedHex->first.q + 1, m_selectedHex->first.r - 1, m_selectedHex->first.s));
    if (hex != m_board.end())
    {
        m_selectedHex = hex;
    }
}

void Board::selectDownHex()
{
    auto hex = m_board.find(Hex(m_selectedHex->first.q - 1, m_selectedHex->first.r + 1, m_selectedHex->first.s));
    if (hex != m_board.end())
    {
        m_selectedHex = hex;
    }
}

