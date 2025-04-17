#include "NumberGame.h"
#include <algorithm> 
#include <numeric>   
#include <random>    


NumberGame::NumberGame() : currentTarget(1) {
    if (!font.loadFromFile("arial.ttf")) {
       
    }

    if (!coverTexture.loadFromFile("assets/images/pz.jpg")) {
       
    }

    // Créer 16 boîtes mélangées
    std::vector<int> numbers(5);
    std::iota(numbers.begin(), numbers.end(), 1);
    std::shuffle(numbers.begin(), numbers.end(), std::mt19937(std::random_device()()));

    // Disposition en 3 colonnes
    for (int i = 0; i < 5; ++i) {
        float x = 50 + (i % 3) * 120; 
        float y = 50 + (i / 3) * 120; 
        boxes.emplace_back(numbers[i], font, sf::Vector2f(x, y), coverTexture);
    }
}

void NumberGame::draw(sf::RenderWindow& window) {
    // Dessiner les boîtes et leurs limites
    for (auto& box : boxes) {
        box.draw(window);
        box.drawDebugBounds(window); // Afficher les limites pour le débogage
    }

    // Dessiner le tableau de résultats
    for (size_t i = 0; i < targetNumbers.size(); ++i) {
        sf::Text t(std::to_string(targetNumbers[i]), font, 30);
        t.setPosition(600 + (i % 3) * 50, 100 + (i / 3) * 50); // 3 colonnes
        t.setFillColor(sf::Color::Green);
        window.draw(t);
    }
}

void NumberGame::handleInput(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            for (auto& box : boxes) {
                if (box.handleClick(mousePos, currentTarget)) {
                    targetNumbers.push_back(currentTarget); // Ajouter au tableau de résultats
                    currentTarget++; // Passer au numéro suivant
                }
            }
        }
    }
}
bool NumberGame::isGameWon() const {
    return currentTarget > 16;
}