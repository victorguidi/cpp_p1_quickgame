#include "match.h"
#include "person.h"
#include <iostream>
#include <vector>

void Players::listPlayers() {
  for (Player player : Ps) {
    player.returnPlayerInfo();
  }
}

void Players::addPlayers(Player *player) { Ps.push_back(*player); }

Match::Match() {
  ID = 90;
  Players();
}
