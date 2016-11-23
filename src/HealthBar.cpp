
#include "HealthBar.h"


// プレイヤーデータの初期化
HealthBar::HealthBar(const int playerNum, const int maxHealth) {
  player_.playerNum = playerNum; 
  player_.health = player_.maxHealth = maxHealth;
}

void HealthBar::setup() {
  guiSetup();
  loadFile(); // デフォルトの設定を最初に読み込む

  // 元のバーの長さをロードして代入。同じ値を現在ＨＰのバーの長さにも代入
  player_.currentBarScale = player_.maxBarScale = barScale_.get().x;
}

void HealthBar::draw() {
  // プレイヤー番号に応じて表示位置をズラす
  switch (player_.playerNum) {
  case PlayerOne:
    drawLeft();
    break;

  case PlayerTwo:
    drawRight();
    break;

  default:  // 例外の数字が入力された場合は１Ｐ側を表示
    drawLeft();
    break;
  }
}

// 1Pなら
void HealthBar::drawLeft(){
  ofRect(0, 0,
    (ofGetWidth() / 2) * player_.currentBarScale,
    (ofGetHeight() / 2) * barScale_.get().y);
}

// 2Pなら
void HealthBar::drawRight() {
  ofRect(ofGetWidth() - ((ofGetWidth() / 2) * player_.currentBarScale), 0,
    (ofGetWidth() / 2) * player_.currentBarScale,
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

// ダメージを受けた際に使用
void HealthBar::remnant(int damage) {
  player_.health -= damage;  // 現在ＨＰからダメージ分減らす
  float restHealth = (float)player_.health / player_.maxHealth;  // 現在ＨＰが最大ＨＰの何％になったか
  float newBarScale = player_.maxBarScale * restHealth;  // 元のバーの長さから同じ％分だけ長さを短くする
  player_.currentBarScale = newBarScale;
}
