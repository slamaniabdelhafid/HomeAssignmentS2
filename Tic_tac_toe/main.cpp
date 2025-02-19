#include <SFML/Graphics.hpp>
#include "bouton.h"
#include "player.h"
#include "game_logic.h"


 
int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(500,500), "Tic-tac-toe");
	sf::Color bgColor(0x2B0040FF); //we define a bgcolor
	sf::Color bleu(0x48D2FEFF);
	sf::Color jaune(0xE2BE00FF);
	sf::Font font;
	sf::Text x_score;
	sf::Text y_score;
	sf::Text x_player;
	sf::Text y_player;
	sf::Text draw;
	sf::Text draw_score;
	sf::Text o_player;
	sf::Text o_score;
	sf::Text new_game;
	sf::Text n;

	// Ajouter la logique de jeu
    GameLogic game;
    Player player1(1);
    Player player2(2);
    bool gameState = true; // true = jeu en cours
	
	//configuration de text
	if (!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf")) { // TESTER EN ABSOLU
        return 1; // Quitter si erreur
    }
	
	// Texte "PlayerX"
    x_player.setFont(font);

    x_player.setString("Player X");
    x_player.setCharacterSize(12); // Taille réduite pour 2 lignes
    x_player.setFillColor(sf::Color::Black);
    x_player.setStyle(sf::Text::Bold);
	x_player.setPosition(140.f , 50.f);
	

    // Texte "0"
    x_score.setFont(font);
    x_score.setString("0");
    x_score.setCharacterSize(16);
    x_score.setFillColor(sf::Color::Black);
    x_score.setStyle(sf::Text::Bold);
	x_score.setPosition(160.f , 75.f);
	
	
	// Texte "draw"
    draw.setFont(font);

    draw.setString("DRAW");
    draw.setCharacterSize(12); // Taille réduite pour 2 lignes
    draw.setFillColor(sf::Color::Black);
    draw.setStyle(sf::Text::Bold);
	draw.setPosition(230.f , 50.f);
	

    // Texte "DRAW SCORE"
    draw_score.setFont(font);
    draw_score.setString("0");
    draw_score.setCharacterSize(16);
    draw_score.setFillColor(sf::Color::Black);
    draw_score.setStyle(sf::Text::Bold);
	draw_score.setPosition(250.f , 75.f);
	
	
	// Texte "PlayerO"
    o_player.setFont(font);

    o_player.setString("Player O");
    o_player.setCharacterSize(12); // Taille réduite pour 2 lignes
    o_player.setFillColor(sf::Color::Black);
    o_player.setStyle(sf::Text::Bold);
	o_player.setPosition(310.f , 50.f);
	

    // Texte "0"
    o_score.setFont(font);
    o_score.setString("0");
    o_score.setCharacterSize(16);
    o_score.setFillColor(sf::Color::Black);
    o_score.setStyle(sf::Text::Bold);
	o_score.setPosition(335.f , 75.f);
	// Créer les trois cases/carrés
    sf::RectangleShape box1(sf::Vector2f(70.f, 70.f)); // Taille 50x50
    sf::RectangleShape box2(sf::Vector2f(70.f, 70.f));
    sf::RectangleShape box3(sf::Vector2f(70.f, 70.f));

    // Positionnement horizontal
    box1.setPosition(130.f, 30.f);  // Gauche
    box2.setPosition(215.f, 30.f); // Milieu
    box3.setPosition(300.f, 30.f); // Droite 

    // Couleurs différentes
    box1.setFillColor(sf::Color(0x48D2FEFF));    // Rouge
    box2.setFillColor(sf::Color(0xBCDBF9FF));    // Vert
    box3.setFillColor(sf::Color(0xE2BE00FF));    // zree9

    // Contour noir pour toutes les cases
    box1.setOutlineThickness(2.f);
    box1.setOutlineColor(sf::Color::Black);
    box2.setOutlineThickness(2.f);
    box2.setOutlineColor(sf::Color::Black);
    box3.setOutlineThickness(2.f);
    box3.setOutlineColor(sf::Color::Black);
    
	//new game bt
	sf::RectangleShape button(sf::Vector2f(300.f, 50.f));
    button.setFillColor(sf::Color::White);
    button.setOutlineThickness(2.f);
    button.setOutlineColor(sf::Color::Black);
    button.setPosition(100.f, 420.f);
	
	//new game txt
	new_game.setFont(font);

    new_game.setString("New Game");
    new_game.setCharacterSize(16); // Taille réduite pour 2 lignes
    new_game.setFillColor(sf::Color::Black);
    new_game.setStyle(sf::Text::Bold);
	new_game.setPosition(210.f , 435.f);
	
	//box de matrice 3x3
	
    std::vector<Button> buttons;
    float buttonSize = 70.f;
    float spacing = 15.f;
    float startX = (500 - (3*buttonSize + 2*spacing)) / 2;
    float startY = 135.f;

    // Génération de la grille 3x3
    for(int row = 0; row < 3; ++row) {
        for(int col = 0; col < 3; ++col) {
            // Positionnement
            sf::Vector2f position(
                startX + col * (buttonSize + spacing),
                startY + row * (buttonSize + spacing)
            );

            // Couleur 
           
			int currentRow = row;
            int currentCol = col;
			sf::Color color(0x43115BFF);
            
			// Modification de l'action des boutons
            auto action = [&,currentRow, currentCol]() {
                if(gameState && game.getCell(currentRow, currentCol) == -1) {
                    // Déterminer le joueur actuel
                    int currentPlayer = (Player::getMoveCount() % 2 == 0) ? 1 : 2;
                    game.getCell(currentRow, currentCol) = (currentPlayer == 1) ? 1 : 0;
                    
					//color.Black;
                    // Vérifier victoire
                    if(game.checkLigne() || game.checkDiagonale()|| game.checkColonne()) {
                        if(currentPlayer == 1) {
                            player1.incrementScore();
                            x_score.setString(std::to_string(player1.getScore()));
                        } else {
                            player2.incrementScore();
                            o_score.setString(std::to_string(player2.getScore()));
                        }
                        gameState = false;
                    }
                    // Vérifier match nul
                    else if(Player::getMoveCount() == 8) {
                      int currentDraw = std::stoi(draw_score.getString().toAnsiString());
					   draw_score.setString(std::to_string(currentDraw + 1));
                       gameState = false;
                    }
                    
                    Player::makeMove();
                }
            };

            buttons.emplace_back(
                sf::Vector2f(buttonSize, buttonSize),
                position,
                color,
                action,
                "",
                font
            );
        }
    }
	// Ajouter l'action pour le bouton New Game
    auto newGameAction = [&]() {
        game.resetMatrix();
        Player::resetMoves();
        gameState = true;
        for(auto& btn : buttons) {
            btn.setLabel("");
        }
    };
    Button newGameBtn(sf::Vector2f(300.f, 50.f), sf::Vector2f(100.f, 420.f), sf::Color::White, newGameAction, "New Game", font);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
                window.close();
            }
			// Gestion des clics
            if(event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                
                // Vérifier les boutons de la grille
                for(auto& btn : buttons) {
                    if(btn.contains(mousePos)) {
                        btn.activate();
                        // Mettre à jour l'affichage
                        int index = &btn - &buttons[0];
                        int row = index / 3;
						
                        int col = index % 3;
                        if(game.getCell(row, col) != -1) {
					
                        btn.setLabel(game.getCell(row, col) == 1 ? "X" : "O");
						//color.Black;
                        btn.setLabelColor(game.getCell(row, col) == 1 ?sf::Color(bleu):sf::Color(jaune));
                    }
                    }
                }
                
                // Vérifier le bouton New Game
                if(newGameBtn.contains(mousePos)) {
                    newGameBtn.activate();
                }
				
            }
        }
		window.clear(bgColor);//apply the bg color;
        window.draw(box1);
		window.draw(box2);
		window.draw(box3);
		window.draw(x_player);
		window.draw(x_score);
		window.draw(o_player);
		window.draw(o_score);
		window.draw(draw);
		window.draw(draw_score);
		window.draw(button);
        window.draw(new_game);
		// Dessin de la grille de jeu
    for(auto& btn : buttons) {
        btn.draw(window);
    }

        window.display();
        }
       
        
    }

    