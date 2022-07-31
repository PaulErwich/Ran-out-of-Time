//
// Created by MLG Erwich on 31/07/2022.
//

#include "GamePlay.h"
GamePlay::GamePlay(
  STATE state_id, sf::RenderWindow& game_window, sf::Font& game_font) :
  GameStateBase(state_id, game_window, game_font)
{
}

bool GamePlay::init()
{
  return GameStateBase::init();
}

void GamePlay::reset()
{
  transition = game_state_id;
}

void GamePlay::input(sf::Event event)
{

}

STATE GamePlay::update(float dt)
{
  return transition;
}

void GamePlay::render()
{

}
