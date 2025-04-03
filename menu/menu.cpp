#include "menu.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

Menu::Menu(float width, float height) //
//:mainmenu{ { font} ,{ font}, {  font }, {font} } ,menuText(font),moveSound(moveBuffer)
{
   if(!font.loadFromFile("assets/fonts/Gamtex.ttf")) {}
   if(!moveBuffer.loadFromFile("assets/sounds/choice.wav")) {}
    if(!menuBuffer.loadFromFile("assets/sounds/menu.wav")) {}
    moveSound.setBuffer(moveBuffer);
	menuSound.setBuffer(menuBuffer);
	menuSound.play();
    menuText.setFont(font);
   // menuText.setString("PING-PONG GAME");
    menuText.setCharacterSize(100);
    menuText.setFillColor(sf::Color(255, 215, 0));
    menuText.setOutlineColor(sf::Color::Black); 
    menuText.setOutlineThickness(3); 
    menuText.setPosition(sf::Vector2f(width / 2 - 430, 90)); 
    string options[4] = { "Play ","History", "Instruction", "Exit" };
	mainmenu[0].setFont(font); 
	mainmenu[0].setString(options[0]);
	mainmenu[0].setCharacterSize(35);
	mainmenu[0].setPosition(sf::Vector2f(600 ,375));
	
	mainmenu[1].setFont(font); 
	mainmenu[1].setString(options[1]);
	mainmenu[1].setCharacterSize(35);
	mainmenu[1].setPosition(sf::Vector2f(580 ,475));
	
	mainmenu[2].setFont(font); 
	mainmenu[2].setString(options[2]);
	mainmenu[2].setCharacterSize(35);
	mainmenu[2].setPosition(sf::Vector2f(550 ,590));
	
	mainmenu[3].setFont(font); 
	mainmenu[3].setString(options[3]);
	mainmenu[3].setCharacterSize(35);
	mainmenu[3].setPosition(sf::Vector2f(605 ,700));
	

    // Définit la couleur de l'option sélectionnée
    mainmenu[0].setFillColor(sf::Color(240, 143, 5)); // Première option sélectionnée par défaut
    selected = 0; // Initialise l'index sélectionné
   
}
Menu ::~Menu(){};
void Menu::draw(RenderWindow& Window){
    Window.draw(menuText);
    for(int i=0;i<4;i++){
        Window.draw(mainmenu[i]);
    }
}
void Menu:: Moveup(){
    if(selected-1>=-1){
        mainmenu[selected].setFillColor(Color::White);
        selected--;
        if(selected==-1){
            selected=3;
        }
       mainmenu[selected].setFillColor(sf::Color(240, 143, 5));
        moveSound.play();
    }
}
void Menu::MoveDown(){
    if(selected+1<=4){
        mainmenu[selected].setFillColor(Color::White);
        selected++;
        if(selected==4){
            selected=0; 
        }
        mainmenu[selected].setFillColor(sf::Color(240, 143, 5));
        moveSound.play();
    }
};
void Menu::setSelected(int n){
    selected = n;
};
bool Menu::isExitSelected() {
    // Check if the selected option is "Exit"
    return selected == 3;
}