//
// Created by MLG Erwich on 05/08/2022.
//

#ifndef SFMLTEMPLATE_PLAYER_H
#define SFMLTEMPLATE_PLAYER_H

#include "Entity.h"

class Player : public Entity
{
 public:
  Player(sf::RenderWindow& game_window);
  bool init() override;

  void reset();

  void setOnGround(bool _on_ground);

  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);

  void update(float dt) override;

 private:
  bool on_ground;
  const int SPEED = 100;
};

#endif // SFMLTEMPLATE_PLAYER_H
