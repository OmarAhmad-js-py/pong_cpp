#ifndef PONG_MENUHANDLER_H
#define PONG_MENUHANDLER_H

#include "SFML/Graphics.hpp"

using namespace sf;

enum GameState {
  MENU,
  PLAY,
};

class MenuHandler {
public:
  MenuHandler();
  void draw();

private:
  Font font;
  Text title;

  RenderWindow *window;
};


#endif//PONG_MENUHANDLER_H
