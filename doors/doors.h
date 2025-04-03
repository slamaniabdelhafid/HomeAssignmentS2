#ifndef DOORS_H
#define DOORS_H

#include <SFML/Graphics.hpp>

class Doors {
private:
    sf::Texture texture;
    sf::Sprite image;
    sf::Font font;
    sf::Text buttonA;
	sf::Text buttonB;
	sf::Text buttonC;
	

public:
    Doors();
    void draw(sf::RenderWindow& window);
    bool isAPressed(sf::Vector2i mousePos);
	bool isBPressed(sf::Vector2i mousePos);
	bool isCPressed(sf::Vector2i mousePos);

};

#endif