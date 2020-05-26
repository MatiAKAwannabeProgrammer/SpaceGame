#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
class Player 
{
private:
    sf::Sprite playerModel;
    sf::Texture playerTexture;
    float speed;
    sf::FloatRect playerBounds;

public:
    Player();
    void drawPlayer(sf::RenderWindow& window);
    void playerMovement(float& deltaTime, sf::Vector2f& currentPos);
    void playerShooting(bool& isFired, sf::Clock& bulletClock, sf::Time& bulletTime);
    void getPlayerPos();
    sf::Vector2f playerPosition;
};
#endif
