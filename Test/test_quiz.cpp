#include "../quiz/quiz.h"
#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>

class QuizTest : public ::testing::Test {
protected:
    sf::RenderWindow window;
    Quiz quiz;

    void SetUp() override {
        window.create(sf::VideoMode(1280, 837), "Test Window");
    }

    void TearDown() override {
        window.close();
    }
};

TEST_F(QuizTest, ConstructorInitializesCorrectly) {
    // Verify the object is created without crashing
    SUCCEED();
}


TEST_F(QuizTest, DrawDoesNotCrash) {
    quiz.draw(window);
    SUCCEED(); // If we get here, draw didn't crash
}

