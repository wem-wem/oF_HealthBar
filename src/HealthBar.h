
#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxXmlSettings.h"


struct PlayerDate {
  int playerNum;  // プレイヤー番号
  int health; // 現在ＨＰ
  int maxHealth;  // 最大ＨＰ
  float currentBarScale; // 現在のＨＰバーの長さ
  float maxBarScale;  // 元々のＨＰバーの長さ
};

class HealthBar {
private:
  enum PlayerNumber {
    PlayerOne = 0,
    PlayerTwo = 1,
  };

  PlayerDate player_;

  ofxPanel gui_;
  ofParameter<ofVec2f> barScale_;
  ofxButton save_;
  ofxButton load_;

  void drawLeft();
  void drawRight();
  void guiSetup();
  void saveFile();
  void loadFile();

public:
  // ＨＰバー生成時にプレイヤー番号と最大ＨＰを受け取る
  HealthBar(const int playerNum, const int maxHealth);

  void setup();
  void draw();
  void remnant(int damage);
};
