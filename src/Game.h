//
// Created by MLG Erwich on 29/07/2022.
//

#ifndef SFMLTEMPLATE_GAME_H
#define SFMLTEMPLATE_GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>


class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void input(sf::Event event);
  void update(float dt);
  void render();

 private:
  sf::RenderWindow& window;

  sf::Font font;

  sf::Text text;
};


#endif //SFMLTEMPLATE_GAME_H
