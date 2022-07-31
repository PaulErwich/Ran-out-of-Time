//
// Created by MLG Erwich on 31/07/2022.
//

#include "GameStateBase.h"
GameStateBase::GameStateBase(
  STATE state_id, sf::RenderWindow& game_window, sf::Font& game_font)
  : window(game_window)
{
  game_state_id = state_id;
  font = &game_font;

  transition = game_state_id;
}

GameStateBase::~GameStateBase() { delete font; }

bool GameStateBase::init()
{
  return true;
}

STATE GameStateBase::getStateID() { return game_state_id; }

void GameStateBase::reset() {}

void GameStateBase::input(sf::Event event) {}

STATE GameStateBase::update(float dt) { return game_state_id; }

void GameStateBase::render() {}

bool GameStateBase::clickChecker(sf::Vector2i click, const sf::Text& area)
{
  if (click.x > area.getPosition().x && click.x < area.getPosition().x + area.getGlobalBounds().width
      && click.y > area.getPosition().y && click.y < area.getPosition().y + area.getGlobalBounds().height)
  {
    {
      std::cout << "Inside box\n";
      return true;
    }
  }
  else
    return false;
}

bool GameStateBase::spriteClickChecker(
  sf::Vector2i click, const sf::Sprite& area)
{
  if (click.x > area.getPosition().x && click.x < area.getPosition().x + area.getGlobalBounds().width
      && click.y > area.getPosition().y && click.y < area.getPosition().y + area.getGlobalBounds().height)
  {
    {
      std::cout << "Inside box\n";
      return true;
    }
  }
  else
    return false;
}
