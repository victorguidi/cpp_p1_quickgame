#pragma once

#include <string>
#include <vector>

struct LifeSpecs {
private:
  int Life;
  int Shield;

public:
  void constructor(int lifeValue, int shieldValue);

  void lifeInfo();

  int returnLifeValue();

  int returnShieldValue();

  void changeLifeValue(int valueToIncrease);

  void changeShieldValue(int valueToIncrease);
};

struct Skills {
private:
  int Power;
  int Stamina;

public:
  void constructor(int powerValue, int staminaValue);

  void skillsInfo();

  void IncreasePower(int valueToIncrease);

  void IncreaseStamina(int valueToIncrease);
};

struct Inventory {
  std::vector<std::string> Items;

  void addItems(std::string item);

  void ListItems();
};

class Player {
private:
  std::string Name;

public:
  LifeSpecs Life;
  Skills Skill;
  Inventory Inv;

  void constructor(std::string name);

  void returnPlayerInfo();

  void changeLifeValue(int value);
  void changeShieldValue(int value);

  void changePowerValue(int value);
  void changeStaminaValue(int value);

  void addItems(std::string item);
  void listItems();

  bool attack(int value, Player *player);
};
