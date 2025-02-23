#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int score;          // Score du joueur
    int playerNumber;   // Numéro du joueur (1 ou 2)
    char symbol;        // Symbole actuel (X/O)
    static int moveCount; // Compteur de mouvements global

public:
    // Constructeur
    Player(int num);

    // Met à jour le symbole basé sur le compteur de mouvements
    void updateSymbol();

    // Vérifie si c'est le tour du joueur
    bool isMyTurn() const;

    // Fait un mouvement (incrémente le compteur)
    static void makeMove();

    // Getters
    int getScore() const;
    char getSymbol() const;
    int getPlayerNumber() const;
    static int getMoveCount();

    // Incrémente le score
    void incrementScore();

    // Réinitialise le compteur de mouvements
    static void resetMoves();
};

#endif 