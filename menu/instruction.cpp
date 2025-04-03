#include "instruction.h"
#include <iostream>

Instruction::Instruction() {
    // Charger l'image
    if (!texture.loadFromFile("assets/images/instruction.jpg")) {
        std::cerr << "Failed to load instruction image!\n";
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

void Instruction::draw(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);
    window.draw(image);
    window.draw(backButton);
    window.display();
}

bool Instruction::isBackPressed(sf::Vector2i mousePos) {
    return backButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}