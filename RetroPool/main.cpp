#include <SFML/Graphics.hpp>
#include <iostream>
#include "RanderMap.h"
#include "Player.h"
#include "SimpleFollow.h"
#define PLAYER_SPEED 60
int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Coffie's game!");
    Player MC, chicken;
    RanderMap Map;
    SimpleFollow Dist;
    Map.LoadMap();
    MC.SetRect(0, 0, 64, 64);
    chicken.SetRect(0, 0, 32, 32);
    int Spritenum;
    Spritenum = 0;
    bool SpritStanding = false;
    sf::Clock dt;
    sf::Time ConvertDT;
    float DeltaTime = 0;
    float playerspeed = 0;
    sf::View view(sf::Vector2f(0, 0), sf::Vector2f(1200, 800));
    MC.SetPos(3000, 2800);
    chicken.SetPos(MC.PlayerCords().x - 32, MC.PlayerCords().y);
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
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            MC.SpriteMovemnet(3, Spritenum, 0,64);
           // chicken.SpriteMovemnet(2, Spritenum, 64,32);
            MC.Movement(0, playerspeed);
            SpritStanding = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            MC.SpriteMovemnet(3, Spritenum, 64,64);
           // chicken.SpriteMovemnet(2, Spritenum, 96,32);
            MC.Movement(-playerspeed, 0);
            SpritStanding = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            MC.SpriteMovemnet(3, Spritenum, 128,64);
            //chicken.SpriteMovemnet(2, Spritenum, 32,32);
            MC.Movement(playerspeed, 0);
            SpritStanding = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            MC.SpriteMovemnet(3, Spritenum, 192,64);
            //chicken.SpriteMovemnet(2, Spritenum, 0,32);
            MC.Movement(0, -playerspeed);
            SpritStanding = false;
        }
        if (SpritStanding) 
        {
            MC.stillSpriteUpdate();
            Spritenum = 0;
        }
        SpritStanding = true;

        Dist.FollowMaster(MC, chicken,playerspeed);

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