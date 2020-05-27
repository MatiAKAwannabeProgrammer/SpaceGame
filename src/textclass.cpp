#include "textclass.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

TextClass::TextClass()
{
    font.loadFromFile("./content/arial_narrow_7.ttf");

    scoreText.setPosition(sf::Vector2f(10.f, 10.f));
    scoreText.setFont(font);
    scoreText.setFillColor(sf::Color(sf::Color::Cyan));
    scoreText.setCharacterSize(24);

    healthText.setPosition(sf::Vector2f(10.f, 30.f));
    healthText.setFont(font);
    healthText.setFillColor(sf::Color(sf::Color::Red));
    healthText.setCharacterSize(24);
}

void TextClass::drawScore(sf::RenderWindow& window, int& score)
{
    scoreText.setString("Score: " + std::to_string(score));
    window.draw(scoreText);
} 

void TextClass::drawHealth(sf::RenderWindow& window, int& health)
{
    healthText.setString("Health: " + std::to_string(health));
    window.draw(healthText);
}
