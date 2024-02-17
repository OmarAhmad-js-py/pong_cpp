#include "PowerUp.h"

PowerUp::PowerUp(const std::string &texturePath, sf::Time duration)
    : m_duration(duration),
      m_texture(TextureHandler::getInstance().getTexture(texturePath)),
      m_timeRemaining(duration) {
  m_window = GameHandler::getInstance().getWindow();

  Vector2<float> textureSize = (Vector2f) m_texture.getSize();
  m_sprite.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
  Sprite sprite(m_texture);
  sprite.setScale(m_size / textureSize.x, m_size / textureSize.y);
  sprite.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
  m_sprite = sprite;
}

void PowerUp::draw() {
  if (m_isAssigned) return;
  m_window->draw(m_sprite);
}

bool PowerUp::isExpired() {
  return m_timeRemaining <= Time::Zero;
}

void PowerUp::decrementTime(const sf::Time &delta) {
  m_timeRemaining -= delta;
}

void PowerUp::setAssignedToPlayer() {
  m_isAssigned = true;
}

void PowerUp::setPosition(const sf::Vector2f &position) {
  m_sprite.setPosition(position);
}

FloatRect PowerUp::getGlobalBounds() {
  return m_sprite.getGlobalBounds();
}

PowerUpEffect PowerUp::getEffect() const {
  return m_effect;
}
bool PowerUp::isAssigned() const {
  return m_isAssigned;
}
