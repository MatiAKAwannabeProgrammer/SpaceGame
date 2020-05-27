#include "game.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

Game::Game()
{
    window.create(sf::VideoMode(800, 600), "The Game");
    isFired = false;
    scoreInt = 0;
    healthInt = 3;
    enemySpawnTimer = 2.4f;
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
    if (enemyTime.asSeconds() >= enemySpawnTimer)
    {
        enemyClock.restart();
        createEnemy();
    }
    updateEnemy();

    enemy->collision(enemyVec, bulletVec, scoreInt);
    // Level functions.
    level();
    increaseDifficulty();
}

void Game::render()
{
    window.clear();

    map.drawMap(window);

    // Displaying the entities.
    player.drawPlayer(window);
    drawBullet();
    drawEnemy();
    score.drawScore(window, scoreInt);
    health.drawHealth(window, healthInt);

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
            healthInt--;
        }
    }
}

void Game::drawEnemy()
{
    for (unsigned int i = 0; i < enemyVec.size(); i++)
        enemyVec[i].drawEnemy(window);
}

void Game::level()
{
    if (scoreInt == 10)
        levelInt = 2;
    if (scoreInt == 20)
        levelInt = 3;
    if (scoreInt == 30)
        levelInt = 4;
    if (scoreInt == 40)
        levelInt = 5;
    if (scoreInt == 50)
        levelInt = 6;
    if (scoreInt == 60)
        levelInt = 7;
    if (scoreInt == 70)
        levelInt = 8;
}

void Game::increaseDifficulty()
{
        if (levelInt == 2)
            enemySpawnTimer = 2.2f;
        if (levelInt == 3)
            enemySpawnTimer = 2.0f;
        if (levelInt == 4)
            enemySpawnTimer = 1.8f;   
        if (levelInt == 5)
            enemySpawnTimer = 1.6f;
        if (levelInt == 6)
            enemySpawnTimer = 1.4f;
        if (levelInt == 7)
            enemySpawnTimer = 1.2f;
        if (levelInt == 8)
            enemySpawnTimer = 1.0f;
}
