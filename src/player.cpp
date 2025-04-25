#include "player.h"
#include "game_logic.h"
#include <random> 
#include <thread>    // Pour std::this_thread
#include <chrono>    // Pour std::chrono
#include <iostream>
// Initialisation du membre statique
int Player::moveCount = 0;

// Constructeur
Player::Player(int num, bool human) : playerNumber(num), isHuman(human) {
    score = 0;
    updateSymbol();
}
bool Player::isHumanPlayer() const {
    return isHuman;
}
void Player::makeAIMove(GameLogic& gameLogic) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    
    if (gameLogic.isBoardFull()) return;

    auto bestMove = gameLogic.findBestMove();
    if (bestMove.first != -1) {
        gameLogic.getCell(bestMove.first, bestMove.second) = 0; // L'IA est O
        Player::makeMove();
    }
}
// Met à jour le symbole basé sur le compteur de mouvements
void Player::updateSymbol() {
    /* Logique :
       - moveCount pair -> Joueur 1 (X)
       - moveCount impair -> Joueur 2 (O) */
    if (playerNumber == 1) {
        symbol = (moveCount % 2 == 0) ? 'X' : 'O';
    } else {
        symbol = (moveCount % 2 == 0) ? 'O' : 'X';
    }
}

// Vérifie si c'est le tour du joueur
bool Player::isMyTurn() const {
    return (moveCount % 2) == (playerNumber - 1);
}

// Fait un mouvement (incrémente le compteur)
void Player::makeMove() {
			   std::cout << "move hafid: " << std::endl; // De
    moveCount++;
}

// Getters
int Player::getScore() const {
    return score;
}

char Player::getSymbol() const {
    return symbol;
}

int Player::getPlayerNumber() const {
    return playerNumber;
}

int Player::getMoveCount() {
    return moveCount;
}

// Incrémente le score
void Player::incrementScore() {
    score++;
}

// Réinitialise le compteur de mouvements
void Player::resetMoves() {
    moveCount = 0;
}
