#include <gtest/gtest.h>
#include "../view/bouton.h"
#include <SFML/Graphics.hpp>

class ButtonTest : public ::testing::Test {
protected:
    sf::Font font;

    void SetUp() override {
        ASSERT_TRUE(font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf"))
            << "Erreur lors du chargement de la police.";
    }

    Button createTestButton() {
        return Button(
            sf::Vector2f(200.f, 50.f),        
            sf::Vector2f(100.f, 100.f),       
            sf::Color::White,                  
            []() {},                           
            "Test Button",                     
            font                              
        );
    }
};

TEST_F(ButtonTest, TextIsSetCorrectly) {
    Button button = createTestButton();
    EXPECT_EQ(button.getLabel().getString(), "Test Button");
}

TEST_F(ButtonTest, TextColorIsUpdated) {
    Button button = createTestButton();
    button.setLabelColor(sf::Color::Red);
    EXPECT_EQ(button.getLabel().getFillColor(), sf::Color::Red);
}

TEST_F(ButtonTest, TextSizeIsUpdated) {
    Button button = createTestButton();
    button.setTextSize(30);
    EXPECT_EQ(button.getLabel().getCharacterSize(), 30);
}

TEST_F(ButtonTest, ContainsInsidePosition) {
    Button button = createTestButton();
    sf::Vector2i insidePosition(150, 125); // Position à l'intérieur
    EXPECT_TRUE(button.contains(insidePosition));
}

TEST_F(ButtonTest, ContainsOutsidePosition) {
    Button button = createTestButton();
    sf::Vector2i outsidePosition(50, 50); // Position à l'extérieur
    EXPECT_FALSE(button.contains(outsidePosition));
}