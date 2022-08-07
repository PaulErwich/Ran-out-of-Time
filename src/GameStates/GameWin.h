//
// Created by MLG Erwich on 31/07/2022.
//

#ifndef SFMLTEMPLATE_GAMEWIN_H
#define SFMLTEMPLATE_GAMEWIN_H

#include "GameStateBase.h"

#include "../Extra/Helper.h"

class GameWin : public GameStateBase
{
 public:
  GameWin(STATE state_id, sf::RenderWindow& game_window, sf::Font& game_font);
  ~GameWin() = default;

  bool init() override;
  void reset() override;
  void input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;


 private:
  sf::Text text_win;
  sf::Text return_to_menu;
  sf::Sprite sprite;
  sf::Texture texture;
};

#endif // SFMLTEMPLATE_GAMEWIN_H
