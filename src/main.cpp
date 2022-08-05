#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
    std::cout << "A window should open alongside the console" << std::endl;

    // Create window and setup
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFMLTemplate");
    window.setFramerateLimit(60);

    // Initialise an instance of the game
    Game game(window);

    if (!game.init())
    {
      std::cout << "INIT FAILED" << std::endl;
      return 0;
    }

    // Clock which starts when it's created
    sf::Clock clock;

    //Game loop: run game as long as the window is open
    while(window.isOpen())
    {
      // check all window events that were triggered since last iteration of loop
      sf::Event event;

      // calculate delta time
      sf::Time time = clock.restart();
      float dt = time.asSeconds();

      // 'process inputs' element of game loop
      while (window.pollEvent(event))
      {
        // 'close requested' event: close the window
        if (event.type == sf::Event::Closed) window.close();

        if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::KeyPressed ||
            event.type == sf::Event::KeyReleased || event.type == sf::Event::MouseMoved)
        {
          game.input(event);
        }
      }

      // update the game
      game.update(dt);

      window.clear(sf::Color(128, 128, 128));

      // render the game
      game.render();
      window.display();
    }

    return 0;
}
