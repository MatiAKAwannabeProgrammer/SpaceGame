#include "game.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

Game::Game()
{
    window.create(sf::VideoMode(800, 600), "The Game");
    isFired = false;
}

bool Game::running()
{
    return window.isOpen();
}

void Game::pollEvents()
{
    while (window.pollEvent(event))    
    {
        if (event.type == sf::Event::Closed)
            window.close();

        
    }
}

void Game::update()
{
    // Start the clocks.
    deltaTime = deltaClock.restart().asSeconds();
    bulletTime = bulletClock.getElapsedTime();
    enemyTime = enemyClock.getElapsedTime();

    // Player methods/variables.
    player.getPlayerPos();
    currentPlayerPos = player.playerPosition;
    player.playerMovement(deltaTime, currentPlayerPos); 
    player.playerShooting(isFired, bulletClock, bulletTime);

    // Bullet function calls.
    if (isFired)
        createBullet();
    isFired = false;
    updateBullet();

    // Enemy function calls.
    if (enemyTime.asSeconds() >= 2)
    {
        enemyClock.restart();
        createEnemy();
    }
    updateEnemy();

    enemy->collision(enemyVec, bulletVec);
}

void Game::render()
{
    window.clear();

    map.drawMap(window);

    // Displaying the entities.
    player.drawPlayer(window);
    drawBullet();
    drawEnemy();

    window.display();
}

void Game::createBullet()
{
    bullet = new Bullet(currentPlayerPos);
    bulletVec.push_back(*bullet);
}

void Game::updateBullet()
{
    for (unsigned int i = 0; i < bulletVec.size(); i++)
    {
        bulletVec[i].updateBullet(deltaTime);
        bulletVec[i].getBulletPos();
        
        if (bulletVec[i].bulletPosition.y <= 0)
        {
            bulletVec.erase(bulletVec.begin() + i);
            bulletVec.shrink_to_fit();
        }
    }
}

void Game::drawBullet()
{
    for (unsigned int i = 0; i < bulletVec.size(); i++)
        bulletVec[i].drawBullet(window);
}

void Game::createEnemy()
{
    enemy = new Enemy();
    enemyVec.push_back(*enemy);
}

void Game::updateEnemy()
{
    for (unsigned int i = 0; i < enemyVec.size(); i++)
    {
        enemyVec[i].enemyMovement(deltaTime);
        enemyVec[i].getEnemyPosition();
        
        if (enemyVec[i].enemyPosition.y >= 600)
        {
            enemyVec.erase(enemyVec.begin() + i);
            enemyVec.shrink_to_fit();
        }
    }
}

void Game::drawEnemy()
{
    for (unsigned int i = 0; i < enemyVec.size(); i++)
        enemyVec[i].drawEnemy(window);
}
