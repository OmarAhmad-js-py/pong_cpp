#ifndef PONG_SLOWPOWERUP_H
#define PONG_SLOWPOWERUP_H

#include "PowerUp.h"
#include "SFML/Graphics.hpp"

using namespace sf;

class SlowPowerUp : public PowerUp {
public:
  SlowPowerUp()
      : PowerUp(loadTexture(), seconds(5.0f)) {
    printf("Power up: Created slow power-up with lifetime of %f seconds\n", this->m_duration.asSeconds());
  }

  void applyTo(Player &player) override {
    // decrease the player's speed
    player.getBody()->setOutlineThickness(3);
    player.getBody()->setOutlineColor(Color::Magenta);
    player.setSpeed(player.initialSpeed * 0.5);
  }

  void revert(Player &player) override {
    // increase the player's speed
    player.getBody()->setOutlineThickness(0);
    player.setSpeed(player.initialSpeed);
  }

  static Texture &loadTexture() {
    static Texture texture;
    if (!texture.loadFromFile("../assets/powerups/slow.png")) {
      throw std::runtime_error("Failed to load slow power-up texture");
    }
    return texture;
  }
};

#endif//PONG_SLOWPOWERUP_H
