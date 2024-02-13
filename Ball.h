#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-integer-division"
#include "RandomEngine.h"
#include <iostream>
#include "GameHandler.h"
#include "EntityHandler.h"
#ifndef PONG_BALL_H
#define PONG_BALL_H

#endif//PONG_BALL_H

#pragma once

using namespace sf;
using namespace std;


class Ball {
public:
  Ball() {
    cout << "Ball constructor started" << endl;
    this->window = GameHandler::getInstance().getWindow();
    cout << "In Ball constructor. Checking window properties:\n";
    cout << "Window size: " << this->window->getSize().x << ", " << this->window->getSize().y << endl;
    cout << "Is window open: " << this->window->isOpen() << endl;
    cout << "Ball constructor got window" << endl;
    this->players = EntityHandler::getInstance().getPlayers();
    cout << "Ball constructor got players" << endl;

    this->pos_y = static_cast<float>(this->window->getSize().y / 2);
    this->pos_x = static_cast<float>(this->window->getSize().x / 2);
    CircleShape _body;
    _body.setRadius(radius);
    _body.setPosition(pos_x, pos_y);
    _body.setOrigin(radius, radius);
    _body.setFillColor(Color::White);

    mt19937 &engine = RandomEngine::getInstance().getEngine();
    uniform_int_distribution<> startingAngle(0, 360);

    this->angle = static_cast<float>(startingAngle(engine));

    this->body = _body;
  }

  void update() {
    // Convert the angle to radians
    float angleRad = angle * 3.1415f / 180.0f;

    // Calculate new position based on the current angle
    pos_x += speed * cos(angleRad);
    pos_y += speed * sin(angleRad);

    // Check for collisions
    if (pos_y >= static_cast<float>(window->getSize().y) - radius || pos_y <= radius) {
      // Flip the angle if collision is on the top or bottom
      angle = -angle;
    }
    if (pos_x >= static_cast<float>(window->getSize().x) - radius || pos_x <= radius) {
      // Flip the angle
      angle = 180.0f - angle;
    }

    // Handle player collision
    std::vector<Player>::iterator it;
    int index = 0;
    for (it = players->begin(); it != players->end(); ++it, ++index) {
      Player &player = *it;
      if (body.getGlobalBounds().contains(angleChangePos)) break;
      if (player.getGlobalBounds().contains(pos_x, pos_y)) {
        float newAngle = 180.0f - angle;
        angle = newAngle;
        angleChangePos = player.getCoords();
        break;
      }
    }

    body.setPosition(pos_x, pos_y);
  }

  void draw() {
    window->draw(body);
  }

private:
  vector<Player>*players;
  CircleShape body;
  RenderWindow *window;
  float pos_y;
  float pos_x;
  float angle = 0.0f;
  Vector2f angleChangePos;
  float radius = 15.0f;
  float speed = 5.0f;
};
#pragma clang diagnostic pop