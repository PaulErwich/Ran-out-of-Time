#include "Vector2.h"
#include <math.h>
#include <iostream>

Vector2::Vector2()
{
  x = 0;
  y = 0;
}
/**
 *   @brief   Constructor.
 *   @details Requires values for it's x and y magnitudes.
 *   @return  void
 */
Vector2::Vector2(float x_, float y_) : x(x_), y(y_) {}

/**
 *   @brief   Copies a velocity.
 *   @details Constructs a new Vector2 from an existing.
 *   @return  void
 */
Vector2::Vector2(const Vector2& rhs)
{
  this->x = rhs.x;
  this->y = rhs.y;
}

/**
 *   @brief   Copies a velocity.
 *   @details Updates Vector2 from an existing.
 *   @return  void
 */
Vector2& Vector2::operator=(const Vector2& rhs)
{
  this->x = rhs.x;
  this->y = rhs.y;

  return *this;
}

/**
 *   @brief   Normalises velocity.
 *   @details Turns the velocity into a unit velocity.
 *   @return  void
 */
void Vector2::normalise()
{
  float magnitude = sqrtf((x * x) + (y * y));

  if (!magnitude)
  {
    std::cout << "no division\n";
    return;
  }

  x /= magnitude;
  y /= magnitude;
}

/**
 *   @brief   Scales the velocity.
 *   @details Uses a single scalar value to adjust the velocity.
 *   @return  void
 */
Vector2 Vector2::operator*(float scalar)
{
  Vector2 vec(*this);
  vec.x *= scalar;
  vec.y *= scalar;
  return vec;
}