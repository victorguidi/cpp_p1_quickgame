#include "person.h"
#include <iostream>
#include <string>
#include <vector>

struct Players {
  std::vector<Player> Ps;

  void addPlayers(Player *player);

  void listPlayers();
};

class Match {
public:
  int ID;
  Players P;

  Match();

  void addPlayers(Player *player);
};
