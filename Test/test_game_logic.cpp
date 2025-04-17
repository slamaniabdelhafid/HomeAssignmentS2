#include "../model/game_logic.h"
#include <gtest/gtest.h>

class GameLogicTest : public ::testing::Test {
protected:
    GameLogic game;

    void SetUp() override {
        game.resetMatrix();
    }
};

TEST_F(GameLogicTest, Initialization) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(game.getCell(i, j), -1);
        }
    }
}

TEST_F(GameLogicTest, CheckWinConditions) {
    // Test row win
    game.getCell(0, 0) = 1;
    game.getCell(0, 1) = 1;
    game.getCell(0, 2) = 1;
    EXPECT_TRUE(game.checkLigne());
    EXPECT_FALSE(game.checkColonne());
    EXPECT_FALSE(game.checkDiagonale());

    game.resetMatrix();
    
    // Test column win
    game.getCell(0, 1) = 0;
    game.getCell(1, 1) = 0;
    game.getCell(2, 1) = 0;
    EXPECT_FALSE(game.checkLigne());
    EXPECT_TRUE(game.checkColonne());
    EXPECT_FALSE(game.checkDiagonale());

    game.resetMatrix();
    
    // Test diagonal win
    game.getCell(0, 0) = 1;
    game.getCell(1, 1) = 1;
    game.getCell(2, 2) = 1;
    EXPECT_FALSE(game.checkLigne());
    EXPECT_FALSE(game.checkColonne());
    EXPECT_TRUE(game.checkDiagonale());
}

TEST_F(GameLogicTest, BoardFullCheck) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            EXPECT_FALSE(game.isBoardFull());
            game.getCell(i, j) = (i + j) % 2; // Alternate between 0 and 1
        }
    }
    EXPECT_TRUE(game.isBoardFull());
}

TEST_F(GameLogicTest, EmptyCellsDetection) {
    auto emptyCells = game.getEmptyCells();
    EXPECT_EQ(emptyCells.size(), 9);
    
    game.getCell(1, 1) = 1;
    emptyCells = game.getEmptyCells();
    EXPECT_EQ(emptyCells.size(), 8);
}


TEST_F(GameLogicTest, ResetMatrix) {
    // Fill the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            game.getCell(i, j) = 1;
        }
    }
    
    game.resetMatrix();
    
    // Verify all cells are reset
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(game.getCell(i, j), -1);
        }
    }
}