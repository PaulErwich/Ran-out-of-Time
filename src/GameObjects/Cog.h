//
// Created by MLG Erwich on 07/08/2022.
//

#ifndef SFMLTEMPLATE_COG_H
#define SFMLTEMPLATE_COG_H

#include "GameObject.h"

class Cog : public GameObject
{
 public:
  Cog(sf::RenderWindow& game_window);
  bool init(float x, float y);
};

#endif // SFMLTEMPLATE_COG_H
