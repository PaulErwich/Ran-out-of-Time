#ifndef SFMLTEMPLATE_PLAYER_H
#define SFMLTEMPLATE_PLAYER_H

#include "../../GameStates/AnimationState.h"
#include "Entity.h"

class Player : public Entity
{
 public:
  Player(sf::RenderWindow& game_window);
  bool init() override;

  void reset();

  void setOnGround(bool _on_ground);

  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);

  void update(float dt) override;
  void setPlayerAnimation();
  void playerAnimatorUpdate(float dt);
  void playerAnimator(
    float update_animation, AnimationState& current,
    sf::IntRect& player_texture_rectangle, int max_size, int sprite_size);

 private:
  bool on_ground;
  const int SPEED = 100;
  float footstep_timer = 0;

  sf::IntRect player_texture_rectangle;
  sf::Clock clock_animation_texture;
  AnimationState current_animation = AnimationState::IDLE;

};

#endif // SFMLTEMPLATE_PLAYER_H
