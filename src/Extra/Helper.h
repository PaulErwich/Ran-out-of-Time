//
// Created by MLG Erwich on 31/07/2022.
//

#ifndef SFMLTEMPLATE_HELPER_H
#define SFMLTEMPLATE_HELPER_H

#include <SFML/Graphics.hpp>

class Helper
{
 public:
  static void SFMLText(sf::Text& text, const std::string& string, sf::Font& font,
                       int char_size, sf::Color color, float x, float y);
};

#endif // SFMLTEMPLATE_HELPER_H
