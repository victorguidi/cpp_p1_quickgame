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

void LifeSpecs::lifeInfo() const {
  std::cout << "Life: " << Life << std::endl;
  std::cout << "Shield: " << Shield << std::endl;
}

int LifeSpecs::returnLifeValue() const { return Life; }

int LifeSpecs::returnShieldValue() const { return Shield; }

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

void Skills::skillsInfo() const {
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

void Inventory::ListItems() const {
  for (std::string i : Items) {
    std::cout << i << " ";
  }
  std::cout << '\n';
}

Player::Player(std::string name) {
  Name = name;
  Life.init(100, 100);
  Skill.init(25, 10);
  Inv = Inventory();
}

void Player::returnPlayerInfo() const {
  std::cout << Name << '\n', Life.lifeInfo(), Skill.skillsInfo(),
      Inv.ListItems();
}

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
    player->Life.changeShieldValue(randomNumber);
  }

  if (player->Life.returnLifeValue() <= 0) {
    return true;
  }
  return false;
}
