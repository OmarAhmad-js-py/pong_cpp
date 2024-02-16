#include "TextureHandler.h"

#include <iostream>

using namespace std;

TextureHandler::TextureHandler() {
  string texturesPaths[] = {
      "../assets/power_ups/grow.png",
      "../assets/power_ups/shrink.png",
      "../assets/power_ups/slow.png",
      "../assets/power_ups/speed.png",
  };

  cout << "TextureHandler: Loading "
       << sizeof(texturesPaths) / sizeof(texturesPaths[0])
       << " textures..." << endl;

  for (auto &texture: texturesPaths) {
    cout << "TextureHandler: Loading texture: " << texture << endl;
    this->loadTexture(texture);
  }

  cout << "TextureHandler: Textures loaded" << endl;
}

TextureHandler &TextureHandler::getInstance() {
  static TextureHandler instance;
  return instance;
}

void TextureHandler::loadTexture(const string &path) {
  sf::Texture texture;
  if (!texture.loadFromFile(path)) {
    throw runtime_error("Failed to load texture: " + path);
  }
  textures[path] = texture;
}

Texture &TextureHandler::getTexture(const std::string &path) {
  auto it = textures.find(path);
  if (it != textures.end())
    return it->second;
  else
    throw runtime_error("Texture not loaded: " + path);
}