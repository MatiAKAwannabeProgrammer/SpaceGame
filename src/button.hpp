#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
class Button
{
private:
    sf::Sprite buttonModel;
    sf::Texture buttonTextureHover;
    sf::Texture butttonTextureNoHover;
    sf::FloatRect buttonBounds;

public:
    Button();
    void drawButton(sf::RenderWindow& window);
    void setTextureHover();
    void setTextureNoHover();

};
#endif
