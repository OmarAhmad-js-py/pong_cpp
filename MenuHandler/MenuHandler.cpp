#include "MenuHandler.h"
#include "../GameHandler/GameHandler.h"

MenuHandler::MenuHandler() {
  this->window = GameHandler::getInstance().getWindow();
  this->font = GameHandler::getInstance().getFont();

  Text _title = Text("Ultimate Super Mega Pong", font, 30);
  _title.setFillColor(sf::Color::White);
  _title.setPosition({window->getSize().x / 2 - _title.getLocalBounds().width / 2, 10});
  this->title = _title;
}

void MenuHandler::draw() {
  this->window->draw(this->title);
}
