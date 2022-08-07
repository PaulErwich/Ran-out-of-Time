//
// Created by MLG Erwich on 31/07/2022.
//

#include "GameMenu.h"
GameMenu::GameMenu(
  STATE state_id, sf::RenderWindow& game_window, sf::Font& game_font) :
  GameStateBase(state_id, game_window, game_font)
{
  transition = STATE::GAME_MENU;
}

bool GameMenu::init()
{
  Helper::SFMLText(text_title, "RAN OUT OF TIME", *font, 80,
                   basic, window.getSize().x / 2, 100);
  Helper::SFMLText(text_play, "PLAY", *font, 60,
                   basic, window.getSize().x / 2, window.getSize().y / 2 - 100);
  Helper::SFMLText(text_exit, "EXIT", *font, 60,
                   basic, window.getSize().x / 2, window.getSize().y / 2 + 100);

  return true;
}

void GameMenu::reset()
{
  transition = game_state_id;
}

void GameMenu::input(sf::Event event)
{
  if (event.type == sf::Event::MouseButtonPressed)
  {
    sf::Vector2i click = sf::Mouse::getPosition(window);

    if (clickChecker(click, text_play))
    {
      transition = STATE::GAME_PLAY;
    }

    if (clickChecker(click, text_exit))
    {
      transition = STATE::GAME_EXIT;
    }
  }
}

STATE GameMenu::update(float dt)
{
  return transition;
}

void GameMenu::render()
{
  window.draw(text_title);
  window.draw(text_play);
  window.draw(text_exit);
}
