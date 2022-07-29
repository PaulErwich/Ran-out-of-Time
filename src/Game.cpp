//
// Created by MLG Erwich on 29/07/2022.
//

#include "Game.h"

Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
  font.loadFromFile("Data/Data/fonts/MochiyPopOne-Regular.ttf");
}

Game::~Game()
{

}

bool Game::init()
{
  text.setFont(font);
  text.setString("GAME");
  text.setCharacterSize(40);
  text.setFillColor(sf::Color::White);

  return true;
}

void Game::input(sf::Event event)
{

}

void Game::update(float dt)
{

}

void Game::render()
{
  window.draw(text);
}