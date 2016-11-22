
#include "HealthCalculator.h"


float HealthCalculator::remnant(PlayerDate player, int damage) {
  player.health -= damage;  // Œ»İ‚g‚o‚©‚çƒ_ƒ[ƒW•ªŒ¸‚ç‚·
  float restHealth = player.health / player.maxHealth;  // Œ»İ‚g‚o‚ªÅ‘å‚g‚o‚Ì‰½“‚É‚È‚Á‚½‚©
  float newBarScale = player.maxBarScale * restHealth;  // Œ³‚Ìƒo[‚Ì’·‚³‚©‚ç“¯‚¶“•ª‚¾‚¯’·‚³‚ğ’Z‚­‚·‚é
  return newBarScale;
}

float HealthCalculator::percentage() {}
