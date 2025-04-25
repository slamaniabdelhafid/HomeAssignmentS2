#ifndef HISTORY_H
#define HISTORY_H

#include <SFML/Graphics.hpp>

class History {
private:
    sf::Texture texture;
    sf::Sprite image;
    sf::Font font;
    sf::Text backButton;

public:
    History();
    void draw(sf::RenderWindow& window);
    bool isBackPressed(sf::Vector2i mousePos);
};

#endif
