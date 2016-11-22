
#include "HealthBar.h"


void HealthBar::setup() {
  guiSetup();
  loadFile(); // デフォルトの設定を最初に読み込む
  player_[0].currentHealth = player_[0].maxBarScale = barScale_.get().x;
  player_[1].currentHealth = player_[1].maxBarScale = barScale_.get().x;

  ofAddListener(ofEvents().draw, this, &HealthBar::draw);
}

void HealthBar::draw(ofEventArgs &args) {
  drawLeft();
  drawRight();
}

void HealthBar::drawLeft(){
  ofRect(0, 0,
    (ofGetWidth() / 2) * player_[0].currentHealth,
    (ofGetHeight() / 2) * barScale_.get().y);
}

void HealthBar::drawRight() {
  ofRect(ofGetWidth() - ((ofGetWidth() / 2) * player_[1].currentHealth), 0,
    (ofGetWidth() / 2) * player_[1].currentHealth,
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
