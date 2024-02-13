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

  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pong",
                          sf::Style::Titlebar | sf::Style::Close, settings);

  Font main_font;
  if (!main_font.loadFromFile("../assets/roboto.ttf"))
    return EXIT_FAILURE;


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

    window.display();
  }

  return 0;
}