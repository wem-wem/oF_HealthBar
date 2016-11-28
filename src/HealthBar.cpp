
#include "HealthBar.h"


void HealthBar::setup(Player &player) {
  guiSetup();
  loadFile(); // デフォルトの設定を最初に読み込む
  tempHealth = player.getMaxHP();  // 比較用ＨＰに最大値を代入
  currentScale = barScale_.get().x; // バーの元の長さをロードして代入
  ofAddListener(ofEvents().update, this, &HealthBar::update);
}

void HealthBar::update(ofEventArgs &args) {
  if (damageScale != 0) {
    for (int i = 0; i < ofGetFrameRate()/4; i++) {
      damageScale = damageScale - (damageScale / ofGetFrameRate()/4);
    }
  }
}

void HealthBar::draw(Player &player) {
  // プレイヤー番号に応じて表示位置をズラす
  switch (player.getID()) {
  case 0:
    drawLeft();
    if (player.getHP() != tempHealth) {
      setDamageScale(player);
    }
    updateLeft(player);
    break;

  case 1:
    drawRight();
    if (player.getHP() != tempHealth) {
      setDamageScale(player);
    }
    updateRight(player);
    break;

  default:  // 例外の数字が入力された場合は１Ｐ側を表示
    drawLeft();
    if (player.getHP() != tempHealth) {
      setDamageScale(player);
    }
    updateLeft(player);
    break;
  }
}

// 1Pなら
void HealthBar::drawLeft() {
  ofRect(0, 0,
    (ofGetWidth() / 2) * currentScale,
    (ofGetHeight() / 2) * barScale_.get().y);
}

// 2Pなら
void HealthBar::drawRight() {
  ofRect(ofGetWidth() - ((ofGetWidth() / 2) * currentScale), 0,
    (ofGetWidth() / 2) * currentScale,
    (ofGetHeight() / 2) * barScale_.get().y);
}

void HealthBar::guiSetup() {
  save_.addListener(this, &HealthBar::saveFile);
  load_.addListener(this, &HealthBar::loadFile);

  gui_.setup();
  gui_.add(barScale_.set("BarScale", ofVec2f(1, 1), ofVec2f(0, 0), ofVec2f(1, 1)));
  gui_.add(save_.setup("Save_BarScale"));
  gui_.add(load_.setup("Loda_BarScale"));
}

void HealthBar::saveFile() {
  gui_.saveToFile("Game/HealthBarSettings.xml");
}

void HealthBar::loadFile() {
  gui_.loadFromFile("Game/HealthBarSettings.xml");
}

// 減少後のＨＰバーの長さを求める
float HealthBar::remnant(Player &player) {
  float restHealth = (float)player.getHP() / (float)player.getMaxHP();  // 現在ＨＰが最大ＨＰの何％になったか
  float newBarScale = barScale_.get().x * restHealth;  // 元のバーの長さから同じ％分だけ長さを短くする
  return newBarScale;
}

void HealthBar::setDamageScale(Player &player) {
  float damageCurrent = currentScale - remnant(player); // 赤ゲージの長さ(現在の長さ - 被ダメ計算後の長さ)
  currentScale = remnant(player); // ＨＰバーの長さを更新
  damageScale = damageCurrent;
}

// １ＰのＨＰ減少時
void HealthBar::updateLeft(Player &player) {
  // ダメージの赤いバーの表示
  ofPushStyle();
  ofSetColor(255, 0, 0);
  ofRect((ofGetWidth() / 2) * currentScale, 0,
    (ofGetWidth() / 2) * damageScale,
    (ofGetHeight() / 2) * barScale_.get().y);
  ofPopStyle();
  tempHealth = player.getHP();  // 現在ＨＰの更新
}

// ２ＰのＨＰ減少時
void HealthBar::updateRight(Player &player) {
  // ダメージの赤いバーの表示
  ofPushStyle();
  ofSetColor(255, 0, 0);
  ofRect(ofGetWidth() - ((ofGetWidth() / 2) * (currentScale + damageScale)), 0,
    (ofGetWidth() / 2) * damageScale,
    (ofGetHeight() / 2) * barScale_.get().y);
  ofPopStyle();
  tempHealth = player.getHP();  // 現在ＨＰの更新
}
