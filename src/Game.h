#ifndef SFMLTEMPLATE_GAME_H
#define SFMLTEMPLATE_GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Extra/Helper.h"

#include "GameStates/GameStateBase.h"
#include "GameStates/GameMenu.h"
#include "GameStates/GamePlay.h"
#include "GameStates/GameOver.h"
#include "GameStates/GameWin.h"


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

  GameMenu* game_menu;
  GamePlay* game_play;
  GameOver* game_over;
  GameWin* game_win;

  GameStateBase* current_state;
};


#endif //SFMLTEMPLATE_GAME_H
