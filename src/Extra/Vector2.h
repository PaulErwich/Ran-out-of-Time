#//
// Created by MLG Erwich on 05/08/2022.
//

#ifndef SFMLTEMPLATE_VECTOR2_H
#define SFMLTEMPLATE_VECTOR2_H

struct Vector2
{
  // construction
  Vector2();
  Vector2(float x_, float y_);
  Vector2(const Vector2& rhs);

  // operations
  Vector2 operator*(float scalar);
  Vector2& operator=(const Vector2& rhs);
  void normalise();

  // data
  float x;
  float y;
};

#endif // SFMLTEMPLATE_VECTOR2_H
