#include "Game.h"

Game::Game() :
    window(VideoMode({ 800, 600 }), "Joc de Plataformes Simple"),
    player(100, 100),
    bob(150, 100),
    font("KOMIKAP_.ttf"),
    instructionsText(font),
    pauseText(font),
    amplada(800),
    alcada(600),
    isPaused(false)
{
    window.setFramerateLimit(60);

    if (levelLoader.loadFromFile("level1.txt", window)) {
        player.setPosition(levelLoader.getPlayerStartPosition().x,
            levelLoader.getPlayerStartPosition().y);
        bob.setPosition(levelLoader.getPlayerStartPosition().x + 60,
            levelLoader.getPlayerStartPosition().y);
    }

    // Text d'instruccions
    instructionsText.setString(
        "Thomas (VERD): WASD | Bob (BLAU): Fletxes\n"
        "Arribeu tots dos a la meta groga!\n"
        "Eviteu els enemics! | Prem P per pausar"
    );
    instructionsText.setCharacterSize(16);
    instructionsText.setFillColor(Color::Black);
    instructionsText.setPosition(sf::Vector2f(10.f, 10.f));

    // Text de pausa
    pauseText.setString("PAUSA\n\nPrem P per continuar");
    pauseText.setCharacterSize(60);
    pauseText.setFillColor(Color::White);
    pauseText.setStyle(Text::Bold);
    pauseText.setOutlineColor(Color::Black);
    pauseText.setOutlineThickness(3);

    // Centrar el text de pausa (CORRECTE)
    FloatRect textBounds = pauseText.getLocalBounds();
    pauseText.setOrigin(sf::Vector2f(
        textBounds.size.x / 2.f,
        textBounds.size.y / 2.f
    ));
    pauseText.setPosition(sf::Vector2f(400.f, 300.f));

    // Crear enemics
    createEnemies();
}

Game::~Game() {
    clearEnemies();
}

void Game::run() {
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();

        handleEvents();
        update(dt);
        draw();
    }
}

void Game::handleEvents() {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<Event::Closed>()) {
            window.close();
        }

        if (const auto* key = event->getIf<Event::KeyPressed>()) {
            if (key->scancode == Keyboard::Scancode::Escape) {
                window.close();
            }

            if (key->scancode == Keyboard::Scancode::P) {
                togglePause();
            }
        }
    }

    // Input només si NO està en pausa
    if (!isPaused) {
        player.handleInput();
        bob.handleInput();
    }
}

void Game::update(float dt) {
    if (isPaused) {
        return;
    }

    player.update(dt, window.getSize().x, window.getSize().y);
    bob.update(dt, window.getSize().x, window.getSize().y);
    levelLoader.update(dt);

    for (Enemy* enemy : enemies) {
        enemy->update(dt);
    }

    checkCollisions(player);
    checkCollisions(bob);
    checkEnemyCollisions();
    checkGoal(levelLoader.getGoal());
}

void Game::draw() {
    window.clear(Color::White);

    levelLoader.draw(window);

    for (Enemy* enemy : enemies) {
        enemy->draw(window);
    }

    player.draw(window);
    bob.draw(window);

    window.draw(instructionsText);

    if (isPaused) {
        RectangleShape overlay(sf::Vector2f(
            static_cast<float>(window.getSize().x),
            static_cast<float>(window.getSize().y)
        ));
        overlay.setFillColor(Color(0, 0, 0, 150));
        window.draw(overlay);

        window.draw(pauseText);
    }

    window.display();
}

void Game::checkCollisions(Character& character) {
    FloatRect charBounds = character.getBounds();
    std::vector<Platform> platforms = levelLoader.getPlatforms();

    for (auto& platform : platforms) {
        FloatRect platformBounds = platform.getBounds();

        if (const std::optional intersection =
            charBounds.findIntersection(platformBounds)) {

            if (charBounds.position.y < platformBounds.position.y &&
                charBounds.position.y + charBounds.size.y <
                platformBounds.position.y + 15) {

                character.stopFalling(
                    platformBounds.position.y - charBounds.size.y
                );
            }
        }
    }
}

void Game::checkGoal(Platform goal) {
    if (player.getBounds().findIntersection(goal.getBounds()) &&
        bob.getBounds().findIntersection(goal.getBounds())) {

        std::cout << "Felicitats! Tots dos heu arribat a la meta!" << std::endl;

        if (levelLoader.loadFromFile("level2.txt", window)) {
            player.setPosition(levelLoader.getPlayerStartPosition().x,
                levelLoader.getPlayerStartPosition().y);
            bob.setPosition(levelLoader.getPlayerStartPosition().x + 60,
                levelLoader.getPlayerStartPosition().y);

            clearEnemies();
            createEnemies();
        }
    }
}

void Game::createEnemies() {
    enemies.push_back(new PatrolEnemy(200, 400, 150, 350, 100.0f));
    enemies.push_back(new PatrolEnemy(450, 300, 400, 600, 80.0f));
    enemies.push_back(new PatrolEnemy(100, 200, 50, 250, 120.0f));

    enemies.push_back(new FlyingEnemy(500, 150, 100, 400, 90.0f));
    enemies.push_back(new FlyingEnemy(300, 200, 150, 450, 70.0f));

    std::cout << "Creats " << enemies.size() << " enemics al nivell" << std::endl;
}

void Game::clearEnemies() {
    for (Enemy* enemy : enemies) {
        delete enemy;
    }
    enemies.clear();
}

void Game::checkEnemyCollisions() {
    for (Enemy* enemy : enemies) {
        if (enemy->checkCollisionWithCharacter(player.getBounds())) {
            std::cout << "Thomas ha tocat un enemic! Reiniciant..." << std::endl;
            player.setPosition(levelLoader.getPlayerStartPosition().x,
                levelLoader.getPlayerStartPosition().y);
        }

        if (enemy->checkCollisionWithCharacter(bob.getBounds())) {
            std::cout << "Bob ha tocat un enemic! Reiniciant..." << std::endl;
            bob.setPosition(levelLoader.getPlayerStartPosition().x + 60,
                levelLoader.getPlayerStartPosition().y);
        }
    }
}

void Game::togglePause() {
    isPaused = !isPaused;

    if (isPaused) {
        std::cout << "JOC EN PAUSA" << std::endl;
    }
    else {
        std::cout << "JOC REPRÈS" << std::endl;
    }
}
