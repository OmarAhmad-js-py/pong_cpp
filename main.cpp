#include "Ball.h"
#include "Player.h"
#include "PointCounter.h"
#include "random"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

float PlayerOffset = 50.0f;
float PlayerSpeed = 10.0f;

int WINDOW_WIDTH = 800;
int WINDOW_HEIGHT = 600;

int main() {

  RenderWindow *window = GameHandler::getInstance().getWindow();

  EntityHandler::getInstance().init_players();
  EntityHandler::getInstance().init_ball();
  EntityHandler::getInstance().init_pointCounter();

  vector<Player> *players = EntityHandler::getInstance().getPlayers();
  Ball *ball = EntityHandler::getInstance().getBall();
  PointCounter *pointCounter = EntityHandler::getInstance().getPointCounter();

  /**
  * Main Loop
  */
  while (window->isOpen()) {
    Event event{};
    while (window->pollEvent(event)) {
      if (event.type == Event::Closed) {
        window->close();
      }
    }

    window->clear(Color::Black);
   for (auto &player: *players) {
      player.draw();
      player.update();
    }

    ball->draw();
    ball->update();

    pointCounter->draw();

    window->display();
  }

  return 0;
}