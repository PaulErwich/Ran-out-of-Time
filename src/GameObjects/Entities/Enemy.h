
#ifndef SFMLTEMPLATE_ENEMY_H
#define SFMLTEMPLATE_ENEMY_H

#include "Entity.h"

class Enemy: public Entity
{
 public:
  Enemy(sf::RenderWindow& game_window);
  bool init(float x, float y) override;
  void update(float dt) override;

 private:
 int getHealth() const;
 void setHealth(int _health);
 float enemySpeed = 50;
 int health;

};

#endif // SFMLTEMPLATE_ENEMY_H
