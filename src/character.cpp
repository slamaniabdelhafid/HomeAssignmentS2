#include "character.h"
#include <experimental/filesystem>
#include <iostream>

namespace fs = std::experimental::filesystem;

Character::Character() :
    m_moveSpeed(300.0f),
    m_jumpForce(-600.0f),
    m_gravity(980.0f),
    m_isGrounded(false),
    m_currentState(AnimationState::Idle),
    m_animationTimer(0.0f),
    m_currentFrame(0),
	m_scaleX(1.0f),
    m_scaleY(1.0f),
    m_frameDuration(0.1f) {
    m_customHitbox = sf::FloatRect(5, 5, 25, 25);
    m_moveLeft = sf::Keyboard::Left;
    m_moveRight = sf::Keyboard::Right;
    m_jumpKey = sf::Keyboard::Space;
}

void Character::loadTexturesFromFolder(const std::string& folderPath, AnimationState state) {
    m_animations[state].clear();
    
    try {
        int counter = 1;
        while(true) {
            std::string path = folderPath + "/" + std::to_string(counter) + ".png";
            sf::Texture texture;
            if(texture.loadFromFile(path)) {
                m_animations[state].push_back(texture);
                counter++;
            } else {
                break;
            }
        }
    } catch(const std::exception& e) {
        std::cerr << "Error loading textures: " << e.what() << std::endl;
    }

    if(!m_animations[m_currentState].empty()) {
        m_sprite.setTexture(m_animations[m_currentState][0]);
    }
}

void Character::update(float deltaTime) {
    handleInput();
    applyPhysics(deltaTime);
    updateAnimation(deltaTime);
}

void Character::draw(sf::RenderWindow& window) {
    window.draw(m_sprite);
}

void Character::handleInput() {
    m_velocity.x = 0;

    if(sf::Keyboard::isKeyPressed(m_moveLeft)) {
		if(!(m_sprite.getPosition().x<100)){
			m_velocity.x = -m_moveSpeed;
			m_sprite.setScale(-m_scaleX, m_scaleY);
		}
         // Inversion horizontale
    }
    else if(sf::Keyboard::isKeyPressed(m_moveRight)) {
	if(!(m_sprite.getPosition().x>=1190)){
			 m_velocity.x = m_moveSpeed;
			 m_sprite.setScale(m_scaleX, m_scaleY);
			// switchAnimation(AnimationState::Run);
		}
       
    }

    if(sf::Keyboard::isKeyPressed(m_jumpKey) && m_isGrounded) {
        m_velocity.y = m_jumpForce;
        m_isGrounded = false;
        switchAnimation(AnimationState::Jump);
    }
}

void Character::applyPhysics(float deltaTime) {
    m_velocity.y += m_gravity * deltaTime;
    sf::Vector2f nextPosition = m_sprite.getPosition() + m_velocity * deltaTime;
    // Vérification collision verticale
    sf::FloatRect nextBounds = m_sprite.getGlobalBounds();
    nextBounds.top = nextPosition.y;

    bool willCollide = false;
    for (const auto& platform : m_platforms) {
        if (nextBounds.intersects(platform.getBounds())) {
            willCollide = true;
            break;
        }
    }

    if (!willCollide) {
        m_sprite.setPosition(nextPosition);
    } else {
        m_velocity.y = 0;
        m_isGrounded = true;
    }
}
sf::FloatRect Character::getBounds(){
	sf::FloatRect bounds = m_sprite.getGlobalBounds();
    bounds.left += m_customHitbox.left;    // Décalage X
    bounds.top += m_customHitbox.top;      // Décalage Y
    bounds.width = m_customHitbox.width;   // Largeur personnalisée
    bounds.height = m_customHitbox.height; // Hauteur personnalisée
    return bounds;
	}

void Character::checkPlatformCollisions(const std::vector<Platform>& platforms) {
    m_isGrounded = false;
    sf::FloatRect bounds = m_sprite.getGlobalBounds();

    for (const auto& platform : platforms) {
        if (bounds.intersects(platform.getBounds())) {
            // Collision depuis le haut
            if (m_velocity.y > 0) {
                m_sprite.setPosition(m_sprite.getPosition().x, platform.getBounds().top - bounds.height);
                m_velocity.y = 0;
                m_isGrounded = true;
            }
            // Collision depuis le bas (optionnel)
            else if (m_velocity.y < 0) {
                m_sprite.setPosition(m_sprite.getPosition().x, platform.getBounds().top + platform.getBounds().height);
                m_velocity.y = 0;
            }
        }
    }
}

void Character::updateAnimation(float deltaTime) {
    if(m_animations[m_currentState].empty()) return;

    m_animationTimer += deltaTime;
    if(m_animationTimer >= m_frameDuration) {
        m_currentFrame = (m_currentFrame + 1) % m_animations[m_currentState].size();
        m_sprite.setTexture(m_animations[m_currentState][m_currentFrame]);
        m_animationTimer = 0.0f;
    }
}

void Character::switchAnimation(AnimationState newState) {
    if(m_currentState != newState && !m_animations[newState].empty()) {
        m_currentState = newState;
        m_currentFrame = 0;
        m_sprite.setTexture(m_animations[m_currentState][m_currentFrame]);
    }
}
void Character::setPosition(const sf::Vector2f& position) {
    m_sprite.setPosition(position);
}

sf::Vector2f Character::getPosition() const {
    return m_sprite.getPosition();
}
void Character::setScale(float factorX, float factorY) {
    m_scaleX = factorX;
    m_scaleY = factorY;
    m_sprite.setScale(m_scaleX, m_scaleY);
}
// Setters pour les contrôles
void Character::setMoveLeftKey(sf::Keyboard::Key key) { m_moveLeft = key; }
void Character::setMoveRightKey(sf::Keyboard::Key key) { m_moveRight = key; }
void Character::setJumpKey(sf::Keyboard::Key key) { m_jumpKey = key; }
