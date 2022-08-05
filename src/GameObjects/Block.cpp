//
// Created by MLG Erwich on 05/08/2022.
//

#include "Block.h"

Block::Block(sf::RenderWindow& game_window) : GameObject(game_window)
{

}

bool Block::init(sf::Texture& block_texture, float x, float y)
{
  texture = &block_texture;

  sprite->setTexture(*texture);
  float scale = 60.0f / 18.0f;
  sprite->scale(scale, scale);

  sprite->setPosition(x, y);
  width = sprite->getGlobalBounds().width;
  height = sprite->getGlobalBounds().height;

  setMin();
  calculateMax();

  return true;
}

