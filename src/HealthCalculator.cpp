
#include "HealthCalculator.h"


float HealthCalculator::remnant(PlayerDate player, int damage) {
  player.health -= damage;  // ���݂g�o����_���[�W�����炷
  float restHealth = player.health / player.maxHealth;  // ���݂g�o���ő�g�o�̉����ɂȂ�����
  float newBarScale = player.maxBarScale * restHealth;  // ���̃o�[�̒������瓯����������������Z������
  return newBarScale;
}

float HealthCalculator::percentage() {}
