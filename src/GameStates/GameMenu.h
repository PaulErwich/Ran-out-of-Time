//
// Created by MLG Erwich on 31/07/2022.
//

#ifndef SFMLTEMPLATE_GAMEMENU_H
#define SFMLTEMPLATE_GAMEMENU_H

#include "GameStateBase.h"

#include "../Extra/Helper.h"

class GameMenu : public GameStateBase
{
 public:
  GameMenu(STATE state_id, sf::RenderWindow& game_window, sf::Font& game_font);
  ~GameMenu() = default;

  bool init() override;
  void reset() override;
  void input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;

 private:
  sf::Text text_title;
  sf::Text text_play;
  sf::Text text_exit;
};

#endif // SFMLTEMPLATE_GAMEMENU_H
