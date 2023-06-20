#include <SFML/Graphics.hpp>
#include <iostream>
#include "RanderMap.h"
#include "Player.h"
#define PLAYER_SPEED 60
int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Coffie's game!");
    Player MC, chicken;
    RanderMap Map;
    Map.LoadMap();
    MC.SetRect(0, 0, 64, 64);
    chicken.SetRect(0, 0, 32, 32);
    int S, A, D, W;
    S = A = D = W = 0;
    sf::Clock dt;
    sf::Time ConvertDT;
    float DeltaTime = 0;
    float playerspeed = 0;
    sf::View view(sf::Vector2f(0, 0), sf::Vector2f(1200, 800));
    MC.SetPos(3000, 2800);
    if (MC.setTexture("assets/player_set.png"))
    {
        std::cout << "fiald to load" << std::endl;
    }
    if (chicken.setTexture("assets/chicken_set.png"))
    {
        std::cout << "fiald to load" << std::endl;
    }
    while (window.isOpen())
    {
        ConvertDT = dt.restart();
        DeltaTime = ConvertDT.asSeconds();
        playerspeed = PLAYER_SPEED * DeltaTime;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            MC.SpriteMovemnet(3, S, 0,64);
            chicken.SpriteMovemnet(2, S, 64,32);
            MC.Movement(0, playerspeed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            MC.SpriteMovemnet(3, A, 64,64);
            chicken.SpriteMovemnet(2, A, 96,32);
            MC.Movement(-playerspeed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            MC.SpriteMovemnet(3, A, 128,64);
            chicken.SpriteMovemnet(2, A, 32,32);
            MC.Movement(playerspeed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            MC.SpriteMovemnet(3, A, 192,64);
            chicken.SpriteMovemnet(2, A, 0,32);
            MC.Movement(0, -playerspeed);
        }

        chicken.SetPos(MC.PlayerCords().x - 32, MC.PlayerCords().y);
        view.setCenter(MC.PlayerCords());
        window.setView(view);

        window.clear();
        Map.DrawMap(window);
        MC.drawplayer(window);
        chicken.drawplayer(window);
        window.display();
    }

    return 0;
}