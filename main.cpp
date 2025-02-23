#include <SFML/Graphics.hpp>
#include "model/game_logic.h"
#include "model/player.h"
#include "view/game_view.h"
#include "controller/game_controller.h"
#include <iostream>

int main() {
    // Créer la fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(500, 500), "Tic Tac Toe");
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf")) {
        std::cout << "Erreur lors du chargement de la police." << std::endl;
        return -1;
    }

    GameLogic gameLogic;
    Player player1(1);
    Player player2(2);
    GameView gameView(font);
    GameController gameController(gameLogic, player1, player2, gameView);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Gérer les événements via le contrôleur
            gameController.handleEvent(event, window);
        }

        // Mettre à jour la vue
        gameController.updateView();

        // Dessiner l'interface graphique
        window.clear(sf::Color(0x2B0040FF)); // Couleur de fond
        gameView.draw(window);
        window.display();
    }

    return 0;
}