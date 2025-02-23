#include <gtest/gtest.h>
#include "../controller/game_controller.h"
#include "../model/game_logic.h"
#include "../model/player.h"
#include "../view/game_view.h"
#include <SFML/Graphics.hpp>

class GameControllerTest : public ::testing::Test {
protected:
    sf::Font font;
    GameLogic gameLogic;
    Player player1{1};
    Player player2{2};
    GameView gameView{font};
    GameController gameController{gameLogic, player1, player2, gameView};

    void SetUp() override {
         const char* ci_env = std::getenv("CI");
    if (!ci_env || std::string(ci_env) != "true") {
        ASSERT_TRUE(font.loadFromFile("assets/fonts/FreeSans.ttf"))
            << "Erreur lors du chargement de la police.";
    }
    }
};

TEST_F(GameControllerTest, HandleEventResetsGame) {
    sf::Event event;
    event.type = sf::Event::MouseButtonPressed;
    event.mouseButton.button = sf::Mouse::Left;

    // Simuler un clic sur le bouton "New Game"
    sf::Vector2i mousePos(150, 435); // Position approximative du bouton "New Game"
    gameController.handleEvent(event, *(new sf::RenderWindow()));

    EXPECT_EQ(gameLogic.getCell(0, 0), -1); // Vérifier que la matrice est réinitialisée
    EXPECT_EQ(Player::getMoveCount(), 1);  // Vérifier que le compteur de mouvements est réinitialisé
}