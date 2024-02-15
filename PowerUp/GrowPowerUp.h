#ifndef PONG_GROWPOWERUP_H
#define PONG_GROWPOWERUP_H

#include "PowerUp.h"
#include "SFML/Graphics.hpp"

using namespace sf;

class GrowPowerUp : public PowerUp {
public:
  GrowPowerUp()
      : PowerUp(loadTexture(), seconds(5.0f)) {
    printf("Power up: Created grow power-up with lifetime of %f seconds\n", this->m_duration.asSeconds());
  }

  void applyTo(Player &player) override {
    // increase the player's height
    player.setHeight(player.initialHeight * 1.5f);
  }

  void revert(Player &player) override {
    // decrease the player's height
    player.setHeight(player.initialHeight);
  }

  static Texture &loadTexture() {
    static Texture texture;
    if (!texture.loadFromFile("../assets/powerups/grow.png")) {
      // handle error here
      throw std::runtime_error("Failed to load slow power-up texture");
    }
    return texture;
  }
};

#endif//PONG_GROWPOWERUP_H
