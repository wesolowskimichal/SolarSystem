#include "Planet.h"
#include "Moon.h"
#include <vector>
#include <iostream>
#include <SFML/System/Clock.hpp>

float WIDTH = 1920.f;
float HEIGHT = 1080.f;

void updateWindow(sf::RenderWindow& window, std::vector<Planet*> _planets) {
    window.clear();
    for (auto _p : _planets) {
        //_p->setTrail();
        //_p->drawTrail(window);
        window.draw(_p->getPlanet());   
    }
    window.display();
}


bool moving(float x1, float x2, float y1, float y2) {
    if (x1 != x2 && y1 != y2)
        return true;
    return false;

}


int main()
{
    //initializing window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Solar System");


    //initializing planets
    Planet* Sun = new Planet(0, 0, 1.989 * pow(10, 30), 80.f, "sunTexture.jpg");   //radius 696340
    Planet* Mercury = new Planet(0.39 * Sun->AU, 0, 0.33 * pow(10, 24), 4.8f, "mercuryTexture.jpg");
    Planet* Venus = new Planet(0.72 * Sun->AU, 0, 4.87 * pow(10, 24), 12.0f, "venusTexture.jpg");
    Planet* Earth = new Planet(1 * Sun->AU, 0, 5.97 * pow(10, 24), 12.8f, "earthTexture.jpg");
    Planet* Mars = new Planet(1.52 * Sun->AU, 0, 0.64 * pow(10, 24), 8.f, "marsTexture.jpg");
    Planet* Jupiter = new Planet(5.20 * Sun->AU, 0, 1898 * pow(10, 24), 140.f, "jupiterTexture.jpg");
    Planet* Saturn = new Planet(9.58 * Sun->AU, 0, 568 * pow(10, 24), 116.f, "saturnTexture.jpg");
    Planet* Uranus = new Planet(19.20 * Sun->AU, 0, 86.8 * pow(10, 24), 32.f, "uranusTexture.jpg");
    Planet* Neptune = new Planet(30.05 * Sun->AU, 0, 102 * pow(10, 24), 50.f, "neptuneTexture.jpg");
    Planet* Pluto = new Planet(39.48 * Sun->AU, 0, 0.013 * pow(10, 24), 2.4f, "plutoTexture.jpg");
    Moon* e = new Moon(0.00256955529, 0, 7.34767309 * pow(10, 22), 2.4f, "moonTexture.jpg", Earth);
    Mercury->setVY(47400.f);
    Venus->setVY(35000.f);
    Earth->setVY(29800.f);
    Mars->setVY(24100.f);
    Jupiter->setVY(13100.f);
    Saturn->setVY(9700.f);
    Uranus->setVY(6800.f);
    Neptune->setVY(5400.f);
    Pluto->setVY(4700.f);
    std::vector<Planet*>Planets = { Sun, Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, Neptune, Pluto };
    //app
    sf::View view = window.getDefaultView();
    window.setView(view);
    float x1 = 0.f, y1 = 0.f;
    sf::Clock clock;
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
                while (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseMoved) {
                    if (moving(xpos, sf::Mouse::getPosition().x, ypos, sf::Mouse::getPosition().y)) {
                        sf::FloatRect visibleArea(x1+(xpos - sf::Mouse::getPosition().x), y1+(ypos - sf::Mouse::getPosition().y), WIDTH, HEIGHT);
                        view = sf::View(visibleArea);
                        window.setView(view);
                        for (auto planet : Planets) {
                            planet->updatePos(Planets);
                            planet->movePlanet();
                            updateWindow(window, Planets);
                        }
                    }
                    for (auto planet : Planets) {
                        planet->updatePos(Planets);
                        planet->movePlanet();
                        updateWindow(window, Planets);
                    }
                    window.pollEvent(event);
                }
                x1 += (xpos - sf::Mouse::getPosition().x);
                y1 += (ypos - sf::Mouse::getPosition().y);
            }
            
            if (event.type == sf::Event::MouseWheelScrolled)
            {
                if (event.mouseWheelScroll.delta > 0) {
                    if (WIDTH - 160 > 0 && HEIGHT - 90 > 0) {
                        WIDTH -= 160;
                        HEIGHT -= 90;
                        x1 += 80;
                        y1 += 45;
                        sf::FloatRect visibleArea(x1, y1, WIDTH, HEIGHT);
                        view = sf::View(visibleArea);
                        updateWindow(window, Planets);
                    }
                }
                if (event.mouseWheelScroll.delta < 0) {
                    WIDTH += 160;
                    HEIGHT += 90;
                    x1 -= 80;
                    y1 -= 45;
                    sf::FloatRect visibleArea(x1, y1, WIDTH, HEIGHT);
                    view = sf::View(visibleArea);
                    updateWindow(window, Planets);
                }
                window.setView(view);
            }

        }
        //sf::Time elapsed = clock.getElapsedTime();
        //if(elapsed.asMicroseconds()>1.f) {
            //clock.restart();
            //std::cout << Planets[1]->getX() << '\t' << Planets[1]->getY() << '\n';
            //movePlanets(Planets);
           // std::cout << Planets[1]->getX() << '\t' << Planets[1]->getY() << "\n\n";
            for (auto planet : Planets) {
                planet->updatePos(Planets);
                planet->movePlanet();
                updateWindow(window, Planets);
            }
            //std::cout << "\n\n";

            //clock.restart();
        //}
        
    }

    return 0;
}