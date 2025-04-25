#include "puzzle.h"
#include <iostream>

Puzzle::Puzzle(sf::RenderWindow& mainWindow, const std::string& imageFile, const std::string& backgroundFile, int gridSize)
    : window(mainWindow), gridSize(gridSize), generator(std::random_device()()){
    if (!texture.loadFromFile(imageFile)) {
        std::cerr << "Erreur de chargement de l'image\n";
        exit(EXIT_FAILURE);
    }

    if (!backgroundTexture.loadFromFile(backgroundFile)) {
        std::cerr << "Erreur de chargement du fond\n";
        exit(EXIT_FAILURE);
    }

    // Dimensions fixes de la fenêtre
    const int windowWidth = 1280;
    const int windowHeight = 837;
    window.create(
        sf::VideoMode(windowWidth, windowHeight),
        "Puzzle"
    );
    window.setFramerateLimit(60);

    // Positionnement du puzzle au centre
    int puzzleWidth = texture.getSize().x;
    int puzzleHeight = texture.getSize().y;
    puzzlePosition.x = (windowWidth - puzzleWidth) / 2;
    puzzlePosition.y = (windowHeight - puzzleHeight) / 2+50;

    // Initialisation du fond
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(
        static_cast<float>(windowWidth) / backgroundTexture.getSize().x,
        static_cast<float>(windowHeight) / backgroundTexture.getSize().y
    );

    initializeGrid();
    shuffle();
}

void Puzzle::initializeGrid() {
    tileWidth = texture.getSize().x / gridSize;
    tileHeight = texture.getSize().y / gridSize;

    grid.resize(gridSize, std::vector<int>(gridSize));
    tiles.clear();

    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            Tile tile;
            tile.originalX = x;
            tile.originalY = y;
            tile.sprite.setTexture(texture);
            tile.sprite.setTextureRect(
                sf::IntRect(x * tileWidth, y * tileHeight, tileWidth, tileHeight)
            );
            // Position avec décalage pour centrer le puzzle
            tile.sprite.setPosition(
                puzzlePosition.x + x * tileWidth,
                puzzlePosition.y + y * tileHeight
            );
            tiles.push_back(tile);

            grid[y][x] = tiles.size() - 1; // Index de la tuile
        }
    }

    // Position vide en bas à droite
    emptyPos = {gridSize - 1, gridSize - 1};
    grid[emptyPos.y][emptyPos.x] = -1;
}

void Puzzle::shuffle() {
	
    std::uniform_int_distribution<int> dirDist(0, 3);
    for (int i = 0; i < 1000; ++i) {
        int dx = 0, dy = 0;
        switch (dirDist(generator)) {
            case 0: dx = -1; break; // Gauche
            case 1: dx = 1; break; // Droite
            case 2: dy = -1; break; // Haut
            case 3: dy = 1; break; // Bas
        }

        int newX = emptyPos.x + dx;
        int newY = emptyPos.y + dy;
        if (newX >= 0 && newX < gridSize && newY >= 0 && newY < gridSize) {
            if (grid[newY][newX] != -1) {
                int tileIndex = grid[newY][newX];
                grid[newY][newX] = -1;
                grid[emptyPos.y][emptyPos.x] = tileIndex;

                // Mettre à jour la position de la tuile avec décalage
                tiles[tileIndex].sprite.setPosition(
                    puzzlePosition.x + emptyPos.x * tileWidth,
                    puzzlePosition.y + emptyPos.y * tileHeight
                );emptyPos = {newX, newY};
            }
        }
    }
}

bool Puzzle::isWin() const {
    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            if (grid[y][x] == -1) continue;
            Tile tile = tiles[grid[y][x]];
            if (tile.originalX != x||tile.originalY != y) {
                return false;
            }
        }
    }
    return true;
}

void Puzzle::moveTile(int x, int y) {
    if (std::abs(x - emptyPos.x) + std::abs(y - emptyPos.y) != 1) return;

    int tileIndex = grid[y][x];
    grid[y][x] = -1;
    grid[emptyPos.y][emptyPos.x] = tileIndex;

    // Mettre à jour la position de la tuile avec décalage
    tiles[tileIndex].sprite.setPosition(
        puzzlePosition.x + emptyPos.x * tileWidth,
        puzzlePosition.y + emptyPos.y * tileHeight
    );
	emptyPos = {x, y};
}
void Puzzle::processEvent(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed && !gameWon) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        mousePos.x -= puzzlePosition.x;
        mousePos.y -= puzzlePosition.y;

        if (mousePos.x < 0  || mousePos.x >= texture.getSize().x|| 
            mousePos.y < 0 || mousePos.y >= texture.getSize().y) {
            return;
        }

        int tileX = mousePos.x / tileWidth;
        int tileY = mousePos.y / tileHeight;

        moveTile(tileX, tileY);
        gameWon = isWin();
    }
}
void Puzzle::draw() {
    window.draw(backgroundSprite);
    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            int tileIndex = grid[y][x];
            if (tileIndex != -1) {
                window.draw(tiles[tileIndex].sprite);
            }
        }
    }
}

bool Puzzle::isGameWon() const {
    return gameWon;
}
