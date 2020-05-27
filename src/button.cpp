#include "button.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

Button::Button()
{
    buttonTextureHover.loadFromFile("./content/buttonHover.png");
    butttonTextureNoHover.loadFromFile("./content/button.png");
}

void Button::drawButton(sf::RenderWindow& window)
{
    buttonBounds = buttonModel.getGlobalBounds();
    window.draw(buttonModel);
}

void Button::setTextureHover()
{
    buttonModel.setTexture(buttonTextureHover);    
}

void Button::setTextureNoHover()
{
    buttonModel.setTexture(butttonTextureNoHover);
}
