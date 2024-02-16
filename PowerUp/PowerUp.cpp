#include "PowerUp.h"

PowerUp::PowerUp(sf::Texture &texture, sf::Time duration)
    : m_duration(duration),
      m_texture(texture),
      m_timeRemaining(duration) {
  m_window = GameHandler::getInstance().getWindow();
  m_sprite.setOrigin(m_texture.getSize().x / 2.0f, m_texture.getSize().y / 2.0f);
  m_sprite = createSprite();
}

void PowerUp::draw() {
  if (m_isAssigned) return;
  m_window->draw(m_sprite);
}

bool PowerUp::isExpired() {
  return m_timeRemaining <= Time::Zero;
}

void PowerUp::decrementTime(const sf::Time &delta) {
  printf("%f\n",  m_timeRemaining.asSeconds());
  m_timeRemaining -= delta;
}

void PowerUp::setAssignedToPlayer() {
  m_isAssigned = true;
}

bool PowerUp::isAssignedToPlayer() {
  return m_isAssigned;
}

void PowerUp::setPosition(const sf::Vector2f &position) {
  m_position = position;
  m_sprite.setPosition(position);
}

Texture &PowerUp::loadTexture(const std::string &path) {
  static Texture texture;
  if (!texture.loadFromFile(path)) {
    // handle error here
    throw std::runtime_error("Failed to load power-up texture");
  }
  printf("Power up: Loaded power-up texture from %s\n", path.c_str());
  return texture;
}

Sprite PowerUp::createSprite() const {
  Sprite sprite(m_texture);
  sprite.setScale(m_size / m_texture.getSize().x, m_size / m_texture.getSize().y);
  sprite.setOrigin(m_texture.getSize().x / 2.0f, m_texture.getSize().y / 2.0f);
  return sprite;
}

FloatRect PowerUp::getGlobalBounds() {
  return m_sprite.getGlobalBounds();
}

PowerUpEffect PowerUp::getEffect() const {
  return m_effect;
}
