#include "GameBox.h"
#include <iostream>
GameBox::GameBox(int num, sf::Font& font, sf::Vector2f position, sf::Texture& coverTexture)
    : isActive(true), value(num) {
    coverSprite.setTexture(coverTexture);
    coverSprite.setPosition(position);
    coverSprite.setScale(80.0f / coverTexture.getSize().x, 80.0f / coverTexture.getSize().y);

    numberText.setString(std::to_string(num));
    numberText.setFont(font);
    numberText.setCharacterSize(24);
    numberText.setFillColor(sf::Color::Red);
    numberText.setPosition(position.x, position.y);
}

void GameBox::draw(sf::RenderWindow& window) {
    if (isActive) {
        window.draw(coverSprite);
    }
}

bool GameBox::handleClick(sf::Vector2f mousePos, int expectedNumber) {
	 std::cout << "Clic détecté sur  " << mousePos.x<<std::endl;
    if (isActive && coverSprite.getGlobalBounds().contains(mousePos)) {
		  std::cout << "Clic détecté sur la boîte " << value << std::endl;
        if (value == expectedNumber) {
            isActive = false; // Désactiver la boîte
            return true;      // Clic valide
        }
    }
    return false; // Clic invalide
}

bool GameBox::isStillActive() const {
    return isActive;
}

// Implémentation de drawDebugBounds
void GameBox::drawDebugBounds(sf::RenderWindow& window) {
    sf::FloatRect bounds = coverSprite.getGlobalBounds();
    sf::RectangleShape debugRect(sf::Vector2f(bounds.width, bounds.height));
    debugRect.setPosition(bounds.left, bounds.top);
    debugRect.setFillColor(sf::Color::Transparent);
    debugRect.setOutlineColor(sf::Color::Red);
    debugRect.setOutlineThickness(1);
    window.draw(debugRect);
}
