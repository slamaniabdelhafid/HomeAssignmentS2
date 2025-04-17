#include "message.h"
#include <iostream>

MessageBox::MessageBox(sf::RenderWindow& window, const std::string& message, const std::string& fontPath,bool txt)
    : window(window) {
    // Charger la police
    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Erreur lors du chargement de la police" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Initialiser les éléments de la boîte de message
    initialize(message,txt);
}

void MessageBox::initialize(const std::string& message,bool txt) {
    // Configuration de la boîte de message
    messageBox.setSize(sf::Vector2f(400.f, 200.f));
    messageBox.setFillColor(sf::Color(50, 50, 50));
    messageBox.setOutlineThickness(2);
    messageBox.setOutlineColor(sf::Color::White);
    messageBox.setPosition(
        window.getSize().x / 2 - messageBox.getSize().x / 2,
        window.getSize().y / 2 - messageBox.getSize().y / 2
    );

    // Configuration du texte principal
    titleText.setFont(font);
    titleText.setString(message);
    titleText.setCharacterSize(24);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(
        messageBox.getPosition().x + (messageBox.getSize().x - titleText.getLocalBounds().width) / 2,
        messageBox.getPosition().y + 20
    );

    // Configuration du bouton Quitter
    quitButton.setSize(sf::Vector2f(120.f, 40.f));
    quitButton.setFillColor(sf::Color::Red);
    quitButton.setPosition(
        messageBox.getPosition().x + 50,
        messageBox.getPosition().y + messageBox.getSize().y - 70
    );

    quitButtonText.setFont(font);
	quitButtonText.setString("Quit");
    quitButtonText.setCharacterSize(20);
    quitButtonText.setFillColor(sf::Color::White);
    quitButtonText.setPosition(
        quitButton.getPosition().x + (quitButton.getSize().x - quitButtonText.getLocalBounds().width) / 2,
        quitButton.getPosition().y + 10
    );

   
    replayButton.setSize(sf::Vector2f(120.f, 40.f));
    replayButton.setFillColor(sf::Color::Green);
    replayButton.setPosition(
        messageBox.getPosition().x + messageBox.getSize().x - 170,
        quitButton.getPosition().y
    );

    replayButtonText.setFont(font);
    txt == false ? replayButtonText.setString("Replay") : replayButtonText.setString("Next") ;
    replayButtonText.setCharacterSize(20);
    replayButtonText.setFillColor(sf::Color::White);
    replayButtonText.setPosition(
        replayButton.getPosition().x + (replayButton.getSize().x - replayButtonText.getLocalBounds().width) / 2,
        replayButton.getPosition().y + 10
    );
}

void MessageBox::draw() {
    window.draw(messageBox);
    window.draw(titleText);
    window.draw(quitButton);
    window.draw(quitButtonText);
    window.draw(replayButton);
    window.draw(replayButtonText);
}

void MessageBox::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            // Conversion des coordonnées de la souris
            sf::Vector2f mousePos = window.mapPixelToCoords(
                sf::Vector2i(event.mouseButton.x, event.mouseButton.y)
            );

            // Vérification des clics sur les boutons
            if (quitButton.getGlobalBounds().contains(mousePos) && quitAction) {
                quitAction();
            } else if (replayButton.getGlobalBounds().contains(mousePos) && replayAction) {
                replayAction();
            }
        }
    }
}

void MessageBox::setQuitAction(std::function<void()> action) {
    quitAction = action;
}

void MessageBox::setReplayAction(std::function<void()> action) {
    replayAction = action;
}