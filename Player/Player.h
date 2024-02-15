#ifndef PONG_PLAYER_H
#define PONG_PLAYER_H

#endif//PONG_PLAYER_H

#pragma once
#include "../PowerUp/PowerUp.h"
#include "SFML/Graphics.hpp"
#include <memory>

using namespace sf;

enum PlayerSide {
  LEFT = 0,
  RIGHT = 1
};

class Player {
public:
  Player(PlayerSide side, Keyboard::Key up, Keyboard::Key down);

  void update(int index, Time deltaTime);
  void draw();
  PlayerSide getSide();
  FloatRect getGlobalBounds();
  RectangleShape *getBody();
  static bool isOwningBall(int index);

  float playerOffset = 50.0f;

  float initialSpeed = 10.0f;
  void setSpeed(float _speed);

  float initialHeight = 100.0f;
  void setHeight(float _height);

  void reset();

  void applyPowerUp(PowerUp *powerUp);
  void removeExpiredPowerUps();


private:
  Keyboard::Key up_key;
  Keyboard::Key down_Key;
  RectangleShape body;
  RenderWindow *window;
  float pos_y;
  float width = 15.0f;
  float height = initialHeight;
  float speed = initialSpeed;

  PlayerSide side = PlayerSide::LEFT;

  std::vector<PowerUp *> activePowerUps;
};