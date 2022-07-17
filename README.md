Simulation of the movement of planets in the solar system. The program is based on the SFML library.
The formula from Newton's law of gravitation was used to calculate the motion. Visualized is the Sun, 8
planets of the solar system and Pluto. The application is written object-oriented and is based on 3 classes:
- Planets - has a set of information about a planet:
  - x, y - position of the planet
  - M - mass of the planet
  - R - radius of the planet
  - xVel, yVel - velocity in the x and y plane of the planet
  - textureFile - file with the texture of the planet
  - texture - texture of the planet
  - _planet - shape of the planet
  - Constants - has variable and constant values:
  - TS - time step (Time Step)
  - G - gravitational constant
  - AU - fixed astronomical unit
  - SCALE - fixed scale in which the planets are displayed
- Legend - contains instructions on what you can do in the application

Description of class functions:

- Planet:
  - Planet(float x, float y, float M, float R, std::string texture) - class constructor,
initializes the specification of a given planet
  - float getX() - returns the position of the planet in the x-plane
  - float getY() - returns the position of the planet in the y plane
  - float getM() - returns the mass of the planet
  - float getR() - returns the planet's radius
  - sf::CircleShape getPlanet() - returns the shape variable of the planet
  - std::pair<float, float>a(Planet* p) - calculates the acceleration of the planet
  - void updatePos(std::vector<Planet*>planets) - updates planet variables
  - void movePlanet() - draws a planet on the screen
  - void setVY(float yVel) - sets the initial velocity of the planet in the y-plane
 - Legend:
  - Legend() - class constructor, sets default values of variables
  - Legend::showLegend(sf::RenderWindow& window, float x1, float y1, float W) -
displays instructions on the screen
