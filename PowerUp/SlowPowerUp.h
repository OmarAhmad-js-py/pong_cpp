#ifndef PONG_SLOWPOWERUP_H
#define PONG_SLOWPOWERUP_H

#include "PowerUp.h"
#include "SFML/Graphics.hpp"

using namespace sf;

class SlowPowerUp : public PowerUp {
public:
  SlowPowerUp()
      : PowerUp(loadTexture("../assets/powerups/slow.png"),
                seconds(15.0f)) {
    printf("Power up: Created slow power-up with lifetime of %i seconds\n", (int) this->m_duration.asSeconds());
    m_effect = PowerUpEffect::BAD;
  }

  void applyTo(Player *player) override {
    // decrease the player's speed
    player->getBody()->setOutlineThickness(3);
    player->getBody()->setOutlineColor(Color::Magenta);
    player->setSpeed(player->initialSpeed * 0.5);
  }

  void revert(Player *player) override {
    // increase the player's speed
    player->getBody()->setOutlineThickness(0);
    player->setSpeed(player->initialSpeed);
  }
};

#endif//PONG_SLOWPOWERUP_H
