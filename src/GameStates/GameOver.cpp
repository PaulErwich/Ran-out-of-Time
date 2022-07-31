//
// Created by MLG Erwich on 31/07/2022.
//

#include "GameOver.h"
GameOver::GameOver(
  STATE state_id, sf::RenderWindow& game_window, sf::Font& game_font) :
  GameStateBase(state_id, game_window, game_font)
{
}

bool GameOver::init()
{
  Helper::SFMLText(text_lose, "TEMPLATE", *font, 80,
                   basic, window.getSize().x / 2, 100);
  Helper::SFMLText(return_to_menu, "ENTER TO RETURN TO MENU", *font, 60,
                   basic, window.getSize().x / 2, window.getSize().y /2);

  return true;
}

void GameOver::reset()
{
  transition = game_state_id;
}

void GameOver::input(sf::Event event)
{
  if (event.type == sf::Event::KeyPressed)
  {
    if (event.key.code == sf::Keyboard::Enter)
    {
      transition = STATE::GAME_MENU;
    }
  }
}

STATE GameOver::update(float dt)
{
  return transition;
}

void GameOver::render()
{
  window.draw(text_lose);
  window.draw(return_to_menu);
}
