#ifndef PONG_ENTITYHANDLER_H
#define PONG_ENTITYHANDLER_H

#include "Player.h"
#include "SFML/Graphics.hpp"

class Ball;
class PointCounter;

using namespace sf;
using namespace std;

class EntityHandler {
public:
  EntityHandler();
  static EntityHandler &getInstance();

  vector<Player> *getPlayers();
  Ball *getBall();
  PointCounter *getPointCounter();

  void init_players();
  void init_ball();
  void init_pointCounter();

  int getCurrentBallOwnerIndex();
  void setBallOwnerIndex(int index);

private:
  vector<Player> players;
  Ball *ball{};
  PointCounter *pointCounter{};
  int currentBallOwnerIndex = -1;

public:
  // Disable copy and assign
  EntityHandler(const EntityHandler &) = delete;
  void operator=(const EntityHandler &) = delete;
};

#endif//PONG_ENTITYHANDLER_H