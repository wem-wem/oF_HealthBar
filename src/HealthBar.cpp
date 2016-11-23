
#include "HealthBar.h"


// �v���C���[�f�[�^�̏�����
HealthBar::HealthBar(const int playerNum, const int maxHealth) {
  player_.playerNum = playerNum; 
  player_.health = player_.maxHealth = maxHealth;
}

void HealthBar::setup() {
  guiSetup();
  loadFile(); // �f�t�H���g�̐ݒ���ŏ��ɓǂݍ���

  // ���̃o�[�̒��������[�h���đ���B�����l�����݂g�o�̃o�[�̒����ɂ����
  player_.currentBarScale = player_.maxBarScale = barScale_.get().x;
}

void HealthBar::draw() {
  // �v���C���[�ԍ��ɉ����ĕ\���ʒu���Y����
  switch (player_.playerNum) {
  case PlayerOne:
    drawLeft();
    break;

  case PlayerTwo:
    drawRight();
    break;

  default:  // ��O�̐��������͂��ꂽ�ꍇ�͂P�o����\��
    drawLeft();
    break;
  }
}

// 1P�Ȃ�
void HealthBar::drawLeft(){
  ofRect(0, 0,
    (ofGetWidth() / 2) * player_.currentBarScale,
    (ofGetHeight() / 2) * barScale_.get().y);
}

// 2P�Ȃ�
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

// �_���[�W���󂯂��ۂɎg�p
void HealthBar::remnant(int damage) {
  player_.health -= damage;  // ���݂g�o����_���[�W�����炷
  float restHealth = (float)player_.health / player_.maxHealth;  // ���݂g�o���ő�g�o�̉����ɂȂ�����
  float newBarScale = player_.maxBarScale * restHealth;  // ���̃o�[�̒������瓯����������������Z������
  player_.currentBarScale = newBarScale;
}
