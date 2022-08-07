#ifndef SFMLTEMPLATE_LEVEL_H
#define SFMLTEMPLATE_LEVEL_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameObject.h"
#include "Entities/Player.h"
#include "../GameStates/GameStateBase.h"
#include "Block.h"
#include "Cog.h"
#include "../Extra/Collisions/CollisionFunctions.h"
#include "../Extra/Collisions/CollisionStructs.h"

class Level
{
 public:
  Level(sf::RenderWindow& game_window);
  ~Level();

  bool init(Player* _player);
  static bool loadAssets();

  void reset();

  static int getHeight();

  void input(sf::Event event);
  STATE update(float dt);
  void render();

  static sf::Texture single_block_texture;
  static sf::Texture leaf_top_texture;
  static sf::Texture leaf_block_texture;
  static sf::Texture leaf_platform_texture[3];
  static sf::Texture wall_texture;
  static sf::Texture inside_tower_texture;
  static sf::Texture clock_tower_texture;

 private:
  sf::RenderWindow& window;

  static const int WIDTH = 32;
  static const int HEIGHT = 90;
  static const int BLOCK_SZ = 60;

  Block *world[WIDTH * HEIGHT];

  GameObject* floor;

  sf::Sprite inside_tower;
  sf::Sprite clock_tower;

  static const int PLAT_NUM = 200;
  int current_platforms;
  GameObject* platforms[PLAT_NUM];

  Player* player;
  static const int MAX_ENEMIES = 5;
  int current_enemies;
  Entity* enemies[MAX_ENEMIES];

  static const int COG_NUMBER = 4;
  Cog *cogs[COG_NUMBER];

  int object_count;

  void init_setup_blocks();
  void init_setup_platforms();
  void init_setup_enemies();

  void textureRow(int platform_x, int platform_y, int width, sf::Texture textures[]);

  void generateWall(int platform_x, int platform_y, int height, sf::Texture textures[]);

  void generatePlatform(int platform_x, int platform_y, int width, sf::Texture textures[]);

  void generateBlock(int platform_x, int platform_y, int texture_num);

  void generateBox(int platform_x, int platform_y, int width, int height,
                   sf::Texture textures[], bool on_floor);

  void textureWall(int platform_x, int platform_y, int height, sf::Texture* textures);
};

#endif // SFMLTEMPLATE_LEVEL_H
