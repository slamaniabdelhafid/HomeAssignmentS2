#include "history.h"
#include <iostream>

History::History() {
    // Charger l'image
    if (!texture.loadFromFile("assets/images/history.jpg")) {
        std::cerr << "Failed to load history image!\n";
    }
    image.setTexture(texture);
      

    
    if (!font.loadFromFile("assets/fonts/Gamtex.ttf")) {
        std::cerr << "Failed to load font!\n";
    }

    // Configurer le bouton "Retour"
    backButton.setFont(font);
    backButton.setString("Back");
    backButton.setCharacterSize(30);
    backButton.setFillColor(sf::Color::Yellow);
    backButton.setPosition(1170, 740);
}

void History::draw(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);
    window.draw(image);
    window.draw(backButton);
    window.display();
}

bool History::isBackPressed(sf::Vector2i mousePos) {
    return backButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

