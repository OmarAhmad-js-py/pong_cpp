#ifndef PONG_POWERUP_H
#define PONG_POWERUP_H

#include "../EntityHandler/EntityHandler.h"
#include "../TextureHandler/TextureHandler.h"
#include "../GameHandler/GameHandler.h"
#include <SFML/Graphics.hpp>

class Player;

enum PowerUpEffect {
  NONE,
  BAD,
  GOOD
};

using namespace sf;
using namespace std;

class PowerUp {
public:
  PowerUp(const string& texturePath, Time duration);

  virtual void applyTo(Player *player) = 0;

  virtual void revert(Player *player) = 0;

  virtual void draw();

  bool isExpired();

  void decrementTime(const Time &delta);

  void setAssignedToPlayer();

  void setPosition(const Vector2f &position);

  FloatRect getGlobalBounds();

  PowerUpEffect getEffect() const;

protected:
  Texture &m_texture;
  Time m_duration;
  Sprite m_sprite;
  bool m_isAssigned = false;
  RenderWindow *m_window;
  float m_size = 32.0f;
  PowerUpEffect m_effect = PowerUpEffect::NONE;

private:
  Time m_timeRemaining;
};

#endif//PONG_POWERUP_H
