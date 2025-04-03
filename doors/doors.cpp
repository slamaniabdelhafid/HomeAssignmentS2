#include "doors.h"
#include <iostream>

Doors::Doors() {
    // Charger l'image
    if (!texture.loadFromFile("assets/images/doors.png")) {
        std::cerr << "Failed to load instruction image!\n";
    }
    image.setTexture(texture);
      

    
    if (!font.loadFromFile("assets/fonts/Gamtex.ttf")) {
        std::cerr << "Failed to load font!\n";
    }

    // Configurer le bouton "Retour"
    buttonA.setFont(font);
    buttonA.setString("A");
    buttonA.setCharacterSize(30);
    buttonA.setFillColor(sf::Color::Yellow);
    buttonA.setPosition(330, 705);
	
	 // Configurer le bouton "Retour"
    buttonB.setFont(font);
    buttonB.setString("B");
    buttonB.setCharacterSize(30);
    buttonB.setFillColor(sf::Color::Yellow);
    buttonB.setPosition(630, 705);
	
	 // Configurer le bouton "Retour"
    buttonC.setFont(font);
    buttonC.setString("C");
    buttonC.setCharacterSize(30);
    buttonC.setFillColor(sf::Color::Yellow);
    buttonC.setPosition(930, 705);
	
}

void Doors::draw(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);
    window.draw(image);
    window.draw(buttonA);
	window.draw(buttonB);
	window.draw(buttonC);
    window.display();
}

bool Doors::isAPressed(sf::Vector2i mousePos) {
	std::cout << "A instruction image!\n";
    return buttonA.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}
bool Doors::isBPressed(sf::Vector2i mousePos) {
	std::cout << "B instruction image!\n";
    return buttonB.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

bool Doors::isCPressed(sf::Vector2i mousePos) {
	std::cout << "c instruction image!\n";
    return buttonC.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

