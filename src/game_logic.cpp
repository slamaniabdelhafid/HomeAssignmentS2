#include "game_logic.h"
#include <algorithm>  // Pour std::max et std::min
#include <climits> 

GameLogic::GameLogic() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = -1;
        }
    }
}

// Vérifie les ligns gagnantes
bool GameLogic::checkLigne() const {
    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] != -1 &&
            matrix[i][0] == matrix[i][1] &&
            matrix[i][0] == matrix[i][2]) {
            return true;
        }
    }
    return false;
}

// Vérifie les colonnes gagnantes
bool GameLogic::checkColonne() const {
    for (int j = 0; j < 3; j++) {
        if (matrix[0][j] != -1 &&
            matrix[0][j] == matrix[1][j] &&
            matrix[0][j] == matrix[2][j]) {
            return true;
        }
    }
    return false;
}

// Vérifie les diagonales gagnantes
bool GameLogic::checkDiagonale() const {
    // Diagonale principale (haut-gauche à bas-droite)
    if (matrix[0][0] != -1 &&
        matrix[0][0] == matrix[1][1] &&
        matrix[0][0] == matrix[2][2]) {
        return true;
    }
    // Diagonale inverse (haut-droite à bas-gauche)
    if (matrix[0][2] != -1 &&
        matrix[0][2] == matrix[1][1] &&
        matrix[0][2] == matrix[2][0]) {
        return true;
    }
    return false;
}

// Méthode utilitaire pour accéder/modifier la matrice
int& GameLogic::getCell(int row, int col) {
    return matrix[row][col];
}

// Méthode pour réinitialiser la matrice
void GameLogic::resetMatrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = -1;
        }
    }
	
}
bool GameLogic::isBoardFull() const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == -1) return false;
        }
    }
    return true;
}

std::vector<std::pair<int, int>> GameLogic::getEmptyCells() const {
    std::vector<std::pair<int, int>> emptyCells;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == -1) {
                emptyCells.emplace_back(i, j);
            }
        }
    }
    return emptyCells;
}

int GameLogic::evaluateBoard() const {
    // Vérifier toutes les lignes
    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] != -1 && matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2]) {
            return matrix[i][0] == 0 ? 10 : 10;
        }
    }

    // Vérifier toutes les colonnes
    for (int j = 0; j < 3; j++) {
        if (matrix[0][j] != -1 && matrix[0][j] == matrix[1][j] && matrix[0][j] == matrix[2][j]) {
            return matrix[0][j] == 0 ? 10 : 10;
        }
    }

    // Vérifier les diagonales
    if (matrix[0][0] != -1 && matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2]) {
        return matrix[0][0] == 0 ? 10 : -10;
    }
    if (matrix[0][2] != -1 && matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0]) {
        return matrix[0][2] == 0 ? 10 : -10;
    }

    return 0; // Match nul
}
int GameLogic::minimax(int depth, bool isMaximizing) {
    int score = evaluateBoard();
    
    // Si quelqu'un a gagné
    if (score == 10) return score - depth;
    if (score == -10) return score + depth;
    
    // Match nul
    if (isBoardFull()) return 0;

    if (isMaximizing) { // Tour de l'IA (maximise)
        int best = -1000;
        for (const auto& cell : getEmptyCells()) {
            matrix[cell.first][cell.second] = 0;
            best = std::max(best, minimax(depth+1, false));
            matrix[cell.first][cell.second] = -1;
        }
        return best;
    } else { // Tour du joueur (minimise)
        int best = 1000;
        for (const auto& cell : getEmptyCells()) {
            matrix[cell.first][cell.second] = 1;
            best = std::min(best, minimax(depth+1, true));
            matrix[cell.first][cell.second] = -1;
        }
        return best;
    }
}

std::pair<int, int> GameLogic::findBestMove() {
    int bestVal = -1000;
    std::pair<int, int> bestMove = {-1, -1};

    // L'IA est le joueur 0 (O)
    for (const auto& cell : getEmptyCells()) {
        // Essayer ce coup
        matrix[cell.first][cell.second] = 0;
        
        // Évaluer le coup
        int moveVal = minimax(0, false);
        
        // Annuler le coup
        matrix[cell.first][cell.second] = -1;
        
        // Trouver le meilleur coup
        if (moveVal > bestVal) {
            bestMove = cell;
            bestVal = moveVal;
        }
    }
    
    return bestMove;
}

