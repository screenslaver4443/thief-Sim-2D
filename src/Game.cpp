//
// Created by Nikolai Pesudovs on 14/10/2025.
//
#include "game.h"
#include "GameStateSaver.h"

// constructor
Game::Game(sf::RenderWindow &win)
    : window(win), state(GameState::MAIN_MENU),
      levelsBeaten(0), suspicion(0), heartsRemaining(3),
      suspicionTimer(0.f)
{
    // erm sprite stuff
    // tests if they all load in and pukks them from sprites folder
    if (!playerTex.loadFromFile("sprites/player.png"))
        std::cout << "failed player\n";
    if (!buttonTex.loadFromFile("sprites/button.png"))
        std::cout << "failed button\n";
    if (!heartTex.loadFromFile("sprites/healthBar.png"))
        std::cout << "failed heart\n";
    if (!diamondTex.loadFromFile("sprites/loot.png"))
        std::cout << "failed diamond\n";

    player.setTexture(playerTex);
    button.setTexture(buttonTex);
    heart.setTexture(heartTex);
    diamond.setTexture(diamondTex);

    // sizes stuff
    player.setScale(0.05f, 0.05f);
    button.setScale(0.05f, 0.05f);
    heart.setScale(0.05f, 0.05f);
    diamond.setScale(0.025f, 0.025f);

    // Initialize playerObj position and sync with sprite
    playerObj.setPosX(100);
    playerObj.setPosY(400);
    player.setPosition(playerObj.getPosX(), playerObj.getPosY());

    // set player's object size to match the sprite (scaled)
    playerObj.setSize(playerTex.getSize().x * 0.05f, playerTex.getSize().y * 0.05f);
    button.setPosition(350, 350);
    heart.setPosition(20, 20);
    diamond.setPosition(600, 400);

    // life system (ie 3 is max health)
    for (int i = 0; i < 3; ++i)
    {
        hearts[i].setTexture(heartTex);
        hearts[i].setScale(0.015f, 0.015f);
        hearts[i].setPosition(30 + i * 70, 20);
    }

    // back to menu thingy
    menuButton.setTexture(buttonTex);
    menuButton.setScale(0.04f, 0.04f);
    int menuButtonX = 700, menuButtonY = 15;
    menuButton.setPosition(menuButtonX, menuButtonY);

    // Load system font - try macOS fonts first, then Linux fallback
    if (!font.loadFromFile("/System/Library/Fonts/Helvetica.ttc") &&
        !font.loadFromFile("/System/Library/Fonts/HelveticaNeue.ttc") &&
        !font.loadFromFile("/System/Library/Fonts/Menlo.ttc") &&
        !font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"))
        std::cout << "Missing font file! Tried Helvetica, Helvetica Neue, Menlo, and DejaVu Sans\n";

    menuText.setFont(font);
    menuText.setString("Menu");
    menuText.setCharacterSize(20);
    menuText.setFillColor(sf::Color::Black);
    menuText.setPosition(menuButtonX + 50, menuButtonY + 15);

    // tracks levels beaten in a session :3
    diamondIcon.setTexture(diamondTex);
    diamondIcon.setScale(0.04f, 0.04f);
    diamondIcon.setPosition(500, 180);

    diamondCount.setFont(font);
    diamondCount.setCharacterSize(28);
    diamondCount.setFillColor(sf::Color::Black);
    diamondCount.setPosition(550, 140);
    diamondCount.setString("x 0");

    // Save/Load buttons
    saveButton.setTexture(buttonTex);
    saveButton.setScale(0.05f, 0.05f);
    saveButton.setPosition(20, 500);
    // no separate load button (autosave loaded at startup)
    resetButton.setTexture(buttonTex);
    resetButton.setScale(0.05f, 0.05f);
    resetButton.setPosition(300, 500);

    saveText.setFont(font);
    saveText.setString("Save");
    saveText.setCharacterSize(18);
    saveText.setFillColor(sf::Color::Black);
    saveText.setPosition(30, 525);

    resetText.setFont(font);
    resetText.setString("Reset");
    resetText.setCharacterSize(18);
    resetText.setFillColor(sf::Color::Black);
    resetText.setPosition(310, 525);

    // register GameStateSaver to persist diamond/levelsBeaten
    static GameStateSaver gsSaver;
    gsSaver.setTarget(&levelsBeaten);
    saveManager.registerSavable(&gsSaver);

    // Do NOT register playerObj anymore — we only persist diamonds
    // On startup, attempt to load saved gamestate automatically
    if (saveManager.loadAll("."))
        std::cout << "Loaded saved game state (auto)\n";

    // levelzzzzz
    for (int i = 0; i < 3; ++i)
    {
        levelButtons[i].setTexture(buttonTex);
        levelButtons[i].setScale(0.07f, 0.07f);
        levelButtons[i].setPosition(120, 150 + i * 100);

        levelText[i].setFont(font);
        levelText[i].setString("Level " + std::to_string(i + 1));
        levelText[i].setCharacterSize(26);
        levelText[i].setFillColor(sf::Color::Black);

        sf::FloatRect textBounds = levelText[i].getLocalBounds();
        sf::FloatRect buttonBounds = levelButtons[i].getGlobalBounds();

        levelText[i].setPosition(
            buttonBounds.left + (buttonBounds.width - textBounds.width) / 2.f,
            buttonBounds.top + (buttonBounds.height - textBounds.height) / 2.f - 8.f);
    }

    // Initialize levels and set default active level to levelOne (first level)
    levelOne.load();
    levelTwo.load();
    levelThree.load();
    activeLevel = &levelOne; // default already created

    // Register savable objects
    saveManager.registerSavable(&playerObj);
}

// sorry I had return a layer deeper bf my bad
void Game::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        // keyboard shortcuts handled here
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::S)
            {
                bool ok = saveManager.saveAll(".");
                std::cout << (ok ? "Saved all savable objects\n" : "Failed to save all\n");
            }
            else if (event.key.code == sf::Keyboard::L)
            {
                bool ok = saveManager.loadAll(".");
                std::cout << (ok ? "Loaded all savable objects\n" : "Failed to load all\n");
                // sync sprite after loading
                player.setPosition(playerObj.getPosX(), playerObj.getPosY());
            }
            else if (event.key.code == sf::Keyboard::D)
            {
                debugEnabled = !debugEnabled;
                std::cout << "Debug overlay " << (debugEnabled ? "enabled\n" : "disabled\n");
            }
        }

        // please work oh god im gonna cry please work
        if (state == GameState::MAIN_MENU && event.type == sf::Event::MouseButtonPressed)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            // check save/load buttons first
            if (saveButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
                bool ok = saveManager.saveAll(".");
                std::cout << (ok ? "Saved all savable objects\n" : "Failed to save all\n");
                continue;
            }
            // no load button here (autosave loaded at startup)
            if (resetButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
                levelsBeaten = 0;
                std::cout << "Diamonds reset to 0\n";
                // save new gamestate immediately
                saveManager.saveAll(".");
                continue;
            }
            for (int i = 0; i < 3; ++i)
            {
                if (levelButtons[i].getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    std::cout << "Starting Level " << i + 1 << "!\n";
                    state = GameState::LEVEL;
                    suspicion = 0;
                    heartsRemaining = 3;
                    playerObj.setPosX(100);
                    playerObj.setPosY(400);
                    player.setPosition(playerObj.getPosX(), playerObj.getPosY());
                    // set the active level based on selection
                    if (i == 0)
                        activeLevel = &levelOne;
                    else if (i == 1)
                        activeLevel = &levelTwo;
                    else if (i == 2)
                        activeLevel = &levelThree;

                    // Reset and reload the chosen level so entities and timers start fresh
                    if (activeLevel)
                    {
                        activeLevel->load();
                        suspicionTimer = 0.f;
                        // reset player speed to default on level start
                        playerObj.setSpeed(200.0f);
                    }
                }
            }
        }

        if (state == GameState::LEVEL && event.type == sf::Event::MouseButtonPressed)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            // in-level clicks (menu positioned in-level)
            if (menuButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
                state = GameState::MAIN_MENU;
                // reset active level so it starts fresh next time
                if (activeLevel)
                {
                    activeLevel->load();
                    suspicionTimer = 0.f;
                }
            }
        }
    }
}

