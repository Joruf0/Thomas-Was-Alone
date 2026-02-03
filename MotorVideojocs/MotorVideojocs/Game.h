#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Thomas.h"
#include "Bob.h"
#include "Platform.h"
#include "Enemy.h"
#include "PatrolEnemy.h"
#include "FlyingEnemy.h"

using namespace std;
using namespace sf;

// Classe principal del joc
class Game {
private: //dades
    RenderWindow window;
    Thomas player;
    Bob bob;
    Clock clock;
    Font font;
    Text instructionsText;
    Text pauseText;
    PlatformMap levelLoader;
    unsigned int amplada;
    unsigned int alcada;
    vector<Enemy*> enemies;  // Vector de punters a enemics
    bool isPaused;  // Estat de pausa del joc

public://metodes
    Game();
    ~Game();  // Destructor per alliberar memòria
    void run();

private: //metodes
    void handleEvents();
    void update(float dt);
    void draw();
    void checkCollisions(Character& character);
    void checkGoal(Platform goal);
    void createEnemies();
    void clearEnemies();
    void checkEnemyCollisions();
    void togglePause();


};