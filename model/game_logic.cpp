#include "game_logic.h"


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