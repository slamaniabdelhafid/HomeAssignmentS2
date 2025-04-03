#pragma once
#include <SFML/Graphics.hpp>

class Arrow {
public:
    Arrow(const std::string& texturePath, float speed, const sf::Vector2f& startPosition);
    
    void update(float deltaTime, float windowWidth);
    void draw(sf::RenderWindow& window) const;
    bool checkCollision(const sf::FloatRect& playerBounds) const;
    sf::FloatRect getGlobalBounds() const;
	void reset(const sf::Vector2f& newPosition);
	sf::FloatRect getBounds() const;

private:
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    float m_speed;
    float m_initialScaleX;
	sf::FloatRect m_customHitbox;
};