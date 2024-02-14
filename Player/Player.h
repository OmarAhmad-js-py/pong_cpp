#ifndef PONG_PLAYER_H
#define PONG_PLAYER_H

#endif//PONG_PLAYER_H

#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

enum PlayerSide {
  LEFT = 0,
  RIGHT = 1
};

class Player {
public:
  Player(PlayerSide side, Keyboard::Key up, Keyboard::Key down);

  void update(int index);
  void draw();
  PlayerSide getSide();
  FloatRect getGlobalBounds();
  Vector2f getCoords();
  static bool isOwningBall(int index);
  void reset();

private:
  Keyboard::Key up_key;
  Keyboard::Key down_Key;
  RectangleShape body;
  RenderWindow *window;
  float pos_y;
  float width = 15.0f;
  float height = 100.0f;

  PlayerSide side = PlayerSide::LEFT;
};