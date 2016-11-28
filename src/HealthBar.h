
#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxXmlSettings.h"
#include "player.h"

class HealthBar {
private:
  float currentScale; // ���݂g�o�o�[�̒���
  float tempHealth; // ��e�O�̂g�o���ꎞ�ۑ����Ă�����
  float damageScale;  // �_���[�W�o�[�̒������ꎞ�ۑ����Ă�����

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
