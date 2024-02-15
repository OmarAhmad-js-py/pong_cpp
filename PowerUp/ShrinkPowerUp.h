#ifndef PONG_SHRINKPOWERUP_H
#define PONG_SHRINKPOWERUP_H

#include "PowerUp.h"
#include "SFML/Graphics.hpp"

using namespace sf;

class ShrinkPowerUp : public PowerUp {
public:
  ShrinkPowerUp()
      : PowerUp(loadTexture(), seconds(5.0f)) {
    printf("Power up: Created shrink power-up with lifetime of %f seconds\n", this->m_duration.asSeconds());
    m_texture = loadTexture();
  }

  void applyTo(Player &player) override {
    // decrease the player's height
    player.setHeight(player.initialHeight * 0.5f);
  }

  void revert(Player &player) override {
    // increase the player's height
    player.setHeight(player.initialHeight);
  }

  static Texture &loadTexture() {
    static Texture texture;
    if (!texture.loadFromFile("../assets/powerups/shrink.png")) {
      // handle error here
      throw std::runtime_error("Failed to load slow power-up texture");
    }

    return texture;
  }
};

#endif//PONG_SHRINKPOWERUP_H
