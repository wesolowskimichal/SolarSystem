#include "Planet.h"
#include <vector>
#include <iostream>
#include <SFML/System/Clock.hpp>
//#include "Array.h"
#define WIDTH 1920.f
#define HEIGHT 1080.f

int updateX(sf::RenderWindow& window) {
    return sf::Mouse::getPosition(window).x;
}

int updateY(sf::RenderWindow& window) {
    return sf::Mouse::getPosition(window).y;
}

void updateWindow(sf::RenderWindow& window, std::vector<sf::CircleShape> _planets) {
    window.clear();
    for (auto _p : _planets)
        window.draw(_p);
    window.display();
}

bool moving(float x1, float x2, float y1, float y2) {
    if (x1 != x2 && y1 != y2)
        return true;
    return false;

}

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Solar System");
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
    sf::View view = window.getDefaultView();
    window.setView(view);
    float x1 = 0.f, y1 = 0.f, x2 = WIDTH, y2 = HEIGHT;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            /*if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }*/
            
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Right) {
                    view.move(event.size.width / 4, 0);
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::Left) {
                    float newxPos = event.size.width / 4;
                    view.move(-newxPos, 0);
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::Up) {
                    float newyPos = event.size.height / 4;
                    view.move(0, -newyPos);
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::Down) {
                    view.move(0, event.size.height / 4);
                    window.setView(view);
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                float xpos = sf::Mouse::getPosition().x;
                float ypos = sf::Mouse::getPosition().y;
                sf::View tempView = view;
                while (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseMoved) {
                    if (moving(xpos, sf::Mouse::getPosition().x, ypos, sf::Mouse::getPosition().y)) {
                        sf::FloatRect visibleArea(x1+(xpos - sf::Mouse::getPosition().x), y1+ (ypos - sf::Mouse::getPosition().y), x2+(xpos - sf::Mouse::getPosition().x), y2+ (ypos - sf::Mouse::getPosition().y));
                        tempView = sf::View(visibleArea);
                        window.setView(sf::View(visibleArea));
                        
                    }
                    updateWindow(window, _planets);
                    window.pollEvent(event);
                }
                x1 += (xpos - sf::Mouse::getPosition().x);
                y1 += (ypos - sf::Mouse::getPosition().y);
                x2 += (xpos - sf::Mouse::getPosition().x);
                y2 += (ypos - sf::Mouse::getPosition().y);
                view = tempView;
            }
            
            if (event.type == sf::Event::MouseWheelScrolled)
            {
                if (event.mouseWheelScroll.delta > 0)
                    view.zoom(0.5);
                if (event.mouseWheelScroll.delta < 0)
                    view.zoom(1.5);
                window.setView(view);
            }
        }
        updateWindow(window, _planets);
    }

    return 0;
}