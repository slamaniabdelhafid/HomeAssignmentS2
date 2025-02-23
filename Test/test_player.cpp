#include <gtest/gtest.h>
#include "../model/player.h"

TEST(PlayerTest, InitialScoreIsZero) {
    Player player(1);
    EXPECT_EQ(player.getScore(), 0);
}

TEST(PlayerTest, IncrementScoreWorks) {
    Player player(1);
    player.incrementScore();
    EXPECT_EQ(player.getScore(), 1);
}

TEST(PlayerTest, ResetMovesWorks) {
    Player::resetMoves();
    EXPECT_EQ(Player::getMoveCount(), 0);
}

TEST(PlayerTest, MakeMoveIncrementsMoveCount) {
    Player::resetMoves();
    Player::makeMove();
    EXPECT_EQ(Player::getMoveCount(), 1);
}