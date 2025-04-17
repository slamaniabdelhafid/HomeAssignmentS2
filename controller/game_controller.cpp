#include "game_controller.h"
#include <iostream>
#include "winpage.h"
// Constructeur
GameController::GameController(GameLogic& logic, Player& p1, Player& p2, GameView& view)
    : gameLogic(logic), player1(p1), player2(p2), gameView(view), gameState(true) {}

// Gère les événements de l'utilisateur
void GameController::handleEvent(sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        // Vérifier si une case a été cliquée
        int clickedCell = gameView.getClickedCell(mousePos);
        if (clickedCell != -1 && gameState) {
            int row = clickedCell / 3;
            int col = clickedCell % 3;

            // Vérifier si la case est vide
            if (gameLogic.getCell(row, col) == -1) {
                // Déterminer le joueur actuel
                int currentPlayer = (Player::getMoveCount() % 2 == 0) ? 1 : 2;
                gameLogic.getCell(row, col) = (currentPlayer == 1) ? 1 : 0;

                // Vérifier victoire
                if (gameLogic.checkLigne() || gameLogic.checkColonne()|| gameLogic.checkDiagonale()) {
                    if (currentPlayer == 1) {
                        player1.incrementScore();
                    } else {
                        player2.incrementScore();
                    }
                    gameState = false;
                }
                // Vérifier match nul
                else if (Player::getMoveCount() == 8) {
                    gameState = false;
                }

                Player::makeMove();
            }
        }
		std::vector<Button> buttons;
		
		// Vérifier si le bouton "New Game" a été cliqué
        if (gameView.getNewGameButton().contains(mousePos)) {
            gameLogic.resetMatrix(); 
            Player::resetMoves();    
            gameState = true;        
            for (auto& btn : buttons) {
                btn.setLabel("");    
            }
        }
    }
}

// Met à jour la vue en fonction de l'état du modèle
void GameController::updateView() {
    // Mettre à jour l'affichage du plateau
    std::vector<std::vector<char>> board(3, std::vector<char>(3, '-'));
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            int value = gameLogic.getCell(row, col);
            board[row][col] = (value == 1) ? 'X' : (value == 0) ? 'O' : '-';
        }
    }
    gameView.updateBoard(board);
}
void GameController::update() {
    if (!gameState) {
		
		 displayWinScreen();
		 gameView.getNewGameButton();
return ;  // Si le jeu est terminé, ne rien faire
}
    
    // Vérifier si c'est le tour de l'IA (player2)
    if (!player1.isMyTurn() && !player2.isHumanPlayer()) {
        player2.makeAIMove(gameLogic);
        
        // Vérifier victoire
        if (gameLogic.checkLigne() || gameLogic.checkColonne() || gameLogic.checkDiagonale()) {
            player2.incrementScore();
            gameState = false;
        }
        // Vérifier match nul
        else if (Player::getMoveCount() == 8) {
            gameState = false;
        }
    }
}