#ifndef PONG_POWERUP_H
#define PONG_POWERUP_H

#include "../EntityHandler/EntityHandler.h"
#include "../GameHandler/GameHandler.h"
#include <SFML/Graphics.hpp>

class Player;

enum PowerUpEffect {
  BAD,
  GOOD
};

using namespace sf;

class PowerUp {
public:
  PowerUp(Texture &texture, Time duration);

  virtual void applyTo(Player *player) = 0;

  virtual void revert(Player *player) = 0;

  virtual void draw();

  bool isExpired();

  void decrementTime(const Time &delta);

  void setAssignedToPlayer();

  bool isAssignedToPlayer();

  void setPosition(const Vector2f &position);

  FloatRect getGlobalBounds();

  static Texture &loadTexture(const std::string &path);

  Sprite createSprite() const;

  PowerUpEffect getEffect() const;

protected:
  Texture &m_texture;
  Time m_duration;
  Sprite m_sprite;
  bool m_isAssigned = false;
  Vector2f m_position;
  RenderWindow *m_window;
  float m_size = 32.0f;
  PowerUpEffect m_effect;

private:
  Time m_timeRemaining;
};

#endif//PONG_POWERUP_H
