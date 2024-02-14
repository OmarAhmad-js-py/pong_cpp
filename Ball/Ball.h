#include "../EntityHandler/EntityHandler.h"
#include "../GameHandler/GameHandler.h"
#include "../RandomEngine.h"
#include <iostream>
#ifndef PONG_BALL_H
#define PONG_BALL_H

#endif//PONG_BALL_H

#pragma once

using namespace sf;
using namespace std;


class Ball {
public:
  Ball();

  void update();

  void draw();
  void reset();

private:
  vector<Player> *players;
  CircleShape body;
  RenderWindow *window;
  float pos_y;
  float pos_x;
  float angle = 0.0f;
  Vector2f angleChangePos;
  float radius = 15.0f;
  float speed = 10.0f;
};