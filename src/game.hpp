#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>
#include "player.hpp"
#include "map.hpp"
#include "bullet.hpp"
#include "enemy.hpp"
#include "textclass.hpp"
#include "button.hpp"

class Game
{
private:

    // Objects.
    sf::RenderWindow window;
    sf::Event event;
    Player player;
    sf::Clock deltaClock;
    sf::Clock bulletClock;
    sf::Time bulletTime;
    sf::Clock enemyClock;
    sf::Time enemyTime;
    Map map;
    Bullet* bullet;
    Enemy* enemy;
    TextClass score;
    TextClass health;
    Button* startButton;
    Button* exitGame;

    // Variables.
    sf::Vector2f currentPlayerPos;
    float deltaTime;
    std::vector<Bullet> bulletVec;
    std::vector<Enemy> enemyVec;
    bool isFired;
    float enemySpawnTimer;
    int levelInt;
    int scoreInt;
    int healthInt;

public:
    Game();
    bool running();
    void pollEvents();
    void update();
    void render();
    void createBullet();
    void updateBullet();
    void drawBullet();
    void createEnemy();
    void updateEnemy();
    void drawEnemy();
    void level();
    void increaseDifficulty();
};
#endif
