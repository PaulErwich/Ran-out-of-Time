#include "Level.h"

sf::Texture Level::single_block_texture;
sf::Texture Level::leaf_top_texture;
sf::Texture Level::leaf_block_texture;
sf::Texture Level::leaf_platform_texture[3];
sf::Texture Level::wall_texture;
sf::Texture Level::inside_tower_texture;
sf::Texture Level::clock_tower_texture;

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

  for (int i = 0; i < COG_NUMBER; i++)
  {
    cogs[i] = new Cog(window);
  }

  player = nullptr;

  current_platforms = 0;
  current_enemies = 0;

  object_count = 0;
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

  for (int i = 0; i < COG_NUMBER; i++)
  {
    delete cogs[i];
  }
}

bool Level::init(Player* _player)
{
  player = _player;

  float scale = 60.f / 18.f;
  inside_tower.setTexture(inside_tower_texture);
  inside_tower.scale(scale, scale);
  inside_tower.setPosition(5 * BLOCK_SZ, 7 * BLOCK_SZ);

  clock_tower.setTexture(clock_tower_texture);
  clock_tower.scale(scale, scale);
  clock_tower.setPosition(0, -3 * BLOCK_SZ);

  int cog_x[COG_NUMBER] = {24, 8, 26, 26};
  int cog_y[COG_NUMBER] = {62, 30, 30, 26};

  for (int i = 0; i < COG_NUMBER; i++)
  {
    cogs[i]->init(cog_x[i] * BLOCK_SZ, cog_y[i] * BLOCK_SZ);
  }

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
      world[i * HEIGHT + (j + HEIGHT - 3)]->init(
        leaf_top_texture, i * BLOCK_SZ, (j + HEIGHT - 3) * BLOCK_SZ);
      world[i * HEIGHT + (j + HEIGHT - 2)]->init(
        leaf_block_texture, i * BLOCK_SZ, (j + HEIGHT - 2) * BLOCK_SZ);
      world[i * HEIGHT + (j + HEIGHT - 1)]->init(
        leaf_block_texture, i * BLOCK_SZ, (j + HEIGHT - 1) * BLOCK_SZ);
    }
  }

  floor->getSprite()->setPosition(world[HEIGHT - 3]->getSprite()->getPosition());
  floor->setWidth(WIDTH * BLOCK_SZ);
  floor->setHeight(3 * BLOCK_SZ);
  floor->setMin();
  floor->calculateMax();
}

void Level::init_setup_platforms()
{
  generatePlatform(8, 83, 3, leaf_platform_texture);
  generatePlatform(10, 79, 3, leaf_platform_texture);
  generatePlatform(18, 79, 4, leaf_platform_texture);
  generatePlatform(22, 75, 3, leaf_platform_texture);
  generatePlatform(17, 72, 3, leaf_platform_texture);
  generatePlatform(12, 70, 4, leaf_platform_texture);
  generatePlatform(7, 66, 4, leaf_platform_texture);
  generatePlatform(12, 63, 13, leaf_platform_texture);
  generatePlatform(22, 59, 3, leaf_platform_texture);
  generatePlatform(8, 56, 5, leaf_platform_texture);
  generatePlatform(17, 56, 4, leaf_platform_texture);
  generatePlatform(8, 52, 4, leaf_platform_texture);
  generatePlatform(18, 35, 6, leaf_platform_texture);
  generatePlatform(12, 39, 4, leaf_platform_texture);
  generatePlatform(8, 31, 8, leaf_platform_texture);
  generatePlatform(19, 31, 8, leaf_platform_texture);
  generatePlatform(16, 27, 11, leaf_platform_texture);
  generatePlatform(10, 23, 4, leaf_platform_texture);
  generatePlatform(13, 19, 4, leaf_platform_texture);
  generatePlatform(16, 15, 4, leaf_platform_texture);
  generatePlatform(16, 11, 4, leaf_platform_texture);
  generatePlatform(5, 7, 10, leaf_platform_texture);
  generatePlatform(17, 7, 10, leaf_platform_texture);

  generateWall(4,86,80, &wall_texture);
  generateWall(27,86,80, &wall_texture);
}

void Level::init_setup_enemies()
{

}

bool Level::loadAssets()
{
  if (!leaf_top_texture.loadFromFile("Data/Data/images/tile_0018.png")) return false;
  if (!leaf_block_texture.loadFromFile("Data/Data/images/tile_0038.png")) return false;

  if (!leaf_platform_texture[0].loadFromFile("Data/Data/images/clockBlockLeft.png")) return false;
  if (!leaf_platform_texture[1].loadFromFile("Data/Data/images/clockBlockMid.png")) return false;
  if (!leaf_platform_texture[2].loadFromFile("Data/Data/images/clockBlockRight.png")) return false;
  if (!wall_texture.loadFromFile("Data/Data/images/clockBlockWall.png")) return false;
  if (!inside_tower_texture.loadFromFile("Data/Data/images/clockTowerInsideWall.png")) return false;
  if (!clock_tower_texture.loadFromFile("Data/Data/images/clockTower.png")) return false;

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
    if (i == 0)
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
  int platform_x, int platform_y, int height,  sf::Texture* textures)
{
  for (int i = 0; i < height; ++i)
  {
    int world_pos = platform_x * HEIGHT + (platform_y - i);
    int pos = platform_x * (platform_y - i);

    world[world_pos]->init(textures[0], (pos / (platform_y - i)) * BLOCK_SZ,
                           (pos / platform_x) * BLOCK_SZ);
  }
}

void Level::generateWall(
  int platform_x, int platform_y, int height, sf::Texture* textures)
{
  textureWall(platform_x, platform_y, height, textures);

  platforms[current_platforms]->getSprite()->setPosition(
    world[platform_x * HEIGHT + (platform_y - height + 1)]->getSprite()->getPosition());
  platforms[current_platforms]->setWidth(BLOCK_SZ);
  platforms[current_platforms]->setHeight(height * BLOCK_SZ);
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

  for (int i = 0; i < COG_NUMBER; i++)
  {
    if (cogs[i]->getVisible())
    {
      if (player->AABB(cogs[i]))
      {
        cogs[i]->setVisible(false);
        object_count++;
      }
    }
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

  if (object_count == 4 && player->getMin().y < 300)
  {
    return STATE::GAME_WIN;
  }

  return STATE::GAME_PLAY;
}

void Level::render()
{
  window.draw(inside_tower);
  window.draw(clock_tower);

  for (int i = 0; i < WIDTH * HEIGHT; i++)
  {
    world[i]->render();
  }

  for (int i = 0; i < COG_NUMBER; i++)
  {
    cogs[i]->render();
  }

  player->render();
}
