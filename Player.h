#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-integer-division"
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

float PlayerOffset = 50.0f;
float PlayerSpeed = 10.0f;

class Player {
public:
  Player(RenderWindow *current_window, PlayerSide side, Keyboard::Key up, Keyboard::Key down) {
    this->window = current_window;
    this->pos_y = static_cast<float>(this->window->getSize().y / 2);
    RectangleShape _body;
    _body.setSize(Vector2f(width, height));
    _body.setOrigin(width / 2, height / 2);
    _body.setFillColor(Color::White);

    float _pos_x;
    switch (side) {
      case PlayerSide::LEFT:
        _pos_x = PlayerOffset;
        break;
      case PlayerSide::RIGHT:
        _pos_x = static_cast<float>(this->window->getSize().x) - PlayerOffset - width;
        break;
    }

    _body.setPosition(Vector2f(_pos_x, pos_y));
    this->body = _body;

    this->up_key = up;
    this->down_Key = down;
  }

  void update() {
    if (Keyboard::isKeyPressed(up_key)) body.move(0, -PlayerSpeed);
    if (Keyboard::isKeyPressed(down_Key)) body.move(0, PlayerSpeed);
  }

  void draw() {
    window->draw(body);
  }

private:
  Keyboard::Key up_key;
  Keyboard::Key down_Key;
  RectangleShape body;
  RenderWindow *window;
  float pos_y;
  float width = 30.0f;
  float height = 100.0f;
};
#pragma clang diagnostic pop