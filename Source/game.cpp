#include "game.hpp"
#include <iostream>

Game::Game() : player(sf::Vector2i(121, 121), sf::Vector2i(8, 8), sf::Color::Green, 100) {
    window.create(sf::VideoMode(1000, 1000), "[SFML]");
    //window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    // debug("Game", "Window created");
    
    texture.create(250, 250);
}

int Game::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }

    return 0;
}

void Game::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update() {
    deltaTime = dtClock.restart().asSeconds();

    player.handleMovement(deltaTime);
    player.healthBar.update();

}

void Game::render() {

    texture.clear(sf::Color::Blue);

    texture.draw(player.getRect());

    texture.draw(player.healthBar.bgRect);
    texture.draw(player.healthBar.fgRect);

    texture.display();
    
    sf::Sprite _texture(texture.getTexture());
    _texture.setScale(4, 4);
    window.clear();
    window.draw(_texture);
    window.display();
}

