#include "bouton.h"
#include <iostream>

// Constructeur
Button::Button(sf::Vector2f size, sf::Vector2f position, sf::Color color,
               std::function<void()> onClick, const std::string& text, sf::Font& font)
    : onClick(onClick) {
    // Configuration de la forme
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(color);
    shape.setOutlineThickness(2);
    shape.setOutlineColor(sf::Color::Black);

    // Configuration du texte
    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(40);
    label.setFillColor(sf::Color::Black);

    // Centrage du texte
    sf::FloatRect textBounds = label.getLocalBounds();
    label.setOrigin(textBounds.left + textBounds.width / 2.0f,
                    textBounds.top + textBounds.height / 2.0f);
    label.setPosition(position.x + size.x / 2, position.y + size.y / 2);
}

// Dessine 
void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(label);
}

// Vérifie si la souris est sur le bouton
bool Button::isMouseOver(sf::RenderWindow& window) const {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

//Active le bouton
void Button::activate() {
    if (onClick) {
        onClick();
    }
}

//nouveau texte pour le bouton
void Button::setLabel(const std::string& newText) {
    label.setString(newText);

    
    sf::FloatRect textBounds = label.getLocalBounds();
    label.setOrigin(textBounds.left + textBounds.width / 2.0f,
                    textBounds.top + textBounds.height / 2.0f);
    label.setPosition(shape.getPosition() + shape.getSize() / 2.0f);

    std::cout << "Label mis à jour : " << newText << std::endl; // Debug
}

//la couleur du texte
void Button::setLabelColor(const sf::Color& color) {
    label.setFillColor(color);
}

//le bouton contient une position donnée
bool Button::contains(const sf::Vector2i& mousePos) const {
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}
// Méthode pour changer la taille du texte
void Button::setTextSize(unsigned int newSize) {
    label.setCharacterSize(newSize); // Mettre à jour la taille du texte

    // Recentrer le texte après modification
    sf::FloatRect textBounds = label.getLocalBounds();
    label.setOrigin(textBounds.left + textBounds.width / 2.0f,
                    textBounds.top + textBounds.height / 2.0f);
    label.setPosition(shape.getPosition().x + shape.getSize().x / 2,
                      shape.getPosition().y + shape.getSize().y / 2);
}
const sf::Text& Button::getLabel() const {
    return label;
}