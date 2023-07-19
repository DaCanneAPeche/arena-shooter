#include "game.hpp"
#include <iostream>

Game::Game() : player(sf::Vector2f(121, 121), deltaTime),
               entityCreator("data/entities.toml", deltaTime) {

    window.create(sf::VideoMode(1000, 1000), "[SFML]");
    //window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    // debug("Game", "Window created");
    
    texture.create(250, 250);

    // auto ennemy = std::make_shared<Ennemy>(sf::Vector2f(100, 100), deltaTime);
    // ennemies.push_back(ennemy);
    npcs.push_back(std::make_shared<Npc>(sf::Vector2f(200, 100), deltaTime));
    
    std::shared_ptr<Ennemy> enemy = entityCreator.getEnemy("gobelin", sf::Vector2f(50, 100),
            ennemies, npcs, player);
    ennemies.push_back(enemy);

    std::shared_ptr<Npc> npc = std::make_shared<Npc>(sf::Vector2f(200, 150), deltaTime);
    npcs.push_back(npc);

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
    camera.update(player.sprite.pos, deltaTime);
    sf::Vector2f entityPos = player.sprite.sprite.getPosition();
    entityPos.x -= camera.offset.x;
    entityPos.y -= camera.offset.y;

    if (player.weaponUsed == 'm')
        player.meleeWeapon->update(entityPos, sf::Mouse::getPosition(window), camera.offset);

    else {
        player.rangeWeapon->update(entityPos, sf::Mouse::getPosition(window), camera.offset);
        player.rangeWeapon->checkLoading(entityCreator);
    }

    player.rangeWeapon->checkProjectiles();

    for (const auto& projectile : player.rangeWeapon->projectiles)
        projectile->update();

    player.healthBar.update(camera.offset);
    for (auto it = ennemies.begin() ; it < ennemies.end() ; ) {
        int i = std::distance(ennemies.begin(), it); 
        
        if (!( i < ennemies.size() )) break;

        if (player.weaponUsed == 'm')
            ennemies[i]->checkDamages(player.meleeWeapon, player.rangeWeapon->projectiles);
        else
            ennemies[i]->checkDamages(player.rangeWeapon, player.rangeWeapon->projectiles);

        if (ennemies[i]->life > 0) {
            ennemies[i]->moveToKb();
            ennemies[i]->healthBar.update(camera.offset);
            it++;
        }
        else ennemies.erase(it);
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

    if (player.weaponUsed == 'm') {
        // texture.draw(player.meleeWeapon->sprite.rect);
        // texture.draw(player.meleeWeapon->sprite.sprite);
        player.meleeWeapon->sprite.draw(texture, camera.offset);
    }
    else {
        // texture.draw(player.rangeWeapon->sprite.rect);
        // texture.draw(player.rangeWeapon->sprite.sprite);
        player.rangeWeapon->sprite.draw(texture, camera.offset);
    }

    for (const auto& projectile : player.rangeWeapon->projectiles) {
        // texture.draw(projectile->sprite.rect);
        // texture.draw(projectile->sprite.sprite);
        projectile->sprite.draw(texture, camera.offset);
    }

    for (const auto& npc : npcs) {
        // texture.draw(npc->sprite.sprite);
        npc->sprite.draw(texture, camera.offset);
    }

    for(const auto& ennemy : ennemies) {
        // texture.draw(ennemy->sprite.rect);
        // texture.draw(ennemy->sprite.sprite);
        ennemy->sprite.draw(texture, camera.offset);
        texture.draw(ennemy->healthBar.bgRect);
        texture.draw(ennemy->healthBar.fgRect);
    }

    // texture.draw(player.sprite.rect);
    // texture.draw(player.sprite.sprite);
    player.sprite.draw(texture, camera.offset);
    texture.draw(player.healthBar.bgRect);
    texture.draw(player.healthBar.fgRect);

    texture.display();
    
    sf::Sprite _texture(texture.getTexture());
    _texture.setScale(4, 4);
    window.clear();
    window.draw(_texture);
    window.display();
}

