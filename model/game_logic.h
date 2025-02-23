#ifndef GAMELOGIC_H
#define GAMELOGIC_H

class GameLogic {
private:
    int matrix[3][3]; 

public:
    // Constructeur initialisant la matrice à -1
    GameLogic();

    // Vérifie les lignes gagnantes
    bool checkLigne() const;
    bool checkColonne() const;
    bool checkDiagonale() const;

    int& getCell(int row, int col);

    // Méthode pour réinitialiser la matrice
    void resetMatrix();
};

#endif 