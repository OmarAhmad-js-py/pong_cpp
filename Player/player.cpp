#include "Player.h"
#include "../EntityHandler/EntityHandler.h"
#include "../GameHandler/GameHandler.h"
extern float PlayerOffset;
extern float PlayerSpeed;

Player::Player(PlayerSide side, Keyboard::Key up, Keyboard::Key down) {
  this->window = GameHandler::getInstance().getWindow();
  this->pos_y = static_cast<float>(this->window->getSize().y / 2); // NOLINT(*-integer-division)
  RectangleShape _body;
  _body.setSize(Vector2f(width, height));
  _body.setOrigin(0.0f, height / 2);
  _body.setFillColor(Color::White);

  float _pos_x;
  switch (side) {
    case PlayerSide::LEFT:
      _pos_x = PlayerOffset;
      break;
    case PlayerSide::RIGHT:
      _pos_x = static_cast<float>(this->window->getSize().x) - PlayerOffset - width;
      break;
  }

  _body.setPosition(Vector2f(_pos_x, pos_y));
  this->body = _body;

  this->up_key = up;
  this->down_Key = down;

  this->side = side;
}

void Player::update(int index) {
  bool isBallOwner = isOwningBall(index);
  if (isBallOwner) body.setFillColor(Color::Red);
  else body.setFillColor(Color::White);

  Vector2<unsigned int> windowSize = this->window->getSize();
  Vector2f playerPosition = body.getPosition();
  if (Keyboard::isKeyPressed(up_key) && playerPosition.y > 0 + PlayerOffset) {
    body.move(0, -PlayerSpeed);
  }
  if (Keyboard::isKeyPressed(down_Key) && playerPosition.y < static_cast<float>(windowSize.y) - PlayerOffset) {
    body.move(0, PlayerSpeed);
  }
}

bool Player::isOwningBall(int index) {
  return EntityHandler::getInstance().getCurrentBallOwnerIndex() == index;
}

void Player::draw() {
  window->draw(body);
}

PlayerSide Player::getSide() {
  return side;
}

FloatRect Player::getGlobalBounds() {
  return body.getGlobalBounds();
}

Vector2f Player::getCoords() {
  return body.getPosition();
}

void Player::reset() {
  float _pos_x;
  switch (side) {
    case PlayerSide::LEFT:
      _pos_x = PlayerOffset;
      break;
    case PlayerSide::RIGHT:
      _pos_x = static_cast<float>(this->window->getSize().x) - PlayerOffset - width;
      break;
  }

  body.setPosition(Vector2f(_pos_x, pos_y));
}
