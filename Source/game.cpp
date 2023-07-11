#include "game.hpp"
#include <iostream>

Game::Game() : player(sf::Vector2f(121, 121), sf::Vector2f(8, 8), sf::Color::Green, 100, deltaTime),
               entityCreator("data/entities.toml", deltaTime) {

    window.create(sf::VideoMode(1000, 1000), "[SFML]");
    //window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    // debug("Game", "Window created");
    
    texture.create(250, 250);

    // auto ennemy = std::make_shared<Ennemy>(sf::Vector2f(100, 100), deltaTime);
    // ennemies.push_back(ennemy);
    
    std::shared_ptr<Ennemy> enemy = entityCreator.getEnemy("gobelin", sf::Vector2f(50, 100));
    ennemies.push_back(enemy);
    std::shared_ptr<Ennemy> enemy1 = entityCreator.getEnemy("gobelin", sf::Vector2f(70, 100));
    ennemies.push_back(enemy1);
    std::shared_ptr<Ennemy> enemy2 = entityCreator.getEnemy("gobelin", sf::Vector2f(90, 100));
    ennemies.push_back(enemy2);
    std::shared_ptr<Ennemy> enemy3 = entityCreator.getEnemy("gobelin", sf::Vector2f(110, 100));
    ennemies.push_back(enemy3);
    std::shared_ptr<Ennemy> enemy4 = entityCreator.getEnemy("gobelin", sf::Vector2f(130, 100));
    ennemies.push_back(enemy4);
    std::shared_ptr<Ennemy> enemy5 = entityCreator.getEnemy("gobelin", sf::Vector2f(150, 100));
    ennemies.push_back(enemy5);

    player.meleeWeapon = entityCreator.getMeleeWeapon("sword");
    player.rangeWeapon = entityCreator.getRangeWeapon("bow");
    player.weaponUsed = 'r';
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

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C) {
            if (player.weaponUsed == 'm') player.weaponUsed = 'r';
            else player.weaponUsed = 'm';
        }
    }
}

void Game::update() {
    deltaTime = dtClock.restart().asSeconds();

    player.handleMovement();

    if (player.weaponUsed == 'm')
        player.meleeWeapon->update(sf::Vector2f(player.sprite.pos.x, player.sprite.pos.y), 
                sf::Mouse::getPosition(window));

    else {
        player.rangeWeapon->update(sf::Vector2f(player.sprite.pos.x, player.sprite.pos.y), 
                sf::Mouse::getPosition(window));
        player.rangeWeapon->checkLoading(entityCreator);
    }

    player.rangeWeapon->checkProjectiles();

    for (const auto& projectile : player.rangeWeapon->projectiles)
        projectile.get()->update();

    player.healthBar.update();
    for (auto it = ennemies.begin() ; it < ennemies.end() ; ) {
        std::cout << "HIHI" << std::endl;
        int i = std::distance(ennemies.begin(), it); 
        
        if (!( i < ennemies.size() )) break;

        if (player.weaponUsed == 'm')
            ennemies[i]->checkDamages(player.meleeWeapon, player.rangeWeapon->projectiles);
        else
            ennemies[i]->checkDamages(player.rangeWeapon, player.rangeWeapon->projectiles);

        if (ennemies[i]->life > 0) {
            ennemies[i]->moveToKb();
            ennemies[i]->healthBar.update();
            it++;
        }
        else ennemies.erase(it);
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

    if (player.weaponUsed == 'm')
        texture.draw(player.meleeWeapon->sprite.rect);
    else
        texture.draw(player.rangeWeapon->sprite.rect);

    for (const auto& projectile : player.rangeWeapon->projectiles) {
        texture.draw(projectile->sprite.rect);
    }

    for(const auto& ennemy : ennemies) {
        texture.draw(ennemy->sprite.rect);
        texture.draw(ennemy->healthBar.bgRect);
        texture.draw(ennemy->healthBar.fgRect);
    }

    texture.draw(player.sprite.rect);
    texture.draw(player.healthBar.bgRect);
    texture.draw(player.healthBar.fgRect);

    texture.display();
    
    sf::Sprite _texture(texture.getTexture());
    _texture.setScale(4, 4);
    window.clear();
    window.draw(_texture);
    window.display();
}

