#include "Player.h"
Player::Player(sf::RenderWindow& game_window) : Entity(game_window)
{
  on_ground = true;
}

bool Player::init()
{
  if (!texture->loadFromFile("Data/Data/images/clockBotSpritesheet.png"))
  {
    return false;
  }

  //set anim state
  setPlayerAnimation();

  sprite->setTexture(*texture);
  sprite->scale(3, 3);

  width = sprite->getGlobalBounds().width;
  height = sprite->getGlobalBounds().height;

  sprite->setPosition(window.getSize().x / 2,
                      85 * 60);

  setMin();
  calculateMax();

  return true;
}

void Player::reset()
{
  sprite->setPosition(window.getSize().x / 2,
                      85 * 60);

  movement = Vector2();
}

void Player::setOnGround(bool _on_ground) { on_ground = _on_ground; }

void Player::keyPressed(sf::Event event)
{
  if (event.key.code == sf::Keyboard::D)
  {
    movement.x = 1.5;
    current_animation = AnimationState::RUNNING;
  }

  if (event.key.code == sf::Keyboard::A)
  {
    movement.x = -1.5;
    current_animation = AnimationState::RUNNING;
  }

  if (event.key.code == sf::Keyboard::Space && on_ground)
  {
    movement.y = -5;
    on_ground = false;
  }
  else if (event.key.code == sf::Keyboard::Space && !on_ground)
  {
    movement.y = 7.5;
  }
}

void Player::keyReleased(sf::Event event)
{
  if (event.key.code == sf::Keyboard::D)
  {
    movement.x = 0;
    current_animation = AnimationState::IDLE;
  }

  if (event.key.code == sf::Keyboard::A)
  {
    movement.x = 0;
    current_animation = AnimationState::IDLE;
  }
}

void Player::update(float dt)
{
  //updates anim state
  playerAnimatorUpdate(dt);

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
      current_animation = AnimationState::RUNNING;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
      movement.x = -1.5;
      current_animation = AnimationState::RUNNING;
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

void Player::setPlayerAnimation()
{
  // player animation
  if (current_animation == AnimationState::IDLE)
  {
    player_texture_rectangle = sf::IntRect(0, 0, 17, 32);
    sprite->setTextureRect(player_texture_rectangle);
    std::cout<<"idle"<<std::endl;
  }

//  else if (current_animation == AnimationState::JUMPING)
//  {
//    player_texture_rectangle = sf::IntRect(0, 80, 49, 40);
//    sprite->setTextureRect(player_texture_rectangle);
//  }

  else if (current_animation == AnimationState::RUNNING)
  {
    player_texture_rectangle = sf::IntRect(17, 0, 17, 32);
    sprite->setTextureRect(player_texture_rectangle);
  }
}

void Player::playerAnimatorUpdate(float dt)
{
  footstep_timer += 1.0f * dt;
  //jump_timer += 0.7f * dt;

  // player animation state
  if (current_animation == AnimationState::RUNNING)
  {
    if (footstep_timer > 1.2f)
    {
      //player_footsteps.play();
      footstep_timer = 0;
    }
    playerAnimator(
      0.05f, current_animation, player_texture_rectangle, 85, 17);
  }
  else if (current_animation == AnimationState::JUMPING)
  {
    /*playerAnimator(
      1.2f * dt, current_animation, player_texture_rectangle, 980, 49);*/
  }
  else if (current_animation == AnimationState::IDLE)
  {
    playerAnimator(
      0.03f * dt, current_animation, player_texture_rectangle, 17, 17);
  }
  if (movement.x == 0)
  {
    current_animation = AnimationState::IDLE;
  }
  if (!on_ground)
  {
    current_animation = AnimationState::JUMPING;
  }
}


void Player::playerAnimator(
  float update_animation, AnimationState &current, sf::IntRect& player_texture_rectangles,
  int max_size, int sprite_size)
{
  if (clock_animation_texture.getElapsedTime().asSeconds() >= update_animation)
  {
    if (current_animation == AnimationState::RUNNING)
    {
      player_texture_rectangle.left += sprite_size;
      player_texture_rectangle.width  = 17;
      player_texture_rectangle.top    = 0.f;
      player_texture_rectangle.height = 32;
      if (player_texture_rectangle.left >= max_size)
      {
        player_texture_rectangle.left = 0;
      }
    }

   /* else if (current_animation == AnimationState::JUMPING)
    {
      player_texture_rectangle.left += sprite_size;
      player_texture_rectangle.width  = 49;
      player_texture_rectangle.top    = 80.f;
      player_texture_rectangle.height = 40;
      if (player_texture_rectangle.left >= max_size)
      {
        player_texture_rectangle.left = 0;
      }
    }
*/
    else if (current_animation == AnimationState::IDLE)
    {
      player_texture_rectangle.left += sprite_size;
      player_texture_rectangle.width  = 17;
      player_texture_rectangle.top    = 0;
      player_texture_rectangle.height = 32;
      if (player_texture_rectangle.left >= max_size)
      {
        player_texture_rectangle.left = 0;
      }
    }

    clock_animation_texture.restart();
    sprite->setTextureRect(player_texture_rectangle);
  }
}