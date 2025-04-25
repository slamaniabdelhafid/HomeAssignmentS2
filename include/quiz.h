#ifndef QUIZ_H
#define QUIZ_H

#include <SFML/Graphics.hpp>

class Quiz {
private:
    sf::Texture texture;
    sf::Sprite image;
    sf::Font font;
    sf::Text buttonA;
	sf::Text buttonB;
	sf::Text buttonC;
	sf::Text buttonD;
	

public:
    Quiz();
    void draw(sf::RenderWindow& window);
    bool isAPressed(sf::Vector2i mousePos);
	bool isBPressed(sf::Vector2i mousePos);
	bool isCPressed(sf::Vector2i mousePos);
	bool isDPressed(sf::Vector2i mousePos);
};

#endif
