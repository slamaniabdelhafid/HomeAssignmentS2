#include "game_view.h"
#include <iostream>

float buttonSize = 90.f;
float spacing = 15.f;
float startX = (1300 - (3*buttonSize + 2*spacing)) / 2;
float startY = 300.f;
sf::Color bleu(0x48D2FEFF);
sf::Color jaune(0xE2BE00FF);
Button& GameView::getNewGameButton() {
    return newGameButton;
}
// Constructeur
 
GameView::GameView(sf::Font& font) : font(font), 

newGameButton(
          sf::Vector2f(300.f, 50.f),         
          sf::Vector2f(490, 220.f),        
          sf::Color::White,                  
          []() {},                           
          "New Game",                        
          font                               
      ){
    //les boutons pour chaque case du plateau (3x3)
	if (!texture.loadFromFile("assets/images/last.png")) {
        std::cerr << "Failed to load instruction image!\n";
    }
    image.setTexture(texture);
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
           sf::Vector2f position(
                startX + col * (buttonSize + spacing),
                startY + row * (buttonSize + spacing)
				);
            sf::Vector2f size( 70.f, 70.f); // Taille de chaque bouton
            sf::Color color(0x43115BFF);

            // Créer un bouton vide avec une action par défaut (vide pour l'instant)
            Button button(
                size, position, color,
                []() {}, // Action vide (sera gérée par le contrôleur)
                "", font
            );

            buttons.push_back(button);
        }
    }
	newGameButton.setTextSize(20);

}
//l'interface graphique complète
void GameView::draw(sf::RenderWindow& window) {
	  window.draw(image);
    for (auto& button : buttons) {
        button.draw(window);
    }
	newGameButton.draw(window);
}

// Met à jour l'état visuel du plateau en fonction de la matrice du modèle
void GameView::updateBoard(const std::vector<std::vector<char>>& board) {
    int index = 0;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            char cellValue = board[row][col];
            if (cellValue == 'X' || cellValue == 'O') {
                buttons[index].setLabel(std::string(1, cellValue)); // Mettre à jour le texte du bouton
				buttons[index].setLabelColor(cellValue == 'X' ?sf::Color(bleu):sf::Color(jaune));
            } else {
                buttons[index].setLabel(""); // Effacer le texte si la case est vide
            }
            ++index;
        }
    }
}

// Vérifie si une case spécifique a été cliquée
int GameView::getClickedCell(const sf::Vector2i& mousePos) const {
    for (size_t i = 0; i < buttons.size(); ++i) {
        if (buttons[i].contains(mousePos)) {
            return static_cast<int>(i); 
        }
    }
    return -1; 
}
