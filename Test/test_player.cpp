#include <gtest/gtest.h>
#include "../model/player.h"
#include "../model/game_logic.h"
#include <thread>

class PlayerTest : public ::testing::Test {
protected:
    void SetUp() override {
        Player::resetMoves();
    }

    void TearDown() override {
        Player::resetMoves();
    }
};

TEST_F(PlayerTest, ConstructorInitialization) {
    Player humanPlayer(1, true);
    EXPECT_EQ(humanPlayer.getPlayerNumber(), 1);
    EXPECT_TRUE(humanPlayer.isHumanPlayer());
    EXPECT_EQ(humanPlayer.getScore(), 0);
    
    Player aiPlayer(2, false);
    EXPECT_EQ(aiPlayer.getPlayerNumber(), 2);
    EXPECT_FALSE(aiPlayer.isHumanPlayer());
}

TEST_F(PlayerTest, SymbolAssignment) {
    Player p1(1);
    Player p2(2);
    
    // Initial state - moveCount = 0
    EXPECT_EQ(p1.getSymbol(), 'X');
    EXPECT_EQ(p2.getSymbol(), 'O');
    
    Player::makeMove(); // moveCount = 1
    p1.updateSymbol();
    p2.updateSymbol();
    EXPECT_EQ(p1.getSymbol(), 'O');
    EXPECT_EQ(p2.getSymbol(), 'X');
}

TEST_F(PlayerTest, TurnManagement) {
    Player p1(1);
    Player p2(2);
    
    EXPECT_TRUE(p1.isMyTurn());
    EXPECT_FALSE(p2.isMyTurn());
    
    Player::makeMove();
    EXPECT_FALSE(p1.isMyTurn());
    EXPECT_TRUE(p2.isMyTurn());
}

TEST_F(PlayerTest, ScoreManagement) {
    Player player(1);
    EXPECT_EQ(player.getScore(), 0);
    player.incrementScore();
    EXPECT_EQ(player.getScore(), 1);
    player.incrementScore();
    EXPECT_EQ(player.getScore(), 2);
}


TEST_F(PlayerTest, MoveCountManagement) {
    EXPECT_EQ(Player::getMoveCount(), 0);
    Player::makeMove();
    EXPECT_EQ(Player::getMoveCount(), 1);
    Player::makeMove();
    EXPECT_EQ(Player::getMoveCount(), 2);
    Player::resetMoves();
    EXPECT_EQ(Player::getMoveCount(), 0);
}