#include "PointCounter.h"
#include "EntityHandler/EntityHandler.h"
#include <iostream>

PointCounter::PointCounter() {
  this->window = GameHandler::getInstance().getWindow();
  this->players = EntityHandler::getInstance().getPlayers();
  this->font = &GameHandler::getInstance().getFont();
  scores = vector<int>(players->size(), 0);
}

void PointCounter::draw() {
  for (int i = 0; i < players->size(); i++) {
    Text text(to_string(scores[i]), *font, 20);
    text.setFillColor(Color::White);
    text.setOutlineColor(Color::Black);
    text.setOutlineThickness(1.0f);
    text.setStyle(Text::Bold);
    text.setPosition(players->at(i).getCoords().x - 35.0f, 20.0f);
    text.setString("Player " + to_string(i + 1) + ": " + to_string(scores[i]));
    window->draw(text);
  }
}

void PointCounter::increment(int index) {
  if (index >= 0 && index < players->size()) {
    scores[index]++;
  } else {
    cout << "Invalid player index" << endl;
  }
}