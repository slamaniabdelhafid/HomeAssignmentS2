#include "arrow.h"
#include <iostream>

Arrow::Arrow(const std::string& texturePath, float speed, const sf::Vector2f& startPosition) :
    m_speed(speed),
    m_initialScaleX(1.0f) {
		m_customHitbox = sf::FloatRect(5, 5, 25, 25);
    if(!m_texture.loadFromFile(texturePath)) {
        std::cerr << "Erreur chargement texture ennemi" << std::endl;
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(startPosition);
    
    // Ajuster l'échelle initiale selon la direction
    if(m_speed < 0) {
        m_initialScaleX = -1.0f;
        m_sprite.setScale(m_initialScaleX, 1.0f);
    }
}

void Arrow::update(float deltaTime, float windowWidth) {
    m_sprite.move(m_speed * deltaTime, 0);

    // Rebond sur les bords
    if(m_sprite.getPosition().x + m_sprite.getGlobalBounds().width > windowWidth) {
        m_speed = -abs(m_speed);
        m_sprite.setScale(-m_initialScaleX, 1.0f);
    }
    else if(m_sprite.getPosition().x < 0) {
        m_speed = abs(m_speed);
        m_sprite.setScale(m_initialScaleX, 1.0f);
    }
}

void Arrow::draw(sf::RenderWindow& window) const {
    window.draw(m_sprite);
	
}

bool Arrow::checkCollision(const sf::FloatRect& playerBounds) const {
    return m_sprite.getGlobalBounds().intersects(playerBounds);
}

void Arrow::reset(const sf::Vector2f& newPosition) {
    m_sprite.setPosition(newPosition);
}
sf::FloatRect Arrow::getBounds() const {
    // Retourne la hitbox personnalisée
    sf::FloatRect bounds = m_sprite.getGlobalBounds();
    bounds.left += m_customHitbox.left;    // Décalage X
    bounds.top += m_customHitbox.top;      // Décalage Y
    bounds.width = m_customHitbox.width;   // Largeur personnalisée
    bounds.height = m_customHitbox.height; // Hauteur personnalisée
    return bounds;
}
