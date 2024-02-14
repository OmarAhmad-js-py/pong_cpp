#include "EntityHandler.h"
#include "../Ball/Ball.h"
#include "../PointCounter/PointCounter.h"
#include <iostream>

EntityHandler::EntityHandler() = default;

void EntityHandler::init_players() {
  // Initialize players
  cout << "Initializing players" << endl;
  vector<Player> _players;
  _players.emplace_back(PlayerSide::LEFT, Keyboard::W, Keyboard::S);
  _players.emplace_back(PlayerSide::RIGHT, Keyboard::Up, Keyboard::Down);

  this->players = _players;

  cout << "Players created" << endl;
}

void EntityHandler::init_ball() {
  cout << "Initializing ball" << endl;
  // Initialize ball
  this->ball = new Ball();

  cout << "Ball created" << endl;
}

void EntityHandler::init_pointCounter() {
  cout << "Initializing point counter" << endl;
  // Initialize point counter
  this->pointCounter = new PointCounter();

  cout << "PointCounter created" << endl;
}

EntityHandler &EntityHandler::getInstance() {
  static EntityHandler instance;
  return instance;
}

vector<Player> *EntityHandler::getPlayers() {
  return &players;
}

Ball *EntityHandler::getBall() {
  return ball;
}

PointCounter *EntityHandler::getPointCounter() {
  return pointCounter;
}
int EntityHandler::getCurrentBallOwnerIndex() const {
  return currentBallOwnerIndex;
}
void EntityHandler::setBallOwnerIndex(int index) {
  currentBallOwnerIndex = index;
}

void EntityHandler::reset() {
  currentBallOwnerIndex = -1;
  ball->reset();
  for (auto &player : players) {
    player.reset();
  }
}