void Game::update()
{
    // frame delta
    float deltaTime = clock.restart().asSeconds();

    // movement controls for da playuh
    if (state == GameState::LEVEL)
    {
        // Use deltaTime-based speeds (units per second) from player object
        float speed = playerObj.getSpeed();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            playerObj.setPosX(playerObj.getPosX() - speed * deltaTime);
            player.setPosition(playerObj.getPosX(), playerObj.getPosY());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            playerObj.setPosX(playerObj.getPosX() + speed * deltaTime);
            player.setPosition(playerObj.getPosX(), playerObj.getPosY());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            playerObj.setPosY(playerObj.getPosY() - speed * deltaTime);
            player.setPosition(playerObj.getPosX(), playerObj.getPosY());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            playerObj.setPosY(playerObj.getPosY() + speed * deltaTime);
            player.setPosition(playerObj.getPosX(), playerObj.getPosY());
        }

        // Global suspicion only accrues when current level has an Employee
        if (activeLevel && activeLevel->hasEmployee())
        {
            suspicionTimer += deltaTime;
            if (suspicionTimer > 1.0f)
            {
                suspicion++;
                suspicionTimer = 0.f;
                std::cout << "Suspicion: " << suspicion << "\n";

                if (suspicion >= 10)
                {
                    suspicion = 0;
                    heartsRemaining--;
                    std::cout << "Heart lost, " << heartsRemaining << " left \n";

                    if (heartsRemaining <= 0)
                    {
                        std::cout << "ya got caught gang :(\n";
                        heartsRemaining = 3;
                        suspicion = 0;
                        playerObj.setPosX(100);
                        playerObj.setPosY(400);
                        player.setPosition(playerObj.getPosX(), playerObj.getPosY());
                        state = GameState::MAIN_MENU;
                    }
                }
            }
        }

        // win
        if (player.getGlobalBounds().intersects(diamond.getGlobalBounds()))
        {
            state = GameState::VICTORY;
            levelsBeaten++;

            // autosave diamonds when obtained
            if (!saveManager.saveAll("."))
                std::cout << "Warning: failed to autosave gamestate\n";

            playerObj.setPosX(100);
            playerObj.setPosY(400);
            player.setPosition(playerObj.getPosX(), playerObj.getPosY());
            diamond.setPosition(600, 400);
        }
        // Forward update to active level (if any)
        if (activeLevel)
            activeLevel->update(deltaTime, playerObj);

        // Update any player buff timers
        playerObj.updateBuff(deltaTime);

        // If player died (health <= 0) return to main menu
        if (playerObj.getHealth() <= 0)
        {
            std::cout << "Player died — returning to menu\n";
            state = GameState::MAIN_MENU;
            playerObj.setHealth(100);
            playerObj.setPosX(100);
            playerObj.setPosY(400);
            player.setPosition(playerObj.getPosX(), playerObj.getPosY());
            // Reload the active level so NPC positions and timers reset
            if (activeLevel)
            {
                activeLevel->load();
            }
            suspicionTimer = 0.f;
            // reset player speed to default
            playerObj.setSpeed(200.0f);
        }

        // If player was just healed by ally, restore some UI or hearts
        if (playerObj.getJustHealed())
        {
            // restore hearts UI to max (this is a simple behavior)
            heartsRemaining = 3;
            playerObj.setJustHealed(false);
        }
    }
}

