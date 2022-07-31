//
// Created by MLG Erwich on 31/07/2022.
//

#ifndef SFMLTEMPLATE_GAMEOVER_H
#define SFMLTEMPLATE_GAMEOVER_H

#include "GameStateBase.h"

class GameOver : public GameStateBase
{
 public:
  GameOver(STATE state_id, sf::RenderWindow& game_window, sf::Font& game_font);
  ~GameOver() = default;

  bool init() override;
  void reset() override;
  void input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;

 private:
  sf::Text text_lose;
  sf::Text return_to_menu;
};

#endif // SFMLTEMPLATE_GAMEOVER_H
