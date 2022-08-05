#include "Enemy.h"

Enemy::Enemy(sf::RenderWindow& game_window): Entity(game_window) {

}

bool Enemy::init(float x, float y)
{
  if (!texture->loadFromFile("Data/Data/images/temp_man.png"))
  {
    return false;
  }

  sprite->setTexture(*texture);
  sprite->setScale(2,2);
  width = sprite->getGlobalBounds().width;
  height = sprite->getGlobalBounds().height;
  sprite->setPosition(x, y);

  setMin();
  calculateMax();
  return true;
}

void Enemy::update(float dt)
{
  sprite->move(10 *enemySpeed* dt,0);
  // test
}

int Enemy::getHealth() const
{
  return health;
}

void Enemy::setHealth(int _health)
{
  health = _health;
}