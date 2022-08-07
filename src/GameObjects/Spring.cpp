//
// Created by scott on 07/08/2022.
//

//Codebase
#include "Spring.h"


Spring::Spring(sf::RenderWindow& gameWindow) : GameObject(gameWindow)
{
  clock = new sf::Clock;
  spring_texture1 = new sf::Texture;
  spring_texture2 = new sf::Texture;
  buffer = new sf::SoundBuffer;
  spring_sfx      = new sf::Sound;
  sprite->setScale(2,2);


}

Spring::~Spring()
{
  delete clock;
  delete spring_texture1;
  delete spring_texture2;
  delete buffer;
  delete spring_sfx;
}

bool Spring::initSpring(float x, float y)
{
  if (!texture->loadFromFile("Data/Data/images/tile_0107.png"))
  {
    return false;
  }
  sprite->setTexture(*texture);
  loadSFX();
  sprite->setPosition(x,y);
  return true;
}

void Spring::loadSFX()
{
  spring_sfx->setBuffer(*buffer);
  if (!buffer->loadFromFile("Data/Audio/boing.wav"))
  {
    std::cout << "Spring sfx did not load";
  }
}


bool Spring::bounce(Player& other, float dt)
{
  location = Vector2(getSprite()->getPosition().x,
                     getSprite()->getPosition().y);
  other.setMovement(Vector2(other.getMovement().x * dt,
                            bounciness * dt));

  if (!texture->loadFromFile("Data/Data/images/tile_0108.png"))
  {
    std::cout << "springs texture did not load";
    return false;
  }
  ready = false;
  spring_sfx->play();
  clock->restart();

  return true;
}

bool Spring::reset()
{
  if (!texture->loadFromFile("Data/Data/images/tile_0107.png"))
  {
    std::cout << "springs texture did not load";
    return false;
  }
  ready = true;

  return true;
}

bool Spring::isReady() const
{
  return ready;
}

sf::Clock Spring::getClock()
{
  return *clock;
}
void Spring::update(float dt)
{

}

bool Spring::isColliding(const sf::Sprite& rect1, const sf::Sprite& rect2)
{
  if(rect1.getPosition().x < rect2.getPosition().x + rect2.getGlobalBounds().width
      && rect1.getPosition().x + rect1.getGlobalBounds().width > rect2.getPosition().x
      && rect1.getPosition().y < rect2.getPosition().y + rect2.getGlobalBounds().height
      && rect1.getGlobalBounds().height + rect1.getPosition().y > rect2.getPosition().y)
  {
    return true;
  }
  else
  {
    return false;
  }
}