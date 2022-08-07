#include "Level.h"

sf::Texture Level::single_block_texture;
sf::Texture Level::leaf_top_texture;
sf::Texture Level::leaf_block_texture;
sf::Texture Level::leaf_platform_texture[4];

Level::Level(sf::RenderWindow& game_window) : window(game_window)
{
  for (int i = 0; i < WIDTH * HEIGHT; i++)
  {
    world[i] = new Block(window);
  }

  floor = new GameObject(window);

  for (int i = 0; i < PLAT_NUM; i++)
  {
    platforms[i] = new GameObject(window);
  }

  for (int i = 0; i < MAX_ENEMIES; i++)
  {
    enemies[i] = new Entity(window);
  }

  player = nullptr;

  current_platforms = 0;
  current_enemies = 0;
}

Level::~Level()
{
  for (int i = 0; i < WIDTH * HEIGHT; i++)
  {
    delete world[i];
  }

  delete floor;

  for (int i = 0; i < PLAT_NUM; i++)
  {
    delete platforms[i];
  }

  for (int i = 0; i < MAX_ENEMIES; i++)
  {
    delete enemies[i];
  }
}

bool Level::init(Player* _player)
{
  player = _player;

  init_setup_blocks();
  init_setup_platforms();

  return true;
}

void Level::init_setup_blocks()
{
  for (int i = 0; i < WIDTH; i++)
  {
    for (int j = 0; j < HEIGHT; j += HEIGHT)
    {
      world[i * HEIGHT + (j + 42)]->init(
        leaf_top_texture, i * BLOCK_SZ, (j + 42) * BLOCK_SZ);
      world[i * HEIGHT + (j + 43)]->init(
        leaf_block_texture, i * BLOCK_SZ, (j + 43) * BLOCK_SZ);
      world[i * HEIGHT + (j + 44)]->init(
        leaf_block_texture, i * BLOCK_SZ, (j + 44) * BLOCK_SZ);
    }
  }

  floor->getSprite()->setPosition(world[42]->getSprite()->getPosition());
  floor->setWidth(WIDTH * BLOCK_SZ);
  floor->setHeight(3 * BLOCK_SZ);
  floor->setMin();
  floor->calculateMax();
}

void Level::init_setup_platforms()
{
  generatePlatform(8, 38, 3, leaf_platform_texture);
  generatePlatform(10, 34, 3, leaf_platform_texture);
  generatePlatform(18, 34, 4, leaf_platform_texture);
  generatePlatform(22, 30, 3, leaf_platform_texture);
  generatePlatform(17, 27, 3, leaf_platform_texture);
  generatePlatform(12, 25, 4, leaf_platform_texture);
  generatePlatform(7, 21, 4, leaf_platform_texture);
  generatePlatform(12, 18, 13, leaf_platform_texture);
  generatePlatform(22, 14, 3, leaf_platform_texture);
  generatePlatform(8, 11, 5, leaf_platform_texture);
  generatePlatform(17, 11, 4, leaf_platform_texture);
  generatePlatform(8, 7, 4, leaf_platform_texture);
  generatePlatform(18, -10, 6, leaf_platform_texture);
  generatePlatform(12, -6, 4, leaf_platform_texture);
  generatePlatform(8, -14, 8, leaf_platform_texture);
  generatePlatform(19, -14, 8, leaf_platform_texture);
  generatePlatform(16, -18, 11, leaf_platform_texture);
  generatePlatform(10, -22, 4, leaf_platform_texture);
  generatePlatform(13, -26, 4, leaf_platform_texture);
  generatePlatform(16, -30, 4, leaf_platform_texture);
  generatePlatform(16, -34, 4, leaf_platform_texture);
  generatePlatform(8, -38, 8, leaf_platform_texture);
  generatePlatform(18, -38, 9, leaf_platform_texture);

  generateWall(8,38,10,leaf_platform_texture);
}

void Level::init_setup_enemies()
{

}

bool Level::loadAssets()
{
  if (!leaf_top_texture.loadFromFile("Data/Data/images/tile_0018.png")) return false;
  if (!leaf_block_texture.loadFromFile("Data/Data/images/tile_0038.png")) return false;

  if (!leaf_platform_texture[0].loadFromFile("Data/Data/images/tile_0077.png")) return false;
  if (!leaf_platform_texture[1].loadFromFile("Data/Data/images/tile_0078.png")) return false;
  if (!leaf_platform_texture[2].loadFromFile("Data/Data/images/tile_0079.png")) return false;
  if (!leaf_platform_texture[3].loadFromFile("Data/Data/images/clockBlockWall.png")) return false;

  return true;
}

void Level::reset()
{

}

int Level::getHeight() { return HEIGHT; }

void Level::textureRow(
  int platform_x, int platform_y, int width, sf::Texture* textures)
{
  int start = platform_x * HEIGHT + platform_y;
  int end = (platform_x + width - 1) * HEIGHT + platform_y;

  for (int i = 0; i < width; i++)
  {
    if (i ==0)
    {
      int pos = (platform_x + i) * platform_y;
      world[start]->init(textures[0], (pos / platform_y) * BLOCK_SZ,
                         (pos / platform_x) * BLOCK_SZ);
    }
    else if (i == width - 1)
    {
      int pos = (platform_x + i) * platform_y;
      world[end]->init(textures[2], (pos / platform_y) * BLOCK_SZ,
                       (pos / (platform_x + i)) * BLOCK_SZ);
    }
    else
    {
      int world_pos = (platform_x + i) * HEIGHT + platform_y;
      int pos = (platform_x + i) * platform_y;
      world[world_pos]->init(textures[1], (pos / platform_y) * BLOCK_SZ,
                             (pos / (platform_x + i)) * BLOCK_SZ);
    }
  }
}

