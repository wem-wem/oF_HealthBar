
#pragma once
#include "ofMain.h"


class Player {
private:
  int id_;
  int HP_;
  int maxHP_;
  
public:
  void setup(int ID, int MaxHP);
  
  // ダメージを食らう場合この関数を通してダメージを受ける
  // 受けたダメージ量を返す
  int damage(int damage);
  
  const int getID();
  const int getMaxHP();
  const int getHP();
};
