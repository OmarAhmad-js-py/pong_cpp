#ifndef PONG_SPEEDPOWERUP_H
#define PONG_SPEEDPOWERUP_H

#include "PowerUp.h"
#include "SFML/Graphics.hpp"

using namespace sf;

class SpeedPowerUp : public PowerUp {
public:
  SpeedPowerUp()
      : PowerUp(loadTexture(), seconds(5.0f)) {
    printf("Power up: Created speed power-up with lifetime of %f seconds\n", this->m_duration.asSeconds());
  }

  void applyTo(Player &player) override {
    // increase the player's speed
    player.getBody()->setOutlineThickness(3);
    player.getBody()->setOutlineColor(Color::Blue);
    player.setSpeed(player.initialSpeed * 1.5);
  }

  void revert(Player &player) override {
    // decrease the player's speed
    player.getBody()->setOutlineThickness(0);
    player.setSpeed(player.initialSpeed);
  }

  static Texture &loadTexture() {
    static Texture texture;
    if (!texture.loadFromFile("../assets/powerups/speed.png")) {
      // handle error here
      throw std::runtime_error("Failed to load speed power-up texture");
    }
    return texture;
  }
};

#endif//PONG_SPEEDPOWERUP_H
