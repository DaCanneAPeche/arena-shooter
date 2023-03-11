#include "game.hpp"
#include <iostream>

Game::Game() : player(sf::Vector2i(121, 121), sf::Vector2i(8, 8), sf::Color::Green, 100) {
    window.create(sf::VideoMode(1000, 1000), "[SFML]");
    //window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    // debug("Game", "Window created");
    
    texture.create(250, 250);

    auto ennemy = std::make_shared<Ennemy> (sf::Vector2i(100, 100), sf::Vector2i(8, 8), sf::Color::Red, 100);
    ennemies.push_back(ennemy);
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
    for (const auto& ennemy : ennemies) {
        ennemy.get()->healthBar.update();
    }

}

void Game::render() {

    texture.clear(sf::Color::Blue);

    /*for (auto& ennemy : ennemies) {
        texture.draw(ennemy.getRect());
        texture.draw(ennemy.healthBar.bgRect);
        texture.draw(ennemy.healthBar.fgRect);
        std::cout << ennemy.healthBar.entityPosX << std::endl;
    }*/
    for(const auto& ennemy : ennemies) {
        texture.draw(ennemy->getRect());
        texture.draw(ennemy->healthBar.bgRect);
        texture.draw(ennemy->healthBar.fgRect);
    }

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

