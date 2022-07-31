//
// Created by MLG Erwich on 31/07/2022.
//

#ifndef SFMLTEMPLATE_GAMEPLAY_H
#define SFMLTEMPLATE_GAMEPLAY_H

#include "GameStateBase.h"

class GamePlay : public GameStateBase
{
 public:
  GamePlay(STATE state_id, sf::RenderWindow& game_window, sf::Font& game_font);
  ~GamePlay() = default;

  bool init() override;
  void reset() override;
  void input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;
};

#endif // SFMLTEMPLATE_GAMEPLAY_H
