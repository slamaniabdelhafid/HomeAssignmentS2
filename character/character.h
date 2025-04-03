#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <map>
#include "platform.h"
enum class AnimationState {
    Idle,
    Run,
    Jump,
    Fall
};

class Character {
public:
    Character();
    void setPosition(const sf::Vector2f& position);
	sf::Vector2f getPosition() const;
    void loadTexturesFromFolder(const std::string& folderPath, AnimationState state);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    void handleInput();

    // Setters pour les contrôles
    void setMoveLeftKey(sf::Keyboard::Key key);
    void setMoveRightKey(sf::Keyboard::Key key);
    void setJumpKey(sf::Keyboard::Key key);
	void setScale(float factorX, float factorY);
	void checkPlatformCollisions(const std::vector<Platform>& platforms);
	sf::FloatRect getBounds();
private:
    void updateAnimation(float deltaTime);
    void applyPhysics(float deltaTime);
    void switchAnimation(AnimationState newState);
	std::vector<Platform> m_platforms;
	sf::FloatRect m_customHitbox;

    sf::Sprite m_sprite;
    std::map<AnimationState, std::vector<sf::Texture>> m_animations;
    AnimationState m_currentState;
    
    // Paramètres de mouvement
    sf::Vector2f m_velocity;
    float m_moveSpeed;
    float m_jumpForce;
    float m_gravity;
    bool m_isGrounded;
	float m_scaleX;
    float m_scaleY;

    // Contrôles
    sf::Keyboard::Key m_moveLeft;
    sf::Keyboard::Key m_moveRight;
    sf::Keyboard::Key m_jumpKey;

    // Animation
    float m_animationTimer;
    unsigned int m_currentFrame;
    float m_frameDuration;
};