#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-integer-division"
#ifndef PONG_BALL_H
#define PONG_BALL_H

#endif//PONG_BALL_H

#pragma once
#include "SFML/Graphics.hpp"
#include "random"

using namespace sf;
using namespace std;


class Ball {
public:
  Ball(RenderWindow *current_window, mt19937 *random_engine) {
    this->random_engine = random_engine;
    this->window = current_window;
    this->pos_y = static_cast<float>(this->window->getSize().y / 2);
    this->pos_x = static_cast<float>(this->window->getSize().x / 2);
    CircleShape _body;
    _body.setRadius(radius);
    _body.setPosition(pos_x, pos_y);
    _body.setOrigin(radius, radius);
    _body.setFillColor(Color::White);

    this->body = _body;
  }

  void update() {
  }

  void draw() {
    window->draw(body);
  }

private:
  CircleShape body;
  RenderWindow *window;
  float pos_y;
  float pos_x;
  float radius = 15.0f;
  float speed = 15.0f;
};
#pragma clang diagnostic pop