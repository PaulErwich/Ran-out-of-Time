//
// Created by MLG Erwich on 05/08/2022.
//

#ifndef SFMLTEMPLATE_COLLISIONSTRUCTS_H
#define SFMLTEMPLATE_COLLISIONSTRUCTS_H

#include "../Vector2.h"
#include "../../GameObjects/GameObject.h"

struct AABB
{
  Vector2 min = Vector2();
  Vector2 max = Vector2();
};

struct Object_Manifold
{
  Object_Manifold();
  Object_Manifold(GameObject *a, GameObject *b);

  GameObject *A;
  GameObject *B;

  float penetration;
  Vector2 normal;
};

#endif // SFMLTEMPLATE_COLLISIONSTRUCTS_H
