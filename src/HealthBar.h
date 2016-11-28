
#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxXmlSettings.h"
#include "player.h"

class HealthBar {
private:
  float currentScale; // 現在ＨＰバーの長さ
  float tempHealth; // 被弾前のＨＰを一時保存しておく箱
  float damageScale;  // ダメージバーの長さを一時保存しておく箱

  ofxPanel gui_;
  ofParameter<ofVec2f> barScale_;
  ofxButton save_;
  ofxButton load_;

  void drawLeft();
  void drawRight();
  void guiSetup();
  void saveFile();
  void loadFile();
  float remnant(Player &player);
  void setDamageScale(Player &player);
  void updateLeft(Player &player);
  void updateRight(Player &player);
public:
  void setup(Player &player);
  void update(ofEventArgs &args);
  void draw(Player &player);
};
