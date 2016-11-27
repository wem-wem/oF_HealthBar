
#include "player.h"


void Player::setup(int ID, int MaxHP) {
  // パラメータの初期化
  id_ = ID;
  maxHP_ = MaxHP;
  HP_ = maxHP_;
}


int Player::damage(int damage) {
  HP_ = int(HP_) - damage;
  if (HP_ < 0) { HP_ = 0; }
  return damage;
}

const int Player::getID() { return id_; }
const int Player::getMaxHP() { return maxHP_; }
const int Player::getHP()    { return HP_;    }
