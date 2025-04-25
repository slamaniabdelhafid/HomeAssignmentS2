#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameBox.h"

class NumberGame {
private:
    sf::Texture coverTexture;
    std::vector<GameBox> boxes; // Déclaration de 'boxes'
    std::vector<int> targetNumbers; // Déclaration de 'targetNumbers'
    sf::Font font; // Déclaration de 'font'
    int currentTarget;

public:
    NumberGame();
    void handleInput(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    bool isGameWon() const;
};
