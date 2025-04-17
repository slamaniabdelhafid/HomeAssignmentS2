#pragma once
#include <SFML/Graphics.hpp>

class Platform {
public:
    Platform(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color = sf::Color::Green);
    
    void draw(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;

private:
    sf::RectangleShape m_shape;
};