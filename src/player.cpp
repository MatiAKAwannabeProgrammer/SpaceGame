#include "player.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

Player::Player()
{
    playerModel.setPosition(sf::Vector2f(400.f, 550.f));
    playerTexture.loadFromFile("./content/player.png");
    playerModel.setTexture(playerTexture);
    speed = 400;
    playerBounds = playerModel.getGlobalBounds();
}

void Player::playerMovement(float& deltaTime, sf::Vector2f& currentPos)
{
    // Movement implementation.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && currentPos.x > 0)
        playerModel.move(-speed * deltaTime, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && currentPos.x < 800 - playerBounds.width)
        playerModel.move(speed * deltaTime, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && currentPos.y > 0)
        playerModel.move(0, -speed * deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && currentPos.y < 600 - playerBounds.height)
        playerModel.move(0, speed * deltaTime);
}

void Player::playerShooting(bool& isFired, sf::Clock& bulletClock, sf::Time& bulletTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bulletTime.asMilliseconds() >= 100)
    {
        bulletClock.restart();
        isFired = true;
    }
}

void Player::drawPlayer(sf::RenderWindow& window)
{
    window.draw(playerModel);
}

void Player::getPlayerPos()
{
    playerPosition = playerModel.getPosition();
}
