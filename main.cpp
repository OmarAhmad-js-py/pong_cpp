#include "Ball.h"
#include "Player.h"
#include "random"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main() {
  random_device rd;
  mt19937 engine(rd());

  int WINDOW_HEIGHT = 600;
  int WINDOW_WIDTH = 800;

  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;

  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                          "Pong",
                          sf::Style::Titlebar | sf::Style::Close,
                          settings);

  window.setFramerateLimit(60);

  Font main_font;
  if (!main_font.loadFromFile("../assets/roboto.ttf"))
    return EXIT_FAILURE;

  vector<Player> players;

  Player LeftPlayer = *new Player(&window, PlayerSide::LEFT, Keyboard::W, Keyboard::S);
  Player RightPlayer = *new Player(&window, PlayerSide::RIGHT, Keyboard::Up, Keyboard::Down);

  players.push_back(LeftPlayer);
  players.push_back(RightPlayer);

  Ball ball = *new Ball(&window, &engine);

  /**
  * Main Loop
  */
  while (window.isOpen()) {
    Event event{};
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
    }

    window.clear(Color::Black);

    for (auto &player: players) {
      player.draw();
      player.update();
    }

    ball.draw();

    window.display();
  }

  return 0;
}