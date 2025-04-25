#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <string>

class Button {
public:
    // Constructeur
    Button(sf::Vector2f size, sf::Vector2f position, sf::Color color,
           std::function<void()> onClick, const std::string& text, sf::Font& font);

    //Dessine le bouton dans la fenêtre
    void draw(sf::RenderWindow& window);

    // Vérifie si la souris est sur le bouton
    bool isMouseOver(sf::RenderWindow& window) const;

    //Active le bouton (déclenche l'action associée)
    void activate();

    //nouveau texte pour le bouton
    void setLabel(const std::string& newText);

    
    void setLabelColor(const sf::Color& color);
	void setTextSize(unsigned int newSize);
	const sf::Text& getLabel() const;
    // Vérifie si le bouton contient une position donnée
    bool contains(const sf::Vector2i& mousePos) const;

private:
    sf::RectangleShape shape; 
    sf::Text label;           
    std::function<void()> onClick; 
};

#endif 
