
#include "character/character.h"
#include "character/arrow.h"
#include "character/message.h"
#include "memo/NumberGame.h"
#include "doors/doors.h" 
#include "quiz/quiz.h" 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "menu/menu.h"
#include "menu/instruction.h"
#include "menu/history.h"
#include "puzzle/puzzle.h" 
#include "model/game_logic.h"
#include "model/player.h"
#include "view/game_view.h"
#include "controller/game_controller.h"
#include "winpage.h"
#include <iostream>



int main() {
    // Initialisation de la fenêtre
    sf::RenderWindow window(sf::VideoMode(1280, 837), "Menu Navigation");

    // Initialisation du menu
    Menu menu(1280, 837);
	SoundBuffer finalBuffer;
	Sound finalSound;
	if(!finalBuffer.loadFromFile("assets/sounds/menu.wav")) {}
    finalSound.setBuffer(finalBuffer);

    // Chargement des textures
    sf::Texture bgImage, bgImage2, keyImage;
    if (!bgImage.loadFromFile("assets/images/menu.jpg")) {
        // Gérer l'erreur si nécessaire
    }
    if (!bgImage2.loadFromFile("assets/images/mario.png")) {
        // Gérer l'erreur si nécessaire
    }
    if (!keyImage.loadFromFile("assets/images/key.png")) {
        // Gérer l'erreur si nécessaire
    }

    // Initialisation des sprites
    sf::Sprite bg(bgImage);
    sf::Sprite bg2(bgImage2);
    sf::Sprite keyy(keyImage);
    keyy.setPosition(1172, 431);

    // Initialisation des pages
    Instruction instructionPage;
    Doors doorsPage;
    Quiz quizPage;
    History historyPage;
    std::unique_ptr<Puzzle> puzzle;

    // Variables d'état
    bool isInMenu = true;
    bool isInPuzzle = false;
    bool isInInstruction = false;
    bool isInHistory = false;
    bool gameOver = false;
	bool step2 = false ;
    bool step4 = false;
    bool step5 = false;
    bool step6 = false;
    bool lastG = false;
    bool hasKey = false;
	bool step1 ;
	bool lastgame = false ;
//tic 
	sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf")) {
        std::cout << "Erreur lors du chargement de la police." << std::endl;
        return -1;
    }

    GameLogic gameLogic;
	Player joueur1(1, true);  // Joueur humain (X)
    Player joueur2(2, false); // IA (O)
    GameView gameView(font);
    GameController gameController(gameLogic, joueur1, joueur2, gameView);

    // Initialisation du personnage
    Character player;
    Arrow arrow("assets/images/arrow.png", 750.0f, sf::Vector2f(1280, 400));

    // Chargement des animations du personnage
    player.loadTexturesFromFolder("assets/character/run", AnimationState::Run);
    player.loadTexturesFromFolder("assets/character/idel", AnimationState::Idle);
    player.loadTexturesFromFolder("assets/character/jump", AnimationState::Jump);
    player.setScale(0.3f, 0.3f);

    // Initialisation des plateformes
    std::vector<Platform> platforms {
        Platform({375, 15}, {0, 529}),
        Platform({160, 15}, {915, 585}),
        Platform({160, 15}, {775, 665}),
        Platform({200, 15}, {1090, 520}),
        Platform({1280, 15}, {0, 720})
    };

    // Initialisation des boîtes de message
    MessageBox messageBox(window, "Game Over", "assets/fonts/Gamtex.ttf", false);
    MessageBox messageBox2(window, "URAAAAA\nYou are in the treasure room", "assets/fonts/Gamtex.ttf", true);

    messageBox.setQuitAction([&window]() {
        window.close();
    });

    messageBox.setReplayAction([&gameOver, &arrow, &hasKey, &player]() {
        gameOver = false;
        arrow.reset(sf::Vector2f(1280, 400));
        hasKey = false;
        player.setPosition(sf::Vector2f(50, 180));
    });
	    messageBox2.setReplayAction([&lastgame, &lastG , &step5]() {
      lastgame = true ;
	  lastG = false ;
	  step5=false ;
	  
    });

    // Position initiale du personnage
    player.setPosition(sf::Vector2f(50, 180));

    // Boucle principale
    sf::Clock clock;
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        sf::Event event;

        // Gestion des événements
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
			gameController.handleEvent(event, window);
            }

            if (step4 == false||step2== true) {
                if (!gameOver) {
                    player.update(deltaTime);
                    arrow.update(deltaTime, window.getSize().x);
                    player.checkPlatformCollisions(platforms);
					if (arrow.checkCollision(player.getBounds())) gameOver = true;
                } else {
                    messageBox.handleEvent(event);
                }
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (step4 == true) {
                    if (doorsPage.isAPressed(sf::Mouse::getPosition(window))) {
                        //srand(time(0));
                        int rn = rand() % 3 + 1;
                        std::cout << "rng!" << rn;
                        switch (rn) {
                            case 1:
                                hasKey = false;
                                step5 = true;
                                step4 = false;
                                break;
                            case 2:
                                hasKey = false;
                                step5 = true;
                                step4 = false;
                                break;
                            case 3:
                                step5 = true;
                                step4 = false;
                                hasKey = false;
                                break;
                            default:
                                break;
                        }
                    } else if (doorsPage.isBPressed(sf::Mouse::getPosition(window))) {
                        srand(time(0));
                        int rn = rand() % 3 + 1;
                        std::cout << "rang!" << rn;
                        switch (rn) {
                            case 1:
                                step4 = false;
                                break;
                            case 2:
                                window.close();
                                break;
                            case 3:
                                step4 = false;
                                break;
                        }
                    } else if (doorsPage.isCPressed(sf::Mouse::getPosition(window))) {
                        srand(time(0));
                        int rn = rand() % 3 + 1;
                        switch (rn) {
                            case 1:
                                step4 = false;
                                break;
                            case 2:
                                
                                break;
                            case 3:
                                step4 = false;
                                break;
                        }
                    }
                } else if (step5 == true) {
                    if (quizPage.isCPressed(sf::Mouse::getPosition(window))) {
                        step4 = false; 
                        lastG = true;
                    } else {
						step5 = false;
						step2 = false ;
						step4 = false; 
						lastgame = true;
                        std::cout << "OOH,you fell into the trap and died\n";
                        //window.close();
                    }
                }
            }

            if (isInMenu) {
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Up) {
                        menu.Moveup();
                    } else if (event.key.code == sf::Keyboard::Down) {
                        menu.MoveDown();
                    } else if (event.key.code == sf::Keyboard::Right) {
					
                        int selectedOption = menu.getSelected();
                        switch (selectedOption) {
                            case 0:
                                isInMenu = false;
                                isInPuzzle = true;
                                puzzle.reset(new Puzzle(window, "assets/images/pz.jpg", "assets/images/pbg.png", 3));
                                break;
                            case 1:
                                isInMenu = false;
                                isInHistory = true;
                                break;
                            case 2:
                                isInMenu = false;
                                isInInstruction = true;
                                break;
                            case 3:
                                window.close();
                                break;
                        }
                    }
                }
            } else if (isInPuzzle) {
                // Gestion des événements du puzzle
				 isInPuzzle = true;
				isInMenu = false;
            } else if (isInInstruction) {
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    if (instructionPage.isBackPressed(sf::Mouse::getPosition(window))) {
                        isInInstruction = false;
                        isInMenu = true;
                    }
                }
            } else if (isInHistory) {
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    if (historyPage.isBackPressed(sf::Mouse::getPosition(window))) {
                        isInHistory = false;
                        isInMenu = true;
                    }
                }
            }
			 else if (lastgame) {
           
            }
        
		
        // Rendu
        window.clear();
	    if (lastgame) {
			finalSound.play();	
			 gameController.update(); 
			         //  window.clear(sf::Color(0x2B0040FF)); // Couleur de fond
					 gameController.updateView();
        gameView.draw(window);
            }
        
       else if (isInMenu) {
            window.draw(bg);
            menu.draw(window);
        } else if (isInInstruction) {
            instructionPage.draw(window);
        } else if (isInHistory) {
            historyPage.draw(window);
        } else if (isInPuzzle) {

			if (puzzle->isWin()){
				isInPuzzle=false;
				step2=true ;
				}
				
						
        
          puzzle->draw();
		 puzzle->processEvent(event);
        } else if (player.getBounds().left + player.getBounds().width < 100 && hasKey == true) {
            step4 = true;
            doorsPage.draw(window);
        } else if (step5 == true) {
            quizPage.draw(window);
            if (lastG) {
                messageBox2.draw();
            }
        } else {
            // Niveau de jeu principal
            for (const auto& platform : platforms) {
                platform.draw(window);
            }
            window.draw(bg2);
            if (player.getBounds().left >= keyy.getGlobalBounds().left) {
                hasKey = true;
            }
            if (!hasKey) {
                window.draw(keyy);
            }
            player.draw(window);
            arrow.draw(window);

            if (gameOver) {
                messageBox.draw();
            }
        }

        window.display();
    }

    return 0;
}
