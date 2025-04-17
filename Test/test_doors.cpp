#include "../doors/doors.h"
#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>

class DoorsTest : public ::testing::Test {
protected:
    sf::RenderWindow window;
    Doors doors;

    void SetUp() override {
        window.create(sf::VideoMode(1280, 837), "Test Window");
    }

    void TearDown() override {
        window.close();
    }
};

TEST_F(DoorsTest, ConstructorInitializesCorrectly) {
    // Verify texture is loaded
    EXPECT_NE(doors.isAPressed({0,0}), true); // Just checking it's callable
    
    // Can't directly check private texture, but we can verify behavior
    SUCCEED();
}



TEST_F(DoorsTest, DrawDoesNotCrash) {
    doors.draw(window);
    SUCCEED(); // If we get here, draw didn't crash
}

