#ifndef PONG_POINTCOUNTER_H
#define PONG_POINTCOUNTER_H

#endif//PONG_POINTCOUNTER_H

#include "../GameHandler/GameHandler.h"
#include "../Player/Player.h"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class PointCounter {
public:
  PointCounter();

  void draw();

  void increment(int index);

private:
  RenderWindow *window;
  Font *font;
  vector<Player> *players;
  vector<int> scores;
};
