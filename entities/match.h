#include "person.h"
#include <iostream>
#include <string>
#include <vector>

class Match {
public:
  int ID;
  std::vector<Player *> P;

  Match();

  void addPlayers(Player &player);

  void listPlayers() const;
};
