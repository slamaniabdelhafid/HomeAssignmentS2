#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "bouton.h"

class GameView {
public:
    // Constructeur
    GameView(sf::Font& font);

    //l'interface graphique complète
    void draw(sf::RenderWindow& window);

    // 
    void updateBoard(const std::vector<std::vector<char>>& board);

    //une case spécifique a été cliquée
    int getClickedCell(const sf::Vector2i& mousePos) const;
	Button& getNewGameButton();

private:
    sf::Font& font; 
    std::vector<Button> buttons; 
	Button newGameButton;
	sf::Texture texture;
    sf::Sprite image;
};

#endif 
