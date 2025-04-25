#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <vector>    // Ajout pour std::vector
#include <utility>   // Ajout pour std::pair
#include <array>     // Ajout pour std::array

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
	bool isBoardFull() const;
    std::vector<std::pair<int, int>> getEmptyCells() const;
    int evaluateBoard() const;
    int minimax(int depth, bool isMaximizing);
    std::pair<int, int> findBestMove();
};

#endif 
