Symulacja ruchu planet w układzie słonecznym. Program opiera się na bibliotece SFML.
Do obliczania ruchu został użyty wzór z prawa grawitacji Newtona. Zwizualizowane jest Słońce, 8
planet układu słonecznego oraz Pluton. Aplikacja jest napisana obiektowo i opiera się na 3 klasach:
- Planet – posiada zestaw informacji o danej planecie:
  - x, y – pozycja planety
  - M – masa planety
  - R – promień planety
  - xVel, yVel – prędkość w płaszczyźnie x i y planety
  - textureFile – plik z teksturą planety
  - texture – tekstura planety
  - _planet – kształt planety
  - Constants – posiada zmienną oraz stałe wartości:
  - TS – krok czasowy (ang. Time Step)
  - G – stała grawitacyjna
  - AU – stała jednostka astronomiczna
  - SCALE – stała skala w jakiej planety są wyświetlane
- Legend – zawiera instrukcje co można zrobić w aplikacji

Opis funkcji klas:

- Planet:
  - Planet(float x, float y, float M, float R, std::string texture) – konstruktor klasy,
inicjalizujący specyfikację danej planety
  - float getX() – zwraca pozycję planety w płaszczyźnie x
  - float getY() – zwraca pozycję planety w płaszczyźnie y
  - float getM() – zwraca masę planety
  - float getR() – zwraca promień planety
  - sf::CircleShape getPlanet() – zwraca zmienną kształtu planety
  - std::pair<float, float>a(Planet* p) – oblicza akceleracje planety
  - void updatePos(std::vector<Planet*>planets) – aktualizuje zmienne planety
  - void movePlanet() – rysuje planetę na ekranie
  - void setVY(float yVel) – ustawia początkową prędkość planety w płaszczyźnie y
 - Legend:
  - Legend() – konstruktor klasy, ustawia wartości domyślne zmiennych
  - Legend::showLegend(sf::RenderWindow& window, float x1, float y1, float W) –
wyświetla instrukcje na ekranie
