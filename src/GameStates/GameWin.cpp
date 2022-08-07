#include "GameWin.h"
GameWin::GameWin(
  STATE state_id, sf::RenderWindow& game_window, sf::Font& game_font) :
  GameStateBase(state_id, game_window, game_font)
{
}

bool GameWin::init()
{

  if (!texture.loadFromFile("Data/Data/images/manclock.png"))
  {
    return false;
  }
  sprite.setTexture(texture);
  sprite.setScale(20,20);

  sprite.setPosition(window.getSize().x/ 2 - (sprite.getGlobalBounds().width/2),window.getSize().y/2
                                                                                      - (sprite.getGlobalBounds().height/2));
  Helper::SFMLText(text_win, "You Win ", *font, 80,
                   basic, window.getSize().x / 2, 100);
  Helper::SFMLText(return_to_menu, "ENTER TO RETURN TO MENU", *font, 60,
                   basic, window.getSize().x / 2, window.getSize().y -150);

  return true;
}

void GameWin::reset()
{
  transition = game_state_id;
}

void GameWin::input(sf::Event event)
{
  if (event.type == sf::Event::KeyPressed)
  {
    if (event.key.code == sf::Keyboard::Enter)
    {
      transition = STATE::GAME_MENU;
    }
  }
}

STATE GameWin::update(float dt)
{
  return transition;
}

void GameWin::render()
{
  window.draw(text_win);
  window.draw(return_to_menu);
  window.draw(sprite);
}
