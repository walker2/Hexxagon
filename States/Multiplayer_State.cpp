#include "Multiplayer_State.h"
#include <iostream>

void Multiplayer_State::init(int screenWidth, int screenHeight, ResourceManager* resourceManager)
{
    m_board = new Board();
    m_player1 = new Player(sf::Color(52, 152, 219), 1, "PLAYER 1");

    if (m_isAIgame)
    {
        m_player2 = new Player(sf::Color(231, 76, 60), 1, "AI");
        m_player2->setToAI();
    }
    else
    {
        m_player2 = new Player(sf::Color(231, 76, 60), 1, "PLAYER 2");
    }


    m_shouldSwitch = GameStates::NONE;
    m_turn = 0;
    m_isGameOver = false;

    m_board->init(3, sf::Color(236, 240, 241), sf::Color::Black, m_layout);

    Hex h1(1, 1, -2);
    Hex h2(-1, -1, 2);
    auto player1Hex = m_board->getBoard().find(h1);
    auto player2Hex= m_board->getBoard().find(h2);

    if (player1Hex != m_board->getBoard().end())
    {
        player1Hex->second.circle.setFillColor(m_player1->getColor());
        m_player1->addToList(player1Hex);
    }

    if (player2Hex != m_board->getBoard().end())
    {
        player2Hex->second.circle.setFillColor(m_player2->getColor());
        m_player2->addToList(player2Hex);

    }
    m_labels[0].setColor(m_player1->getColor());
    m_labels[1].setColor(m_player1->getColor());
    m_labels[2].setColor(m_player2->getColor());
    m_labels[3].setColor(sf::Color::Transparent);

    m_labels[0].setString("1");
    m_labels[1].setString(m_player1->getName() + " TURN");
    m_labels[2].setString("1");
    m_labels[3].setString("FFFFFFFFFFFFFFFFFFFFFF");

    m_font = resourceManager->getFont("media/fonts/roboto_black.ttf");//.loadFromFile("media/fonts/roboto_black.ttf");
    for (int i = 0; i < 4; ++i)
    {
        m_labels[i].setFont(m_font);
        m_labels[i].setCharacterSize(32);
        sf::FloatRect rect = m_labels[i].getLocalBounds();
        m_labels[i].setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
    }

    m_labels[0].setPosition(sf::Vector2f(50.0f, 25.0f));
    m_labels[1].setPosition(sf::Vector2f(400.0f, 25.0f));
    m_labels[2].setPosition(sf::Vector2f(750.0f, 25.0f));
    m_labels[3].setPosition(sf::Vector2f(400.0f, 500.0f));

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
                if (event.mouseButton.button == sf::Mouse::Button::Left)
                {
                    makeMove(window);
                }
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Space && m_isGameOver)
                {
                    next();
                }
                break;
        }
    }
}

void Multiplayer_State::update(const sf::Time &time)
{

}

void Multiplayer_State::draw(sf::RenderWindow &window)
{
    for (auto &hex : m_board->getBoard())
    {
        window.draw(hex.second.convex);
        window.draw(hex.second.circle);
    }
    for (int i = 0; i < 4; ++i)
    {
        window.draw(m_labels[i]);
    }
}

GameStates Multiplayer_State::shouldSwitch()
{
    return m_shouldSwitch;
}

void Multiplayer_State::next()
{

    delete m_board;
    delete m_player1;
    delete m_player2;
    m_shouldSwitch = GameStates::INTRO;
}

void Multiplayer_State::makeMove(sf::RenderWindow &window)
{
    if (!m_turn)
    {
        if (handleMove(*m_player1, *m_player2, window))
        {
            setGUIAfterMove(*m_player2, *m_player1);
        }
        if (isGameOver(*m_player2))
        {
            setGUIAfterGameOver(*m_player2, *m_player1);
        }
    }
    else
    {
        if (handleMove(*m_player2, *m_player1, window))
        {
            setGUIAfterMove(*m_player1, *m_player2);
        }
        if (isGameOver(*m_player1))
        {
            setGUIAfterGameOver(*m_player1, *m_player2);
        }
    }
}

bool Multiplayer_State::handleMove(Player &player, Player &enemy, sf::RenderWindow &window)
{
    if(player.isAI())
    {
        handleAIMove(player, enemy);
        return true;
    }

    sf::Vector2i localPosition = sf::Mouse::getPosition(window);

    auto hx = m_board->getBoard().find(pixel_to_hex(m_layout, sf::Vector2f(localPosition.x, localPosition.y)));
    if (hx != m_board->getBoard().end())
    {
        if (hx->second.convex.getFillColor() == sf::Color(156, 155, 122) && hx->second.circle.getFillColor() == sf::Color::Transparent)
        {
            hx->second.circle.setFillColor(player.getColor());

            player.addPoints(1);
            player.addToList(hx);

            m_board->setAllConvexColor(sf::Color(236, 240, 241));
            m_board->placeHex(hx, player, enemy);
            return true;
        }
        else if (hx->second.convex.getFillColor() == sf::Color(255, 211, 147) && hx->second.circle.getFillColor() == sf::Color::Transparent)
        {
            m_prevHex->second.circle.setFillColor(sf::Color::Transparent);
            hx->second.circle.setFillColor(player.getColor());

            player.removeFromList(m_prevHex);
            player.addToList(hx);

            m_board->setAllConvexColor(sf::Color(236, 240, 241));
            m_board->placeHex(hx, player, enemy);
            return true;
        }
        m_board->setAllConvexColor(sf::Color(236, 240, 241));

        if (hx->second.circle.getFillColor() != player.getColor())
        {
            return false;
        }
        else
        {
            m_board->showAvailableMoves(hx);
            m_prevHex = hx;
        }
    }
    return false;
}

