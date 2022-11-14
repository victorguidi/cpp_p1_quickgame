#pragma once

#include <string>
#include <vector>

struct LifeSpecs {
private:
  int Life;
  int Shield;

public:
  void init(int lifeValue, int shieldValue);

  void lifeInfo() const;

  int returnLifeValue() const;

  int returnShieldValue() const;

  void changeLifeValue(int valueToIncrease);

  void changeShieldValue(int valueToIncrease);
};

struct Skills {
private:
  int Power;
  int Stamina;

public:
  void init(int powerValue, int staminaValue);

  void skillsInfo() const;

  void IncreasePower(int valueToIncrease);

  void IncreaseStamina(int valueToIncrease);
};

struct Inventory {
  std::vector<std::string> Items;

  void addItems(std::string item);

  void ListItems() const;
};

class Player {
private:
  std::string Name;

public:
  LifeSpecs Life;
  Skills Skill;
  Inventory Inv;

  Player(std::string name);

  void returnPlayerInfo() const;

  bool attack(int value, Player *player);
};
