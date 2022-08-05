//
// Created by MLG Erwich on 05/08/2022.
//

#ifndef SFMLTEMPLATE_BLOCK_H
#define SFMLTEMPLATE_BLOCK_H

#include "GameObject.h"

class Block : public GameObject
{
 public:
  Block(sf::RenderWindow& game_window);
  bool init(sf::Texture &block_texture, float x, float y);
};

#endif // SFMLTEMPLATE_BLOCK_H
