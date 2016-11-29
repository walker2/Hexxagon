#include "Multiplayer_State.h"
#include <iostream>

#define PL1CLR sf::Color(52, 152, 219)
#define PL2CLR sf::Color(231, 76, 60)

void Multiplayer_State::init(int screenWidth, int screenHeight, ResourceManager* resourceManager)
{
    m_board = new Board();
    m_gameGUI = new GameGUI();

    m_player1 = new Player(HexInfo::PlayerType::PLAYER1, 1, "PLAYER 1", 1);

    if (m_isAIgame)
    {
        m_player2 = new Player(HexInfo::PlayerType::PLAYER2, 1, "AI", 1);
        m_player2->setToAI();
    }
    else
    {
        m_player2 = new Player(HexInfo::PlayerType::PLAYER2, 1, "PLAYER 2", 0);
    }


    m_shouldSwitch = GameStates::NONE;
    m_turn = 0;
    m_isGameOver = false;

    m_board->init(3, *m_player1, *m_player2);
    sf::Color color1 = PL1CLR;
    sf::Color color2 = PL2CLR;
    m_gameGUI->createLabel("1", "media/fonts/roboto_black.ttf", color1, resourceManager, {50.0f, 25.0f}, 48);
    m_gameGUI->createLabel(m_player1->getName() + " TURN", "media/fonts/roboto_black.ttf", color1, resourceManager, {400.0f, 25.0f}, 32);
    m_gameGUI->createLabel("1", "media/fonts/roboto_black.ttf", color2, resourceManager, {750.0f, 25.0f}, 48);
    m_gameGUI->createLabel("FFFFFFFFFFFFFFFFF", "media/fonts/roboto_black.ttf", sf::Color::Transparent, resourceManager, {400.0f, 500.0f}, 24);
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
        if (isGameOver(*m_player1))
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
        if (isGameOver(*m_player2))
        {
            setGUIAfterGameOver();
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
        if (hx->second.inRangeOne && hx->second.attachedToPlayer == HexInfo::PlayerType::NONE)
        {
            hx->second.attachedToPlayer = player.getPlayerType();//.circle.setFillColor(player.getColor());

            player.addPoints(1);
            player.addToList(hx);

            m_board->setAllHexesToFree();
            m_board->placeHex(hx, player, enemy);
            return true;
        }
        else if (hx->second.inRangeTwo && hx->second.attachedToPlayer == HexInfo::PlayerType::NONE)
        {
            m_prevHex->second.attachedToPlayer = HexInfo::PlayerType::NONE;
            hx->second.attachedToPlayer = player.getPlayerType();

            player.removeFromList(m_prevHex);
            player.addToList(hx);

            m_board->setAllHexesToFree();
            m_board->placeHex(hx, player, enemy);
            return true;
        }
        m_board->setAllHexesToFree();

        if (hx->second.attachedToPlayer != player.getPlayerType())
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
                if (hex->second.attachedToPlayer == HexInfo::PlayerType::NONE)
                    return false;
            }
        }
    }
    return true;
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

    if (m_player1->getPoints() < m_player2->getPoints() + (m_boardSize * 12  - (m_player2->getPoints() + m_player1->getPoints())))
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

void Multiplayer_State::handleAIMove(Player &player, Player &enemy)
{
    std::vector<Move> moves;
    Move aiMove;
    if(player.getName() == "PLAYER 1")
    {
        aiMove = getBestAIMove(player, enemy, 3, Move(-10000), Move(10000), player.getPoints());
    }
    else
    {
        aiMove = getBestAIMove(player, enemy, 3, Move(-10000), Move(10000), player.getPoints());
    }

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

    m_board->placeHex(aiMove.it, player, enemy);
}

Move Multiplayer_State::getBestAIMove(Player &player, Player &enemy, int depth, Move alpha, Move beta, int startPoints)
{
    if (depth == 0)
    {
        return Move(10 * (player.getPoints() - startPoints));
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
            auto hex = m_board->getBoard().find(*itr);
            if (hex != m_board->getBoard().end())
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
                        auto hes = m_board->getBoard().find(*itr1);
                        //Check if hex is belongs to the enemy
                        if (hes != m_board->getBoard().end() && hes->second.attachedToPlayer == enemy.getPlayerType())
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

