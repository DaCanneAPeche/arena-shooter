#include "game.hpp"
#include <iostream>

void print() {
    std::cout << "Trolololololololololololololo !!!" << std::endl;
}

Game::Game() : player(sf::Vector2i(121, 121), sf::Vector2i(8, 8), sf::Color::Green, 100, deltaTime) {
    window.create(sf::VideoMode(1000, 1000), "[SFML]");
    //window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    // debug("Game", "Window created");
    
    texture.create(250, 250);

    auto ennemy = std::make_shared<Ennemy>(sf::Vector2i(100, 100), deltaTime);
    ennemies.push_back(ennemy);

    testTimer.setTimer(print, 5);
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

    player.handleMovement();
    player.meleeWeapon.update(deltaTime, sf::Vector2f(player.rect.left, player.rect.top), 
            sf::Mouse::getPosition(window));

    player.healthBar.update();
    for (const auto& ennemy : ennemies) {
        ennemy.get()->checkDamages(player.meleeWeapon);

        if (ennemy.get()->life > 0) {
            ennemy.get()->moveToKb();
            ennemy.get()->healthBar.update();
        }
        else ennemies.erase(std::remove(ennemies.begin(), ennemies.end(), ennemy), ennemies.end());
    }

    testTimer.checkTime();

}

void Game::render() {

    texture.clear(sf::Color::Blue);

    /*for (auto& ennemy : ennemies) {
        texture.draw(ennemy.getRect());
        texture.draw(ennemy.healthBar.bgRect);
        texture.draw(ennemy.healthBar.fgRect);
        std::cout << ennemy.healthBar.entityPosX << std::endl;
    }*/

    texture.draw(player.meleeWeapon.damageHitboxRect);

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

