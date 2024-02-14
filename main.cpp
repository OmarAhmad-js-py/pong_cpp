#include "Ball/Ball.h"
#include "Player/Player.h"
#include "PointCounter/PointCounter.h"
#include "PowerUp/SpeedPowerUp.h"
#include "random"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main() {

  RenderWindow *window = GameHandler::getInstance().getWindow();

  EntityHandler::getInstance().init_players();
  EntityHandler::getInstance().init_ball();
  EntityHandler::getInstance().init_pointCounter();

  vector<Player> *players = EntityHandler::getInstance().getPlayers();
  Ball *ball = EntityHandler::getInstance().getBall();
  PointCounter *pointCounter = EntityHandler::getInstance().getPointCounter();

  SpeedPowerUp speedPowerUp;

  players->at(0).applyPowerUp(&speedPowerUp);

  Clock clock;
  /**
  * Main Loop
  */
  while (window->isOpen()) {

    Time deltaTime = clock.restart();

    Event event{};
    while (window->pollEvent(event)) {
      if (event.type == Event::Closed) {
        window->close();
      }
    }

    window->clear(Color::Black);

    for (int index = 0; index < players->size(); index++) {
      Player &player = players->at(index);
      player.draw();
      player.update(index, deltaTime);
    }

    ball->draw();
    ball->update();

    pointCounter->draw();

    window->display();
  }

  return 0;
}