
#include "HealthBar.h"


void HealthBar::setup(Player *player) {
  if (player_ == nullptr) { return; }
  player_ = player;
  guiSetup();
  loadFile(); // �f�t�H���g�̐ݒ���ŏ��ɓǂݍ���
  tempHealth = player_->getMaxHP();  // ��r�p�g�o�ɍő�l����
  currentScale = barScale_.get().x; // �o�[�̌��̒��������[�h���đ��
  ofAddListener(ofEvents().update, this, &HealthBar::update);
}

void HealthBar::update(ofEventArgs &args) {
  if (damageScale != 0) {
    for (int i = 0; i < ofGetFrameRate()/4; i++) {
      damageScale = damageScale - (damageScale / ofGetFrameRate()/4);
    }
  }
}

void HealthBar::draw() {
  if (player_ == nullptr) { return; }
  // �v���C���[�ԍ��ɉ����ĕ\���ʒu���Y����
  switch (player_->getID()) {
  case PlayerOne:
    drawLeft();
    if (player_->getHP() != tempHealth) {
      setDamageScale();
    }
    updateLeft();
    break;

  case PlayerTwo:
    drawRight();
    if (player_->getHP() != tempHealth) {
      setDamageScale();
    }
    updateRight();
    break;

  default:  // ��O�̐��������͂��ꂽ�ꍇ�͂P�o����\��
    drawLeft();
    if (player_->getHP() != tempHealth) {
      setDamageScale();
    }
    updateLeft();
    break;
  }
}

// 1P�Ȃ�
void HealthBar::drawLeft() {
  ofRect(0, 0,
    (ofGetWidth() / 2) * currentScale,
    (ofGetHeight() / 2) * barScale_.get().y);
}

// 2P�Ȃ�
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

// ������̂g�o�o�[�̒��������߂�
float HealthBar::remnant() {
  float restHealth = (float)player_->getHP() / (float)player_->getMaxHP();  // ���݂g�o���ő�g�o�̉����ɂȂ�����
  float newBarScale = barScale_.get().x * restHealth;  // ���̃o�[�̒������瓯����������������Z������
  return newBarScale;
}

void HealthBar::setDamageScale() {
  float damageCurrent = currentScale - remnant(); // �ԃQ�[�W�̒���(���݂̒��� - ��_���v�Z��̒���)
  currentScale = remnant(); // �g�o�o�[�̒������X�V
  damageScale = damageCurrent;
}

// �P�o�̂g�o������
void HealthBar::updateLeft() {
  // �_���[�W�̐Ԃ��o�[�̕\��
  ofPushStyle();
  ofSetColor(255, 0, 0);
  ofRect((ofGetWidth() / 2) * currentScale, 0,
    (ofGetWidth() / 2) * damageScale,
    (ofGetHeight() / 2) * barScale_.get().y);
  ofPopStyle();
  tempHealth = player_->getHP();  // ���݂g�o�̍X�V
}

// �Q�o�̂g�o������
void HealthBar::updateRight() {
  // �_���[�W�̐Ԃ��o�[�̕\��
  ofPushStyle();
  ofSetColor(255, 0, 0);
  ofRect(ofGetWidth() - ((ofGetWidth() / 2) * (currentScale + damageScale)), 0,
    (ofGetWidth() / 2) * damageScale,
    (ofGetHeight() / 2) * barScale_.get().y);
  ofPopStyle();
  tempHealth = player_->getHP();  // ���݂g�o�̍X�V
}
