﻿#include "Planet.h"
#include <vector>
#include <iostream>
//#include "Array.h"
#define WIDTH 1920.f
#define HEIGHT 1080.f

int main()
{

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Solar System");
    sf::Vertex lines[] = {
        sf::Vertex(sf::Vector2f(0, HEIGHT / 2.f)),
        sf::Vertex(sf::Vector2f(WIDTH, HEIGHT / 2.f)),
        sf::Vertex(sf::Vector2f(WIDTH / 2.f,0)),
        sf::Vertex(sf::Vector2f(WIDTH / 2.f,HEIGHT*100))
    };
    Planet* Sun = new Planet(0, 0, 1.989 * pow(10, 30), 16.f, 1, 240, 10, 50);   //radius 696340
    Planet* Mercury = new Planet(0.39*Sun->AU, 0, 1, 6.f, 0, 0, 255, 0);
    Planet* Venus = new Planet(0.72 * Sun->AU, 0, 1, 6.f, 0, 0, 255, 0);
    Planet* Earth = new Planet(1 * Sun->AU, 0, 1, 6.f, 0, 0, 255, 0);
    Planet* Mars = new Planet(1.52 * Sun->AU, 0, 1, 6.f, 0, 0, 255, 0);
    Planet* Jupiter = new Planet(5.20 * Sun->AU, 0, 1, 6.f, 0, 0, 255, 0);
    Planet* Saturn = new Planet(9.58 * Sun->AU, 0, 1, 6.f, 0, 0, 255, 0);
    Planet* Uranus = new Planet(19.20 * Sun->AU, 0, 1, 6.f, 0, 0, 255, 0);
    Planet* Neptune = new Planet(30.05 * Sun->AU, 0, 1, 6.f, 0, 0, 255, 0);
    Planet* Pluto = new Planet(39.48 * Sun->AU, 0, 1, 6.f, 0, 255, 0, 0);

    std::vector<Planet*> Planets = { Sun, Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, Neptune, Pluto };
    std::vector<sf::CircleShape> _planets;
    for (auto P : Planets)
        _planets.push_back(P->create());
    //sf::CircleShape _sun = sun->create();
    
    float x1 = 0.f, y1 = 0.f;
    sf::View view = window.getDefaultView();
    window.setView(view);
    float mPosX{}, mPosY{};
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized)
            {
                //sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
                //view.setViewport(sf::FloatRect(abs(x1-event.size.width), abs(y1-event.size.height), event.size.width, event.size.height));
                view.setViewport(sf::FloatRect(0.f, 0.f, event.size.width, event.size.height));
                window.setView(view);
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                mPosX = sf::Mouse::getPosition(window).x;
                mPosY = sf::Mouse::getPosition(window).y;
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                float mPosXN = sf::Mouse::getPosition(window).x;
                float mPosYN = sf::Mouse::getPosition(window).y;
                view.move(mPosX + (mPosX - mPosXN), mPosY + (mPosY - mPosYN));
                window.setView(view);
            }
            if (event.type == sf::Event::MouseWheelScrolled)
            {
                if (event.mouseWheelScroll.delta > 0)
                    view.zoom(0.5);
                if (event.mouseWheelScroll.delta < 0)
                    view.zoom(-0.5);
                window.setView(view);
            }
        }
        window.clear();
        window.draw(lines, 4, sf::Lines);
        for (auto _p : _planets)
            window.draw(_p);
        window.display();
    }

    return 0;
}