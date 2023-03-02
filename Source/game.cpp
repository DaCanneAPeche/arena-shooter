#include "game.hpp"

Game::Game() : player(sf::Vector2i(121, 121)) {
    window.create(sf::VideoMode(1000, 1000), "[SFML]");
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

void Game::update() {}

void Game::render() {

    texture.clear(sf::Color::Blue);

    texture.draw(player.getRect());

    texture.display();
    
    sf::Sprite _texture(texture.getTexture());
    _texture.setScale(4, 4);
    window.clear();
    window.draw(_texture);
    window.display();
}
