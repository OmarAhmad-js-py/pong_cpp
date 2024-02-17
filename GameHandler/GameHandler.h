#ifndef PONG_GAMEHANDLER_H
#define PONG_GAMEHANDLER_H

#include "../MenuHandler/MenuHandler.h"
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

class GameHandler {
public:
  GameHandler();
  static GameHandler &getInstance();

  RenderWindow *getWindow();
  Font &getFont();

  void setGameState(GameState state);
  GameState getGameState();

private:
  RenderWindow window;
  Font main_font;


public:
  // Disable copy and assign
  GameHandler(const GameHandler &) = delete;
  void operator=(const GameHandler &) = delete;
  int window_height;
  int window_width;
  GameState gameState = GameState::MENU;
};

#endif//PONG_GAMEHANDLER_H