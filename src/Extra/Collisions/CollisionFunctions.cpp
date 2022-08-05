//
// Created by MLG Erwich on 05/08/2022.
//

#include "CollisionFunctions.h"

bool AABBvsAABB_MK3(Object_Manifold *m)
{
  AABB abox;
  abox.min = m->A->getMin();
  abox.max = m->A->getMax();

  AABB bbox;
  bbox.min = m->B->getMin();
  bbox.max = m->B->getMax();

  float x_pen = 0, y_pen = 0;
  bool right = false, bottom = false;

  if ((bbox.min.x < abox.min.x && abox.min.x < bbox.max.x))
  {

    x_pen = bbox.max.x - abox.min.x;
    right = true;
  }
  else if (bbox.min.x < abox.max.x && abox.max.x < bbox.max.x)
  {
    x_pen = abox.max.x - bbox.min.x;
  }

  if (bbox.min.y < abox.min.y && abox.min.y < bbox.max.y)
  {

    y_pen = bbox.max.y - abox.min.y;
    bottom = true;
  }
  else if (bbox.min.y < abox.max.y && abox.max.y < bbox.max.y)
  {

    y_pen = abox.max.y - bbox.min.y;
  }

  if (x_pen == 0 || y_pen == 0)
  {
    return false;
  }
  else
  {
    if (x_pen < y_pen)
    {
      if (right)
      {
        m->normal = Vector2(-1, 0);
      }
      else
      {
        m->normal = Vector2(1, 0);
      }
    }
    else
    {
      if (bottom)
      {
        m->normal = Vector2(0, -1);
      }
      else
      {
        m->normal = Vector2(0, 1);
      }
    }
    return true;
  }
}