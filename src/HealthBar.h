
#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxXmlSettings.h"
#include "HealthCalculator.h"


struct PlayerDate {
  int health; // ���݂g�o
  int maxHealth;  // �ő�g�o
  float currentHealth; // ���݂̂g�o����(�g�o�o�[�̒���)
  float maxBarScale;
};

class HealthBar {
private:
  PlayerDate player_[2];

  ofxPanel gui_;
  ofParameter<ofVec2f> barScale_;
  ofxButton save_;
  ofxButton load_;
public:
  void setup();
  void draw(ofEventArgs &args);

  void drawLeft();
  void drawRight();

  void guiSetup();
  void saveFile();
  void loadFile();
};
