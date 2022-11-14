#include "match.h"
#include "person.h"
#include <iostream>
#include <vector>

Match::Match() {
  ID = 90;
  std::vector<Player *> P;
}

void Match::addPlayers(Player &player) { P.push_back(&player); }

void Match::listPlayers() const {
  for (int i = 0; i < P.size(); i++) {
    P[i]->returnPlayerInfo();
  }
}
