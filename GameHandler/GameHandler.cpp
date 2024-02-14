#include "GameHandler.h"
#include "../Ball/Ball.h"
#include "../Player/Player.h"
#include "../PointCounter.h"
#include <iostream>


extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;

GameHandler::GameHandler() {

  cout << "GameHandler::GameHandler()" << endl;
  // Initialize window
  ContextSettings settings;
  settings.depthBits = 24;
  settings.stencilBits = 8;
  settings.antialiasingLevel = 4;
  this->window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pong", Style::Default, settings);
  this->window.setFramerateLimit(60);

  cout << "Window created" << endl;



  // Initialize font
  if (!this->main_font.loadFromFile("../assets/roboto.ttf"))
    exit(1);

  cout << "Font loaded" << endl;


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