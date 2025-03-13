#include "puzzle.h"
#include <iostream>

Puzzle::Puzzle(const std::string& imageFile, int gridSize)
    : gridSize(gridSize), generator(std::random_device()()) {
    if (!texture.loadFromFile(imageFile)) {
        std::cerr << "Erreur de chargement de l'image\n";
        exit(EXIT_FAILURE);
    }

    window.create(
        sf::VideoMode(gridSize * texture.getSize().x / gridSize, 
                     gridSize * texture.getSize().y / gridSize),
        "Puzzle"
    );
    window.setFramerateLimit(60);

    initializeGrid();
    shuffle();
}

void Puzzle::initializeGrid() {
    int tileWidth = texture.getSize().x / gridSize;
    int tileHeight = texture.getSize().y / gridSize;

    grid = std::array<std::array<int, 4>, 4>(); // Initialisé à 0 par défaut
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
            tile.sprite.setPosition(x * tileWidth, y * tileHeight);
            tiles.push_back(tile);

            grid[y][x] = tiles.size() - 1; // Index de la tuile
        }
    }

    // Position vide en bas à droite
    emptyPos = {gridSize - 1, gridSize - 1};
    grid[emptyPos.y][emptyPos.x] = -1;
}

void Puzzle::shuffle() {
    std::uniform_int_distribution<int> dir(0, 3);
    for (int i = 0; i < 1000; ++i) {
        int dx = 0, dy = 0;
        switch (dir(generator)) {
            case 0: dx = -1; break; // Gauche
            case 1: dx = 1; break; // Droite
            case 2: dy = -1; break; // Haut
            case 3: dy = 1; break; // Bas
        }

        int newX = emptyPos.x + dx;
        int newY = emptyPos.y + dy;
        if (newX >= 0 && newX < gridSize && newY >= 0 && newY < gridSize) {
            if (grid[newY][newX] != -1) {
                // Échange avec la tuile adjacente
                int tileIndex = grid[newY][newX];
                grid[newY][newX] = -1;
                grid[emptyPos.y][emptyPos.x] = tileIndex;

                // Mettre à jour la position de la tuile
                tiles[tileIndex].sprite.setPosition(
                    emptyPos.x * (texture.getSize().x / gridSize),
                    emptyPos.y * (texture.getSize().y / gridSize)
                );

                // Mettre à jour la position vide
                emptyPos = {newX, newY};
            }
        }
    }
}

bool Puzzle::isWin() const {
    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            if (grid[y][x] == -1) continue; // Ignorer la position vide
            Tile tile = tiles[grid[y][x]];
            if (tile.originalX != x || tile.originalY != y) {
                return false;
            }
        }
    }
    return true;
}

void Puzzle::moveTile(int x, int y) {
    if (std::abs(x - emptyPos.x) + std::abs(y - emptyPos.y) != 1) return;

    // Échange la tuile avec la position vide
    int tileIndex = grid[y][x];
    grid[y][x] = -1;
    grid[emptyPos.y][emptyPos.x] = tileIndex;

    // Mettre à jour la position de la tuile
    tiles[tileIndex].sprite.setPosition(
        emptyPos.x * (texture.getSize().x / gridSize),
        emptyPos.y * (texture.getSize().y / gridSize)
    );

    // Mettre à jour la position vide
    emptyPos = {x, y};
}

void Puzzle::run() {
    bool isWin = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (isWin) continue;

                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                int x = mousePos.x / (texture.getSize().x / gridSize);
                int y = mousePos.y / (texture.getSize().y / gridSize);

                if (x < 0 || x >= gridSize || y < 0 || y >= gridSize) continue;

                moveTile(x, y);
                //isWin = isWin();
            }
        }

        window.clear();
        for (const auto& tile : tiles) {
            window.draw(tile.sprite);
        }
        window.display();

        if (isWin) {
            std::cout << "Vous avez gagné !" << std::endl;
            window.close();
        }
    }
}