#ifndef PUZZLE_H
#define PUZZLE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <array>
#include <random>

class Puzzle {
public:
    Puzzle(const std::string& imageFile, int gridSize);
    void run();

private:
    struct Tile {
        int originalX, originalY;
        sf::Sprite sprite;
    };

    const int gridSize;
    sf::Texture texture;
    sf::RenderWindow window;
    std::vector<Tile> tiles;
    std::array<std::array<int, 4>, 4> grid; // Position des tuiles (0 = vide)
    sf::Vector2i emptyPos;
    std::mt19937 generator;

    void initializeGrid();
    void shuffle();
    bool isWin() const;
    void moveTile(int x, int y);
};

#endif // PUZZLE_H