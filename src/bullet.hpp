#ifndef BULLET_HPP 
#define BULLET_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
class Bullet
{
private:
    sf::Sprite bulletModel;
    sf::Texture bulletTexture;
    float speed;

public:
    Bullet(sf::Vector2f& playerPos);
    void updateBullet(float& deltaTime);
    void drawBullet(sf::RenderWindow& window);
    void getBulletPos();
    sf::Vector2f bulletPosition;
};
#endif
