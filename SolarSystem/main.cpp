#include <SFML/Graphics.hpp>
#define WIDTH 1920.f
#define HEIGHT 1080.f

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Solar System");
    sf::Vertex lines[] = {
        sf::Vertex(sf::Vector2f(0, HEIGHT / 2.f)),
        sf::Vertex(sf::Vector2f(WIDTH, HEIGHT / 2.f)),
        sf::Vertex(sf::Vector2f(WIDTH / 2.f,0)),
        sf::Vertex(sf::Vector2f(WIDTH / 2.f,HEIGHT))
    };
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(lines, 4, sf::Lines);
        window.display();
    }

    return 0;
}