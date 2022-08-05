//
// Created by MLG Erwich on 05/08/2022.
//

#include "Entity.h"
Entity::Entity(sf::RenderWindow& game_window) : GameObject(game_window)
{

}

bool Entity::init(float x, float y)
{
  return true;
}

void Entity::update(float dt, GameObject* ground)
{

}
