//
// Created by philipp on 2/13/24.
//

#ifndef PONG_POINTCOUNTER_H
#define PONG_POINTCOUNTER_H

#endif//PONG_POINTCOUNTER_H

#include "GameHandler.h"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class PointCounter {
public:
  PointCounter() {
    this->window = GameHandler::getInstance().getWindow();
    this->players = EntityHandler::getInstance().getPlayers();
    this->font = &GameHandler::getInstance().getFont();
    scores = vector<int>(players->size(), 0);
  }

  void draw() {
    for (int i = 0; i < players->size(); i++) {
      Text text(to_string(scores[i]), *font, 20);
      text.setFillColor(Color::White);
      text.setOutlineColor(Color::Black);
      text.setOutlineThickness(1.0f);
      text.setStyle(Text::Bold);
      text.setPosition(players->at(i).getCoords().x - 35.0f,
                       20.0f);
      text.setString("Player " + to_string(i + 1) + ": " + to_string(scores[i]));
      window->draw(text);
    }
  }

  void increment(int index) {
    if (index >= 0 && index < players->size()) {
      scores[index]++;
    }
  }

private:
  RenderWindow *window;
  Font *font;
  vector<Player> *players;
  vector<int> scores;
};
