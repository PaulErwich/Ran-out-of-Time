//
// Created by MLG Erwich on 05/08/2022.
//

#ifndef SFMLTEMPLATE_ENTITY_H
#define SFMLTEMPLATE_ENTITY_H

#include "../GameObject.h"

class Entity : public GameObject
{
 public:
  Entity(sf::RenderWindow& game_window);
  virtual bool init(float x, float y);

  virtual void update(float dt, GameObject* ground);

 protected:

};

#endif // SFMLTEMPLATE_ENTITY_H
