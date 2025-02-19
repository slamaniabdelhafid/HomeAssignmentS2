#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int score;          // Score du joueur
    int playerNumber;   // Numéro du joueur (1 ou 2)
    char symbol;        // Symbole actuel (X/O)
    static int moveCount; // Compteur de mouvements global

public:
	static int getMoveCount();
    // Constructeur
    Player(int num) : playerNumber(num) {
        score = 0;
        updateSymbol(); // Initialise le symbole
    }

    // Met à jour le symbole basé sur le compteur de mouvements
    void updateSymbol() {
        /* Logique :
           - moveCount pair -> Joueur 1 (X)
           - moveCount impair -> Joueur 2 (O) */
        if(playerNumber == 1) {
            symbol = (moveCount % 2 == 0) ? 'X' : 'O';
        } else {
            symbol = (moveCount % 2 == 0) ? 'O' : 'X';
        }
    }

    // Vérifie si c'est le tour du joueur
    bool isMyTurn() const {
        return (moveCount % 2) == (playerNumber - 1);
    }

    // Fait un mouvement (incrémente le compteur)
    static void makeMove() {
        moveCount++;
    }

    // Getters
    int getScore() const { return score; }
    char getSymbol() const { return symbol; }
    int getPlayerNumber() const { return playerNumber; }

    // Incrémente le score
    void incrementScore() { score++; }

    // Réinitialise le compteur de mouvements
    static void resetMoves() { moveCount = 0; }
};

// Initialisation du membre statique
int Player::moveCount = 0; // Initialisation

int Player::getMoveCount() {
    return moveCount;
}

#endif // PLAYER_H