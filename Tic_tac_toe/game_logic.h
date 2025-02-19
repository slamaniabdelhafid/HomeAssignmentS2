#ifndef GAMELOGIC_H
#define GAMELOGIC_H

class GameLogic {
private:
    int matrix[3][3]; // Matrice 3x3

public:
    // Constructeur initialisant la matrice à -1
    GameLogic() {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                matrix[i][j] = -1;
            }
        }
    }

    // Vérifie les lignes gagnantes
    bool checkLigne() const {
        for(int i = 0; i < 3; i++) {
            if(matrix[i][0] != -1 && 
               matrix[i][0] == matrix[i][1] && 
               matrix[i][0] == matrix[i][2]) {
                return true;
            }
        }
        return false;
    }

    // Vérifie les colonnes gagnantes
    bool checkColonne() const {
        for(int j = 0; j < 3; j++) {
            if(matrix[0][j] != -1 && 
               matrix[0][j] == matrix[1][j] && 
               matrix[0][j] == matrix[2][j]) {
                return true;
            }
        }
        return false;
    }

    // Vérifie les diagonales gagnantes
    bool checkDiagonale() const {
        // Diagonale principale (haut-gauche à bas-droite)
        if(matrix[0][0] != -1 && 
           matrix[0][0] == matrix[1][1] && 
           matrix[0][0] == matrix[2][2]) {
            return true;
        }

        // Diagonale inverse (haut-droite à bas-gauche)
        if(matrix[0][2] != -1 && 
           matrix[0][2] == matrix[1][1] && 
           matrix[0][2] == matrix[2][0]) {
            return true;
        }

        return false;
    }

    // Méthode utilitaire pour accéder/modifier la matrice
    int& getCell(int row, int col) {
        return matrix[row][col];
    }

    // Méthode pour réinitialiser la matrice
    void resetMatrix() {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                matrix[i][j] = -1;
            }
        }
    }
};

#endif // GAMELOGIC_H