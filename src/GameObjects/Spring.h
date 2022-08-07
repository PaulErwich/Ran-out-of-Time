//
// Created by scott on 07/08/2022.
//

#ifndef SFMLTEMPLATE_SPRING_H
#define SFMLTEMPLATE_SPRING_H

  //Game Engine
#include "GameObject.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Entities/Player.h"

// Codebase

class Spring : public GameObject
{
 public:
  explicit Spring(sf::RenderWindow& gameWindow);
  ~Spring();
  bool initSpring(float x, float y);
  void loadSFX();
  bool bounce(Player& other, float dt);
  bool reset();
  void update(float dt) override;
  bool isReady() const;
  sf::Clock getClock();
  bool isColliding(const sf::Sprite& rect1,
                   const sf::Sprite& rect2);

 private:
  bool ready = true;
  float bounciness = -450;
  Vector2 location = Vector2(0, 0);
  sf::Clock* clock;
  sf::Texture* spring_texture1;
  sf::Texture* spring_texture2;
  sf::SoundBuffer* buffer;
  sf::Sound* spring_sfx;


};

#endif // SFMLTEMPLATE_SPRING_H



