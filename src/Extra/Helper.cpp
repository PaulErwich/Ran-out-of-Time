//
// Created by MLG Erwich on 31/07/2022.
//

#include "Helper.h"

void Helper::SFMLText(sf::Text& text, const std::string& string, sf::Font& font, int char_size, sf::Color color, float x, float y)
{
  text.setFont(font);
  text.setString(string);
  text.setCharacterSize(char_size);
  text.setFillColor(sf::Color::White);
  text.setPosition(x - text.getGlobalBounds().width / 2, y - text.getGlobalBounds().height);
}