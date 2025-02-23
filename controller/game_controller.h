#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "game_logic.h"
#include "player.h"
#include "game_view.h"

class GameController {
public:
    // Constructeur
    GameController(GameLogic& logic, Player& player1, Player& player2, GameView& view);

    
    void handleEvent(sf::Event& event, sf::RenderWindow& window);

   
    void updateView();

private:
    GameLogic& gameLogic; 
    Player& player1;      
    Player& player2;      
    GameView& gameView;   
    bool gameState;       
};

#endif 