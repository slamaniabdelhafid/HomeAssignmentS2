#include <gtest/gtest.h>
#include "../model/game_logic.h"

TEST(GameLogicTest, InitialMatrixIsEmpty) {
    GameLogic logic;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            EXPECT_EQ(logic.getCell(row, col), -1);
        }
    }
}

TEST(GameLogicTest, SetCellWorks) {
    GameLogic logic;
    logic.getCell(0, 0) = 1;
    EXPECT_EQ(logic.getCell(0, 0), 1);
}

TEST(GameLogicTest, CheckLigneDetectsWin) {
    GameLogic logic;
    logic.getCell(0, 0) = 1;
    logic.getCell(0, 1) = 1;
    logic.getCell(0, 2) = 1;
    EXPECT_TRUE(logic.checkLigne());
}

TEST(GameLogicTest, CheckDiagonaleDetectsWin) {
    GameLogic logic;
    logic.getCell(0, 0) = 1;
    logic.getCell(1, 1) = 1;
    logic.getCell(2, 2) = 1;
    EXPECT_TRUE(logic.checkDiagonale());
}