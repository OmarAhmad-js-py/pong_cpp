#ifndef PONG_SPEEDPOWERUP_H
#define PONG_SPEEDPOWERUP_H

#include "PowerUp.h"
#include "SFML/Graphics.hpp"

using namespace sf;

class SpeedPowerUp : public PowerUp {
public:
  SpeedPowerUp()
      : PowerUp(loadTexture("../assets/powerups/speed.png"), seconds(15.0f)) {
    printf("Power up: Created speed power-up with lifetime of %i seconds\n", (int) this->m_duration.asSeconds());
    m_effect = PowerUpEffect::GOOD;
  }

  void applyTo(Player *player) override {
    // increase the player's speed
    player->getBody()->setOutlineThickness(3);
    player->getBody()->setOutlineColor(Color::Blue);
    player->setSpeed(player->initialSpeed * 1.5);
  }

  void revert(Player *player) override {
    // decrease the player's speed
    player->getBody()->setOutlineThickness(0);
    player->setSpeed(player->initialSpeed);
  }
};

#endif//PONG_SPEEDPOWERUP_H
