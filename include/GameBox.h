#pragma once
#include <SFML/Graphics.hpp>

class GameBox {
private:
    sf::Sprite coverSprite;
    sf::Text numberText;
    bool isActive;
    int value;

public:
    GameBox(int num, sf::Font& font, sf::Vector2f position, sf::Texture& coverTexture);
    void draw(sf::RenderWindow& window);
    bool handleClick(sf::Vector2f mousePos, int expectedNumber);
    bool isStillActive() const;

    // Ajoutez cette déclaration
    void drawDebugBounds(sf::RenderWindow& window);
};
