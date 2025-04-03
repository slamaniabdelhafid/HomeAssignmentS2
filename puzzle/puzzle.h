#ifndef PUZZLE_H
#define PUZZLE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <array>
#include <random>

class Puzzle {
public:
   Puzzle(sf::RenderWindow& mainWindow, const std::string& imageFile, const std::string& backgroundFile, int gridSize);
    void processEvent(const sf::Event& event);
    void update();
    void draw();
    bool isGameWon() const;
	bool isWin() const;      
private:
    struct Tile {
        int originalX, originalY;
        sf::Sprite sprite;
    };

    const int gridSize;
    sf::Texture texture;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::RenderWindow& window;
    std::vector<Tile> tiles;
    std::vector<std::vector<int>> grid;
    sf::Vector2i puzzlePosition;
    sf::Vector2i emptyPos;
    int tileWidth, tileHeight;
    std::mt19937 generator;
	bool gameWon = false;
    void initializeGrid(); 
    void shuffle();
    //bool isWin() const;
    void moveTile(int x, int y);
	//svoid draw(sf::RenderWindow& window);
};

#endif // PUZZLE_H
