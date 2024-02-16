#ifndef PONG_TEXTUREHANDLER_H
#define PONG_TEXTUREHANDLER_H

#include <SFML/Graphics.hpp>
#include <map>

using namespace std;
using namespace sf;

class TextureHandler {
public:
  TextureHandler();
  static TextureHandler &getInstance();

  void loadTexture(const string &path);
  Texture &getTexture(const string &path);

private:
  map<string, Texture> textures;
};


#endif//PONG_TEXTUREHANDLER_H
