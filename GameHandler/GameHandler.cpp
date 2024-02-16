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

  string texturesPaths[] = {
      "../assets/power_ups/grow.png",
      "../assets/power_ups/shrink.png",
      "../assets/power_ups/slow.png",
      "../assets/power_ups/speed.png",
  };

  cout << "GameHandler: Loading "
       <<sizeof(texturesPaths) / sizeof(texturesPaths[0])
       << " texturesPaths" << endl;

  for (auto &texture: texturesPaths) {
    cout << "GameHandler: Loading texture: " << texture << endl;
    this->loadTexture(texture);
  }

  cout << "GameHandler: Textures loaded" << endl;


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
void GameHandler::loadTexture(const string &path) {
  sf::Texture texture;
  if (!texture.loadFromFile(path)) {
    throw runtime_error("Failed to load texture: " + path);
  }
  textures[path] = texture;
}
Texture &GameHandler::getTexture(const string &path) {
  auto it = textures.find(path);
  if (it != textures.end())
    return it->second;
  else
    throw runtime_error("Texture not loaded: " + path);
}
