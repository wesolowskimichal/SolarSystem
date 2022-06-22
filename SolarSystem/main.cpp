#include "constants.h"
#include "Planet.h"
#include <vector>
#include <iostream>
#include <SFML/System/Clock.hpp>
#include "Legend.h"

void updateWindow(sf::RenderWindow& window, std::vector<Planet*> _planets,  sf::Sprite bg, Legend* legend, float x1, float y1, float W) {
    window.clear();
    window.draw(bg);
    legend->showLegend(window, x1, y1, W);
    for (auto _p : _planets) {
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
    float WIDTH = 1920.f;
    float HEIGHT = 1080.f;
    float x1 = 0.f, y1 = 0.f;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Solar System");
    sf::Texture bgTexture;
    Legend* legend = new Legend();
    bgTexture.loadFromFile("Textures/galaxyTexture.jpg");
    bgTexture.setSmooth(true);
    bgTexture.setRepeated(true);
    sf::Sprite bg(bgTexture);
    bg.setTextureRect({ int(x1),int(y1),int(WIDTH),int(HEIGHT)});
    bool space = false;
    //initializing planets
    Planet* Sun = new Planet(0, 0, 1.989 * pow(10, 30), 80.f, "Textures/sunTexture.jpg");   //radius 696340
    Planet* Mercury = new Planet(0.39 * AU, 0, 0.33 * pow(10, 24), 4.8f, "Textures/mercuryTexture.jpg");
    Planet* Venus = new Planet(0.72 * AU, 0, 4.87 * pow(10, 24), 12.0f, "Textures/venusTexture.jpg");
    Planet* Earth = new Planet(1 * AU, 0, 5.97 * pow(10, 24), 12.8f, "Textures/earthTexture.jpg");
    Planet* Mars = new Planet(1.52 * AU, 0, 0.64 * pow(10, 24), 8.f, "Textures/marsTexture.jpg");
    Planet* Jupiter = new Planet(5.20 * AU, 0, 1898 * pow(10, 24), 140.f, "Textures/jupiterTexture.jpg");
    Planet* Saturn = new Planet(9.58 * AU, 0, 568 * pow(10, 24), 116.f, "Textures/saturnTexture.jpg");
    Planet* Uranus = new Planet(19.20 * AU, 0, 86.8 * pow(10, 24), 32.f, "Textures/uranusTexture.jpg");
    Planet* Neptune = new Planet(30.05 * AU, 0, 102 * pow(10, 24), 50.f, "Textures/neptuneTexture.jpg");
    Planet* Pluto = new Planet(39.48 * AU, 0, 0.013 * pow(10, 24), 2.4f, "Textures/plutoTexture.jpg");
    Mercury->setVY(-47400.f);
    Venus->setVY(-35000.f);
    Earth->setVY(-29800.f);
    Mars->setVY(-24100.f);
    Jupiter->setVY(-13100.f);
    Saturn->setVY(-9700.f);
    Uranus->setVY(-6800.f);
    Neptune->setVY(-5400.f);
    Pluto->setVY(-4700.f);
    std::vector<Planet*>Planets = { Sun, Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, Neptune, Pluto };
    //app
    sf::View view = window.getDefaultView();
    window.setView(view);
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Right) {
                    x1 += WIDTH / 8;
                    sf::FloatRect visibleArea(x1, y1, WIDTH, HEIGHT);
                    view = sf::View(visibleArea);
                    bg.setTextureRect({ int(x1),int(y1),int(WIDTH),int(HEIGHT) });
                    bg.setPosition(x1, y1);
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::Left) {
                    x1 -= WIDTH / 8;
                    sf::FloatRect visibleArea(x1, y1, WIDTH, HEIGHT);
                    view = sf::View(visibleArea);
                    bg.setTextureRect({ int(x1),int(y1),int(WIDTH),int(HEIGHT) });
                    bg.setPosition(x1, y1);
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::Up) {
                    y1 -= HEIGHT / 8;
                    sf::FloatRect visibleArea(x1, y1, WIDTH, HEIGHT);
                    view = sf::View(visibleArea);
                    bg.setTextureRect({ int(x1),int(y1),int(WIDTH),int(HEIGHT) });
                    bg.setPosition(x1, y1);
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::Down) {
                    y1 += HEIGHT / 8;
                    sf::FloatRect visibleArea(x1, y1, WIDTH, HEIGHT);
                    view = sf::View(visibleArea);
                    bg.setTextureRect({ int(x1),int(y1),int(WIDTH),int(HEIGHT) });
                    bg.setPosition(x1, y1);
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::F1)
                    TS /= 2;
                if (event.key.code == sf::Keyboard::F2)
                    TS *= 2;
                if (event.key.code == sf::Keyboard::Space) {
                    if (space) {
                        TS = 3600 * 24;
                        space = false;
                    }
                    else {
                        TS = 0;
                        space = true;
                    }
                }
                if (event.key.code == sf::Keyboard::Enter) {
                    x1 = 960.f - WIDTH / 2;
                    y1 = 540.f - HEIGHT / 2;
                    bg.setTextureRect({ int(x1),int(y1),int(WIDTH),int(HEIGHT) });
                    bg.setPosition(x1, y1);
                    sf::FloatRect visibleArea(x1, y1, WIDTH, HEIGHT);
                    view = sf::View(visibleArea);
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
                        bg.setTextureRect({ int(x1 + (xpos - sf::Mouse::getPosition().x)),int(y1 + (ypos - sf::Mouse::getPosition().y)),int(WIDTH),int(HEIGHT) });
                        bg.setPosition(x1 + (xpos - sf::Mouse::getPosition().x), y1 + (ypos - sf::Mouse::getPosition().y));
                        window.setView(view);

                        for (auto planet : Planets) {
                            planet->updatePos(Planets);
                            planet->movePlanet();
                            updateWindow(window, Planets, bg, legend, x1 + (xpos - sf::Mouse::getPosition().x), y1 + (ypos - sf::Mouse::getPosition().y), WIDTH);
                        }
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
                        bg.setTextureRect({ int(x1),int(y1),int(WIDTH),int(HEIGHT) });
                        bg.setPosition(x1, y1);
                        updateWindow(window, Planets, bg, legend, x1, y1, WIDTH);
                    }
                }
                if (event.mouseWheelScroll.delta < 0) {
                    WIDTH += 160;
                    HEIGHT += 90;
                    x1 -= 80;
                    y1 -= 45;
                    sf::FloatRect visibleArea(x1, y1, WIDTH, HEIGHT);
                    view = sf::View(visibleArea);
                    bg.setTextureRect({ int(x1),int(y1),int(WIDTH),int(HEIGHT) });
                    bg.setPosition(x1, y1);
                    updateWindow(window, Planets, bg, legend, x1, y1, WIDTH);
                }
                window.setView(view);
            }

        }
            for (auto planet : Planets) {
                planet->updatePos(Planets);
                planet->movePlanet();
                updateWindow(window, Planets, bg, legend, x1, y1, WIDTH);
            }
        
    }

    return 0;
}