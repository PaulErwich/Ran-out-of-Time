//
// Created by MLG Erwich on 05/08/2022.
//

#include "Player.h"
Player::Player(sf::RenderWindow& game_window) : Entity(game_window)
{
  on_ground = true;
}

bool Player::init()
{
  if (!texture->loadFromFile("Data/Data/images/manclock.png"))
  {
    return false;
  }

  sprite->setTexture(*texture);

  sprite->scale(3, 3);

  width = sprite->getGlobalBounds().width;
  height = sprite->getGlobalBounds().height;

  sprite->setPosition(window.getSize().x / 2,
                      20 * 60);

  setMin();
  calculateMax();

  return true;
}

void Player::reset()
{
  sprite->setPosition(window.getSize().x / 2,
                      20 * 60);

  movement = Vector2();
}

void Player::setOnGround(bool _on_ground) { on_ground = _on_ground; }

void Player::keyPressed(sf::Event event)
{
  if (event.key.code == sf::Keyboard::D)
  {
    movement.x = 1.5;
  }

  if (event.key.code == sf::Keyboard::A)
  {
    movement.x = -1.5;
  }

  if (event.key.code == sf::Keyboard::Space && on_ground)
  {
    movement.y = -5;
    on_ground = false;
  }
}

void Player::keyReleased(sf::Event event)
{
  if (event.key.code == sf::Keyboard::D)
  {
    movement.x = 0;
  }

  if (event.key.code == sf::Keyboard::A)
  {
    movement.x = 0;
  }
}

void Player::update(float dt)
{
  movement.y += 5 * dt;

  if (on_ground)
  {
    movement.y = 0;
  }

  if (movement.x == 0)
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
      movement.x = 1.5;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
      movement.x = -1.5;
    }
  }

  sprite->move(movement.x * SPEED * dt, movement.y * SPEED * dt);

  if (sprite->getPosition().x < 0)
  {
    sprite->setPosition(0, sprite->getPosition().y);
  }
  else if (sprite->getPosition().x + width > window.getSize().x)
  {
    sprite->setPosition(window.getSize().x - width, sprite->getPosition().y);
  }

  setMin();
  calculateMax();
}