void Game::render()
{
    // preeety backgrounf
    if (state == GameState::VICTORY)
        window.clear(sf::Color(255, 255, 150)); // yellow i think
    else
        window.clear(sf::Color(245, 245, 245)); // white

    if (state == GameState::MAIN_MENU)
    {
        for (int i = 0; i < 3; ++i)
        {
            window.draw(levelButtons[i]);
            window.draw(levelText[i]);
        }

        window.draw(diamondIcon);
        diamondCount.setString("x " + std::to_string(levelsBeaten));
        window.draw(diamondCount);
        // Save/Reset buttons in menu
        window.draw(saveButton);
        window.draw(saveText);
        window.draw(resetButton);
        window.draw(resetText);
    }
    else if (state == GameState::LEVEL)
    {
        for (int i = 0; i < heartsRemaining; ++i)
            window.draw(hearts[i]);
        window.draw(menuButton);
        window.draw(menuText);
        window.draw(player);
        window.draw(diamond);
        // Draw active level-specific sprites/entities
        if (activeLevel)
            activeLevel->draw(window);

        // (no save/reset buttons in-level)

        // debug overlay
        if (debugEnabled)
        {
            sf::Text dbg(playerObj.toString(), font, 14);
            dbg.setFillColor(sf::Color::Red);
            dbg.setPosition(10, 500);
            window.draw(dbg);
        }
    }
    else if (state == GameState::VICTORY)
    {
        // YOU WON GANG screen
        sf::Text title("Oh em gee\nYOU WON!", font, 60);
        title.setFillColor(sf::Color::Black);
        title.setPosition(220, 150);

        sf::Sprite backButton(buttonTex);
        backButton.setScale(0.07f, 0.07f);
        backButton.setPosition(250, 320);
        sf::Text backText("Back To Levels", font, 30);
        backText.setFillColor(sf::Color::Black);
        backText.setPosition(260, 330);

        sf::Text msg("Your diamond has been added \nto your total!", font, 24);
        msg.setFillColor(sf::Color::Black);
        msg.setPosition(230, 440);

        window.draw(title);
        window.draw(backButton);
        window.draw(backText);
        window.draw(msg);

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::FloatRect backButtonRect(260, 310, 190, 50);
            if (backButtonRect.contains(mousePos.x, mousePos.y))
                state = GameState::MAIN_MENU;
        }
    }

    window.display();
}
