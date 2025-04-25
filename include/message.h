#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <SFML/Graphics.hpp>
#include <string>
#include <functional>

class MessageBox {
public:
    // Constructeur
    MessageBox(sf::RenderWindow& window, const std::string& message, const std::string& fontPath, bool txt);

    // Dessiner la boîte de message
    void draw();

    // Gérer les événements
    void handleEvent(const sf::Event& event);

    // Définir les actions des boutons
    void setQuitAction(std::function<void()> action);
    void setReplayAction(std::function<void()> action);


private:
    sf::RenderWindow& window; // Référence à la fenêtre principale
    sf::RectangleShape messageBox; // Rectangle de la boîte de message
    sf::Font font; // Police de texte
    sf::Text titleText; // Texte du message
    sf::RectangleShape quitButton; // Bouton Quitter
    sf::Text quitButtonText; // Texte du bouton Quitter
    sf::RectangleShape replayButton; // Bouton Rejouer
    sf::Text replayButtonText; // Texte du bouton Rejouer
	sf::Text nextButtonText;

    std::function<void()> quitAction; // Action pour le bouton Quitter
    std::function<void()> replayAction; 

    
    void initialize(const std::string& message, bool txt);
};

#endif 
