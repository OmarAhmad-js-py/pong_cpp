#include "GameHandler.h"
#include "../PointCounter/PointCounter.h"
#include <iostream>

GameHandler::GameHandler() {
  cout << "GameHandler: created" << endl;
  this->window_height = 600;
  this->window_width = 800;
  // Initialize window
  ContextSettings settings;
  settings.depthBits = 24;
  settings.stencilBits = 8;
  settings.antialiasingLevel = 4;
  this->window.create(VideoMode(this->window_width, this->window_height), "Pong", Style::Default, settings);
  this->window.setFramerateLimit(60);

  cout << "GameHandler: Window created" << endl;


  // Initialize font
  if (!this->main_font.loadFromFile("../assets/roboto.ttf"))
    exit(1);

  cout << "GameHandler: Font loaded" << endl;
}

GameHandler &GameHandler::getInstance() {
  static GameHandler instance;
  return instance;
}

RenderWindow *GameHandler::getWindow() {
  return &this->window;
}
Font &GameHandler::getFont() {
  return this->main_font;
}