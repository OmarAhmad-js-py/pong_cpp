#ifndef PONG_POWERUP_H
#define PONG_POWERUP_H

#include "../Player/Player.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Player;

class PowerUp {
public:
  PowerUp(Texture &texture, Time duration)
      : m_texture(texture),
        m_duration(duration),
        m_sprite(texture) {
    m_sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);
    m_timeRemaining = duration;
  }

  virtual void applyTo(Player &player) = 0;

  virtual void revert(Player &player) = 0;

  Texture &getTexture() {
    return m_texture;
  };

  Time getDuration() {
    return m_duration;
  };

  Sprite &getSprite() {
    return m_sprite;
  };

  bool isExpired() const {
    return m_timeRemaining <= Time::Zero;
  };

  void decrementTime(const Time &delta) {
    m_timeRemaining -= delta;
  }

protected:
  Texture &m_texture;
  Time m_duration;
  Sprite m_sprite;

private:
  Time m_timeRemaining;
};

#endif//PONG_POWERUP_H
