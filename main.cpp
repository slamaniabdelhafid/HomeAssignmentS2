#include <SFML/Graphics.hpp>
#include "menu/menu.h"
#include "menu/instruction.h"
#include "menu/history.h"
#include "puzzle/puzzle.h" 

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 837), "Menu Navigation");
    Menu menu(1280, 837);
    sf::Texture bgImage;
    if (!bgImage.loadFromFile("assets/images/menu.jpg")) {
        // Gérer l'erreur si nécessaire
    }
    sf::Sprite bg(bgImage);

    Instruction instructionPage;
    History historyPage;

    bool isInMenu = true;
    bool isInInstruction = false;
    bool isInHistory = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (isInMenu) {
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Up) {
                        menu.Moveup();
                    } else if (event.key.code == sf::Keyboard::Down) {
                        menu.MoveDown();
                    } else if (event.key.code == sf::Keyboard::Enter) {
                        int selectedOption = menu.getSelected(); // Récupère l'option sélectionnée
                        switch (selectedOption) {
                            case 0: // Play
                                // Lancer le puzzle
                                isInMenu = false;
                                // Déclaration de puzzle dans le cas approprié
                               {
                                    Puzzle puzzle("assets/images/puzzle.jpg", 3); // Taille de grille 4x4
                                    puzzle.run(); // Lancement du puzzle (bloquant)
                                }
                                // Après fermeture du puzzle, on revient au menu
                                isInMenu = true;
                                break;
                            case 1: // History
                                isInMenu = false;
                                isInHistory = true;
                                break;
                            case 2: // Instruction
                                isInMenu = false;
                                isInInstruction = true;
                                break;
                            case 3: // Exit
                                window.close();
                                break;
                        }
                    }
                }
            } else if (isInInstruction) {
                if (event.type == sf::Event::MouseButtonPressed && 
                    event.mouseButton.button == sf::Mouse::Left) {
                    if (instructionPage.isBackPressed(
                        sf::Mouse::getPosition(window))) {
                        isInInstruction = false;
                        isInMenu = true;
                    }
                }
            } else if (isInHistory) {
                // Gestion de la page Historique
                if (event.type == sf::Event::MouseButtonPressed && 
                    event.mouseButton.button == sf::Mouse::Left) {
                    if (historyPage.isBackPressed(
                        sf::Mouse::getPosition(window))) {
                        isInHistory = false;
                        isInMenu = true;
                    }
                }
            }
        }

        window.clear();
        if (isInMenu) {
            window.draw(bg);
            menu.draw(window);
        } else if (isInInstruction) {
            instructionPage.draw(window);
        } else if (isInHistory) {
            historyPage.draw(window);
        }
        window.display();
    }

    return 0;
}