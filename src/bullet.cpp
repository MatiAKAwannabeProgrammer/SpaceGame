#include "bullet.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

Bullet::Bullet(sf::Vector2f& playerPos)
{
    bulletModel.setPosition(playerPos.x +16, playerPos.y);
    bulletTexture.loadFromFile("./content/bullet.png");
    bulletModel.setTexture(bulletTexture);
    speed = 500.f;
}

void Bullet::updateBullet(float& deltaTime)
{
    bulletModel.move(0, -speed * deltaTime);
}

void Bullet::drawBullet(sf::RenderWindow& window)
{
    window.draw(bulletModel);
}

void Bullet::getBulletPos()
{
    bulletPosition = bulletModel.getPosition();
}
