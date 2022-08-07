//
// Created by MLG Erwich on 31/07/2022.
//

#ifndef SFMLTEMPLATE_GAMEPLAY_H
#define SFMLTEMPLATE_GAMEPLAY_H

#include "GameStateBase.h"

#include "../GameObjects/Entities/Player.h"
#include "../GameObjects/Entities/Enemy.h"

#include "../GameObjects/Level.h"
#include "../GameObjects/Spring.h"

class GamePlay : public GameStateBase
{
 public:
  GamePlay(STATE state_id, sf::RenderWindow& game_window, sf::Font& game_font);
  ~GamePlay();

  bool init() override;
  void reset() override;
  void input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;
  void checkSpringCollisions(float dt);

 private:
  static const int enemy_count = 4;
  static const int spring_count = 4;

  Player *player;
  Enemy* enemy[enemy_count]{};
  Spring* springs[spring_count]{};

  Level* level;

  sf::View new_view;



};

#endif // SFMLTEMPLATE_GAMEPLAY_H