bool Multiplayer_State::isGameOver(Player &player)
{
    if (player.getPoints() == 0)
        return true;

    for (auto elem : player.getList())
    {
        std::vector<Hex> hxs = elem->first.range(2);
        for (auto itr = hxs.begin(); itr != hxs.end(); ++itr)
        {
            auto hex = m_board->getBoard().find(*itr);
            if (hex != m_board->getBoard().end())
            {
                if (hex->second.circle.getFillColor() == sf::Color::Transparent)
                    return false;
            }
        }
    }
    return true;
}

void Multiplayer_State::setGUIAfterMove(Player& player, Player& enemy)
{
    m_turn = !m_turn;

    m_labels[0].setString(std::to_string(player.getPoints()));
    m_labels[1].setString(player.getName() + " TURN");
    m_labels[1].setColor(player.getColor());
    m_labels[2].setString(std::to_string(enemy.getPoints()));
}

void Multiplayer_State::setGUIAfterGameOver(Player& player, Player& enemy)
{
    if (player.getPoints() < enemy.getPoints() + (m_boardSize * 12  - (enemy.getPoints() + player.getPoints())))
    {
        m_labels[1].setString(enemy.getName() + " WINS");
    }
    else
    {
        m_labels[1].setString(player.getName() + " WINS");
    }
    m_labels[3].setColor(sf::Color::White);
    m_labels[3].setString("Press SPACE to start again");
    m_isGameOver = true;
}

void Multiplayer_State::handleAIMove(Player &player, Player &enemy)
{
    std::vector<Move> moves;
    Move aiMove = getBestAIMove(player, enemy, 3, Move(-10000), Move(10000));

    if(aiMove.score == -10000)
    {
        aiMove = getBestAIMove(player, enemy, 1, Move(-10000), Move(10000));
    }


    aiMove.it->second.circle.setFillColor(player.getColor());
    if (aiMove.isJump)
    {
        aiMove.prev_it->second.circle.setFillColor(sf::Color::Transparent);
        player.extractPoints(1);
        player.removeFromList(aiMove.prev_it);
    }
    player.addPoints(1);
    player.addToList(aiMove.it);

    std::vector<Hex> hexs = aiMove.it->first.range(1);
    for (auto itr = hexs.begin(); itr != hexs.end(); ++itr)
    {
        auto hhx = m_board->getBoard().find(*itr);
        if (hhx != m_board->getBoard().end() && hhx->second.circle.getFillColor() == enemy.getColor())
        {
            hhx->second.circle.setFillColor(player.getColor());

            player.addPoints(1);
            player.addToList(hhx);
            enemy.extractPoints(1);
            enemy.removeFromList(hhx);
        }

    }
    std::cout << "BEST AI MOVE WITH SCORE " << aiMove.score;
}

Move Multiplayer_State::getBestAIMove(Player &player, Player &enemy, int depth, Move alpha, Move beta)
{
    if (depth == 0)
    {
        if (player.isAI())
        {
            return Move(-10 * (m_player1->getPoints() - m_player2->getPoints()));
        }
        else
        {
            return Move(10 * (m_player1->getPoints() - m_player2->getPoints()));
        }
    }

    Move max(-10000);
    auto list = player.getList();

    for (auto elem : list)
    {
        std::vector<Hex> hxs = elem->first.range(2);
        for (auto itr = hxs.begin(); itr != hxs.end(); ++itr)
        {
            auto hex = m_board->getBoard().find(*itr);
            if (hex != m_board->getBoard().end()) {
                if (hex->second.circle.getFillColor() == sf::Color::Transparent)
                {
                    Move move(0);

                    if (hex->first.distance(elem->first) > 1)
                    {
                        player.extractPoints(1);
                        player.removeFromList(elem);
                        move.prev_it = elem;
                        move.isJump = true;
                    }

                    hex->second.circle.setFillColor(player.getColor());
                    player.addPoints(1);
                    player.addToList(hex);
                    std::vector<Hex> hexs = hex->first.range(1);
                    std::vector<std::unordered_map<Hex, HexImage>::iterator> used_hexes;
                    for (auto itr1 = hexs.begin(); itr1 != hexs.end(); ++itr1)
                    {
                        auto hes = m_board->getBoard().find(*itr1);
                        if (hes != m_board->getBoard().end() && hes->second.circle.getFillColor() == enemy.getColor())
                        {
                            hes->second.circle.setFillColor(player.getColor());

                            player.addPoints(1);
                            player.addToList(hes);
                            enemy.extractPoints(1);
                            enemy.removeFromList(hes);
                            used_hexes.push_back(hes);
                        }
                    }

                    Move minus_alpha = alpha;
                    minus_alpha.score = - minus_alpha.score;
                    Move minus_beta = beta;
                    minus_beta.score = - minus_beta.score;


                    move.it = hex;
                    move.score = - getBestAIMove(enemy, player, depth - 1, minus_beta, minus_alpha).score;

                    if(move.score > max.score)
                    {
                        max = move;
                    }
                    hex->second.circle.setFillColor(sf::Color::Transparent);
                    player.extractPoints(1);
                    player.removeFromList(hex);

                    for (auto u_hex : used_hexes)
                    {
                        u_hex->second.circle.setFillColor(enemy.getColor());

                        enemy.addPoints(1);
                        enemy.addToList(u_hex);
                        player.extractPoints(1);
                        player.removeFromList(u_hex);
                    }
                    if (hex->first.distance(elem->first) > 1)
                    {
                        player.addPoints(1);
                        player.addToList(elem);
                    }
                    if (move.score > alpha.score)
                        alpha = move;

                    if (alpha.score >= beta.score)
                        return alpha;

                }
            }
        }
    }
    return max;
}
