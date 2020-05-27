#include "enemy.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

Enemy::Enemy()
{
    enemyTexture.loadFromFile("./content/enemy.png");
    enemyModel.setTexture(enemyTexture);
    speed = 200.f;

    // Set a random position.
    srand((unsigned) time(0));
    spawnPosition = (rand() % 750) + 1; 
    enemyModel.setPosition(sf::Vector2f(spawnPosition, 0));
    
}

void Enemy::enemyMovement(float& deltaTime)
{
    enemyBounds = enemyModel.getGlobalBounds();
    enemyModel.move(0, speed * deltaTime);
}

void Enemy::drawEnemy(sf::RenderWindow& window)
{
    window.draw(enemyModel);
}

void Enemy::getEnemyPosition()
{
    enemyPosition = enemyModel.getPosition();
}

void Enemy::collision(std::vector<Enemy>& enemyVec, std::vector<Bullet>& bulletVec, int& score)
{
    for (unsigned int i = 0; i < enemyVec.size(); i++) 
    {
        for (unsigned int j = 0; j < bulletVec.size(); j++)
        {
            if (enemyVec[i].enemyBounds.contains(bulletVec[j].bulletPosition))
            {
                enemyVec.erase(enemyVec.begin() + i);
                bulletVec.erase(bulletVec.begin() + j);
                score++;
            }
        }
    }
}
