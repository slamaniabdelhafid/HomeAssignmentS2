#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>
#include <iostream>

class Button {
public:
    Button(sf::Vector2f size, sf::Vector2f position, sf::Color color, 
          std::function<void()> onClick, const std::string& text, sf::Font& font)
        : onClick(onClick) 
    {
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
        label.setFillColor(sf::Color::White);

        // Centrage du texte
        sf::FloatRect textBounds = label.getLocalBounds();
        label.setOrigin(textBounds.left + textBounds.width/2.0f,
                        textBounds.top + textBounds.height/2.0f);
        label.setPosition(position.x + size.x/2, position.y + size.y/2);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(label);
    }

    bool isMouseOver(sf::RenderWindow& window) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        return shape.getGlobalBounds().contains(mousePos.x, mousePos.y);
    }

    void handleClick() {
        if(onClick) {
            onClick();
        }
    }
	// Ajoutez ces nouvelles méthodes
    bool contains(const sf::Vector2i& mousePos) const {
        return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
    }

    void activate() {
        handleClick(); // Renommez simplement handleClick en activate
    }

    void setLabel(const std::string& newText) {
        label.setString(newText);
        // Recentrer le texte après modification
        sf::FloatRect textBounds = label.getLocalBounds();
        label.setOrigin(textBounds.left + textBounds.width/2.0f,
                        textBounds.top + textBounds.height/2.0f);
        label.setPosition(shape.getPosition() + shape.getSize()/2.0f);
		std::cout << "Label mis à jour : " << newText << std::endl;  // Debug
		
    }

    void setLabelColor(const sf::Color& color) {
        label.setFillColor(color);
    }

private:
    sf::RectangleShape shape;
    sf::Text label;
    std::function<void()> onClick;
};