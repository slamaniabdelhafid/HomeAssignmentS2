#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <SFML/Graphics.hpp>

class Instruction {
private:
    sf::Texture texture;
    sf::Sprite image;
    sf::Font font;
    sf::Text backButton;

public:
    Instruction();
    void draw(sf::RenderWindow& window);
    bool isBackPressed(sf::Vector2i mousePos);
};

#endif
