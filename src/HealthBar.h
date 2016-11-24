
#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxXmlSettings.h"


struct PlayerDate {
  int playerNum;  // �v���C���[�ԍ�
  int health; // ���݂g�o
  int maxHealth;  // �ő�g�o
  float currentBarScale; // ���݂̂g�o�o�[�̒���
  float maxBarScale;  // ���X�̂g�o�o�[�̒���
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

  bool test = false;
  float damage = 0;
  void drawDamage(float damageCurrent);

public:
  // �g�o�o�[�������Ƀv���C���[�ԍ��ƍő�g�o���󂯎��
  HealthBar(const int playerNum, const int maxHealth);

  void setup();
  void draw();
  void remnant(int damage);
};
