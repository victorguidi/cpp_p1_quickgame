#include "person.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

void LifeSpecs::init(int lifeValue, int shieldValue) {
  Life = lifeValue;
  Shield = shieldValue;
}

void LifeSpecs::lifeInfo() {
  std::cout << "Life: " << Life << std::endl;
  std::cout << "Shield: " << Shield << std::endl;
}

int LifeSpecs::returnLifeValue() { return Life; }

int LifeSpecs::returnShieldValue() { return Shield; }

void LifeSpecs::changeLifeValue(int valueToIncrease) {
  Life = Life + valueToIncrease;
}

void LifeSpecs::changeShieldValue(int valueToIncrease) {
  Shield = Shield + valueToIncrease;
}

void Skills::init(int powerValue, int staminaValue) {
  Power = powerValue;
  Stamina = staminaValue;
}

void Skills::skillsInfo() {
  std::cout << "Power: " << Power << std::endl;
  std::cout << "Stamina: " << Stamina << std::endl;
}

void Skills::IncreasePower(int valueToIncrease) {
  Power = Power + valueToIncrease;
}

void Skills::IncreaseStamina(int valueToIncrease) {
  Stamina = Stamina + valueToIncrease;
}

void Inventory::addItems(std::string item) { Items.push_back(item); }

void Inventory::ListItems() {
  for (std::string i : Items) {
    std::cout << i << " ";
  }
  std::cout << '\n';
}

Player::Player(std::string name) {
  Name = name;
  Life.init(100, 100);
  Skill.init(25, 10);
  Inventory();
}

void Player::returnPlayerInfo() {
  std::cout << Name << '\n', Life.lifeInfo(), Skill.skillsInfo(), listItems();
}

void Player::changeLifeValue(int value) { Life.changeLifeValue(value); }
void Player::changeShieldValue(int value) { Life.changeShieldValue(value); }

void Player::changePowerValue(int value) { Skill.IncreasePower(value); }
void Player::changeStaminaValue(int value) { Skill.IncreaseStamina(value); }

void Player::addItems(std::string item) { Inv.addItems(item); }
void Player::listItems() { Inv.ListItems(); }

bool Player::attack(int value, Player *player) {

  std::srand(time(0));
  int randomNumber;

  if (player->Life.returnLifeValue() > 1) {
    randomNumber = -rand() % player->Life.returnLifeValue();
  } else {
    randomNumber = -rand() % value;
  }

  if (player->Life.returnShieldValue() < 0) {
    player->Life.changeLifeValue(randomNumber);
  } else {
    player->changeShieldValue(randomNumber);
  }

  if (player->Life.returnLifeValue() <= 0) {
    return true;
  }
  return false;
}
