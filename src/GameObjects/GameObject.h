//
// Created by MLG Erwich on 05/08/2022.
//

#ifndef SFMLTEMPLATE_GAMEOBJECT_H
#define SFMLTEMPLATE_GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Extra/Vector2.h"

class GameObject
{
 public:
  GameObject(sf::RenderWindow& game_window);
  ~GameObject();
  sf::Sprite* getSprite();

  bool getVisible() const;
  void setVisible(bool visibility);

  virtual bool init();
  virtual void update(float dt);
  virtual void render();

  void setMin();
  Vector2 getMin();
  virtual void calculateMax();
  Vector2 getMax();
  float getWidth() const;
  float getHeight() const;
  void setWidth(float _width);
  void setHeight(float _height);

  Vector2 getMovement();
  void setMovement(Vector2 move);

  bool AABB(GameObject* collider) const;

 protected:
  sf::RenderWindow& window;
  sf::Texture *texture;
  sf::Sprite *sprite;

  Vector2 movement;

  // default 0, 0
  Vector2 min = Vector2();
  Vector2 max = Vector2();
  float width;
  float height;

  bool visible;
};

#endif // SFMLTEMPLATE_GAMEOBJECT_H
