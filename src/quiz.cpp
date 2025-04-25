#include "quiz.h"
#include <iostream>

Quiz::Quiz() {
    // Charger l'image
    if (!texture.loadFromFile("assets/images/quiz.png")) {
        std::cerr << "Failed to load instruction image!\n";
    }
    image.setTexture(texture);
      

    
    if (!font.loadFromFile("assets/fonts/Gamtex.ttf")) {
        std::cerr << "Failed to load font!\n";
    }

    // Configurer le bouton "Retour"
    buttonA.setFont(font);
    buttonA.setString("Collecting\ngold");
    buttonA.setCharacterSize(30);
    buttonA.setFillColor(sf::Color::Black);
    buttonA.setPosition(425, 465);
	
	 // Configurer le bouton "Retour"
    buttonB.setFont(font);
    buttonB.setString("Building a \ngreat pyramid");
    buttonB.setCharacterSize(30);
    buttonB.setFillColor(sf::Color::Black);
    buttonB.setPosition(675, 465);
	
	 // Configurer le bouton "Retour"
    buttonC.setFont(font);
    buttonC.setString("death");
    buttonC.setCharacterSize(30);
    buttonC.setFillColor(sf::Color::Black);
    buttonC.setPosition(450, 625);
	
	 // Configurer le bouton "Retour"
    buttonD.setFont(font);
    buttonD.setString("Hard working");
    buttonD.setCharacterSize(30);
    buttonD.setFillColor(sf::Color::Black);
    buttonD.setPosition(680, 625);
}

void Quiz::draw(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);
    window.draw(image);
    window.draw(buttonA);
	window.draw(buttonB);
	window.draw(buttonC);
	window.draw(buttonD);
    window.display();
}

bool Quiz::isAPressed(sf::Vector2i mousePos) {
	std::cout << "A instruction image!\n";
    return buttonA.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}
bool Quiz::isBPressed(sf::Vector2i mousePos) {
	std::cout << "B instruction image!\n";
    return buttonB.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

bool Quiz::isCPressed(sf::Vector2i mousePos) {
	std::cout << "c instruction image!\n";
    return buttonC.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

bool Quiz::isDPressed(sf::Vector2i mousePos) {
	std::cout << "D instruction image!\n";
    return buttonD.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}
