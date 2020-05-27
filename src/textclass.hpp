#ifndef SCORE_HPP
#define SCORE_HPP

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>

class TextClass
{
private:
    sf::Font font;
    sf::Text scoreText;
    sf::Text healthText;

public:
    TextClass();
    void drawScore(sf::RenderWindow& window, int& score);
    void drawHealth(sf::RenderWindow& window, int& health);

};
#endif
