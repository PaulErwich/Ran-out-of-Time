//
// Created by MLG Erwich on 07/08/2022.
//

#include "Cog.h"
Cog::Cog(sf::RenderWindow& game_window) : GameObject(game_window)
{

}

bool Cog::init(float x, float y)
{
  if (!texture->loadFromFile("Data/Data/images/cog.png")) return false;

  sprite->setTexture(*texture);
  float scale = 0.1;
  sprite->scale(scale, scale);

  sprite->setPosition(x, y);
  width = sprite->getGlobalBounds().width;
  height = sprite->getGlobalBounds().height;

  setMin();
  calculateMax();

  return true;
}
