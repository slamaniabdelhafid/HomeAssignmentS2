#include <SFML/Graphics.hpp>
#include <iostream>
#include "winpage.h"
void displayWinScreen() {
    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(1280, 837), "WIIIIIIIIIIIIN");

    // Chargement de la texture de fond
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("assets/images/win.png")) {
        std::cerr << "Erreur lors du chargement de l'image de fond !" << std::endl;
        return; // Arrêt de la fonction en cas d'erreur
    }

    // Création du sprite de fond
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    // Ajustement de l'échelle du sprite pour remplir la fenêtre
    backgroundSprite.setScale(
        static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x,
        static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y
    );

    // Boucle principale de la fenêtre
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Effacement et dessin
        window.clear();
        window.draw(backgroundSprite);
        window.display();
    }
}