void Level::textureWall(
  int platform_x, int platform_y, int width,  sf::Texture* textures)
{

  for (int i = 0; i < width; ++i)
  {
    int world_pos = (platform_x + i) * HEIGHT + platform_y;
    int pos = (platform_x + i) * platform_y;

    world[world_pos]->init(textures[4], (pos / platform_y + i) * BLOCK_SZ,
                           (pos / (platform_x)) * BLOCK_SZ);
  }
}

void Level::generateWall(
  int platform_x, int platform_y, int height, sf::Texture* textures)
{
  textureWall(platform_x, platform_y, height, textures);

  platforms[current_platforms]->getSprite()->setPosition(
    world[platform_x * HEIGHT + platform_y]->getSprite()->getPosition());
  platforms[current_platforms]->setWidth(BLOCK_SZ);
  platforms[current_platforms]->setHeight(height*BLOCK_SZ);
  platforms[current_platforms]->setMin();
  platforms[current_platforms]->calculateMax();

  current_platforms++;
}
void Level::generatePlatform(
  int platform_x, int platform_y, int width, sf::Texture* textures)
{
  textureRow(platform_x, platform_y, width, textures);

  platforms[current_platforms]->getSprite()->setPosition(
    world[platform_x * HEIGHT + platform_y]->getSprite()->getPosition());
  platforms[current_platforms]->setWidth(width * BLOCK_SZ);
  platforms[current_platforms]->setHeight(BLOCK_SZ);
  platforms[current_platforms]->setMin();
  platforms[current_platforms]->calculateMax();

  current_platforms++;
}

void Level::generateBlock(int platform_x, int platform_y, int texture_num)
{
  int world_pos = platform_x * HEIGHT + platform_y;
  world[world_pos]->init(leaf_block_texture,
                         platform_x * BLOCK_SZ, platform_y * BLOCK_SZ);

  platforms[current_platforms]->getSprite()->setPosition(
    world[world_pos]->getSprite()->getPosition());
  platforms[current_platforms]->setWidth(BLOCK_SZ);
  platforms[current_platforms]->setHeight(BLOCK_SZ);
  platforms[current_platforms]->setMin();
  platforms[current_platforms]->calculateMax();

  current_platforms++;
}

void Level::generateBox(
  int platform_x, int platform_y, int width, int height, sf::Texture* textures,
  bool on_floor)
{
  for (int i = 0; i < height; i++)
  {
    if (i == 0)
    {
      textureRow(platform_x, platform_y, width, textures);
    }
    else if (i == height - 1)
    {
      if (!on_floor)
      {
        textureRow(platform_x, platform_y + 1, width, textures);
      }
      else
      {
        textureRow(platform_x, platform_y + i, width, textures);
      }
    }
    else
    {
      textureRow(platform_x, platform_y + i, width, textures);
    }
  }

  int world_pos = platform_x * HEIGHT + platform_y;
  platforms[current_platforms]->getSprite()->setPosition(
    world[world_pos]->getSprite()->getPosition());
  platforms[current_platforms]->setWidth(width * BLOCK_SZ);
  platforms[current_platforms]->setHeight(height * BLOCK_SZ);
  platforms[current_platforms]->setMin();
  platforms[current_platforms]->calculateMax();

  current_platforms++;
}

void Level::input(sf::Event event)
{

}

STATE Level::update(float dt)
{
  player->update(dt);

  player->setOnGround(false);

  if (player->AABB(floor))
  {
    player->setOnGround(true);
    player->getSprite()->setPosition(player->getSprite()->getPosition().x,
                                     floor->getMin().y - player->getHeight());
  }

  Object_Manifold collision(player, nullptr);

 //collision.B = wall_one;

 //if (AABBvsAABB_MK3(&collision))
 //{
 //  if (collision.normal.x != 0)
 //  {
 //    if (collision.normal.x == 1)
 //    {
 //      player->getSprite()->setPosition(collision.B->getMin().x - player->getWidth(), player->getSprite()->getPosition().y);
 //    }
 //    else if (collision.normal.x == -1)
 //    {
 //      player->getSprite()->setPosition(collision.B->getMax().x, player->getSprite()->getPosition().y);
 //    }
 //  }
 //}

  for (int i = 0; i < PLAT_NUM; i++)
  {
    if (platforms[i] != nullptr)
    {
      collision.B = platforms[i];

      if (AABBvsAABB_MK3(&collision))
      {
        if (collision.normal.x != 0)
        {
          if (collision.normal.x == 1)
          {
            player->getSprite()->setPosition(collision.B->getMin().x - player->getWidth(), player->getSprite()->getPosition().y);
          }
          else if (collision.normal.x == -1)
          {
            player->getSprite()->setPosition(collision.B->getMax().x, player->getSprite()->getPosition().y);
          }
        }
        else if (collision.normal.y != 0)
        {
          if (collision.normal.y == 1)
          {
            player->setOnGround(true);
          }
          else if (collision.normal.y == -1)
          {
            player->setMovement(Vector2(player->getMovement().x, 2));
          }
        }
      }
    }
  }

  return STATE::GAME_PLAY;
}

void Level::render()
{
  for (int i = 0; i < WIDTH * HEIGHT; i++)
  {
    world[i]->render();
  }

  player->render();
}
