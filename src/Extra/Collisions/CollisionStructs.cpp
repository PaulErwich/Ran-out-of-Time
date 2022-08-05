//
// Created by MLG Erwich on 05/08/2022.
//

#include "CollisionStructs.h"

Object_Manifold::Object_Manifold()
{
  A = nullptr;
  B = nullptr;

  penetration = 0;
}

Object_Manifold::Object_Manifold(GameObject* a, GameObject* b)
{
  A = a;
  B = b;

  penetration = 0;
}