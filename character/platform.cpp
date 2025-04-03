#include "platform.h"

Platform::Platform(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color) {
    m_shape.setSize(size);
    m_shape.setPosition(position);
    m_shape.setFillColor(color);
}

void Platform::draw(sf::RenderWindow& window) const {
    window.draw(m_shape);
}

sf::FloatRect Platform::getBounds() const {
    return m_shape.getGlobalBounds();
}