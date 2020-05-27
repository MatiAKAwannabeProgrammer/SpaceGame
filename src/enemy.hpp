#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <stdlib.h>
#include <stdlib.h>
#include <ctime>
#include "bullet.hpp"

class Enemy
{
private:
    sf::Sprite enemyModel;
    sf::Texture enemyTexture;
    float spawnPosition;
    float speed;

public:
    Enemy();
    void enemyMovement(float& deltaTime);
    void drawEnemy(sf::RenderWindow& window);
    void getEnemyPosition(); 
    void collision(std::vector<Enemy>& enemyVec, std::vector<Bullet>& bulletVec, int& score);
    sf::Vector2f enemyPosition;
    sf::FloatRect enemyBounds;
};
#endif
