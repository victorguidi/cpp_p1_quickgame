#include "entities/match.h"
#include "entities/person.h"
#include <iostream>
#include <iterator>
#include <stdlib.h>

#define LOG(x) std::cout << x << std::endl

int main() {

  Match match;

  Player player1("Bob");
  Player player2("Alice");

  match.addPlayers(player1);
  match.addPlayers(player2);

  player1.Inv.addItems("sword");
  player1.Inv.addItems("shield");

  player2.Inv.addItems("sword");
  player2.Inv.addItems("shield");

  std::cout << "The Players in the game are \n" << std::endl;

  bool pl = false;
  while (!pl) {

    std::srand(time(0));
    int value = rand() % 10;

    pl = player1.attack(value, &player2);

    value = rand() % 10;
    pl = player2.attack(value, &player1);
  }

  match.listPlayers();

  if (player1.Life.returnLifeValue() > player2.Life.returnLifeValue()) {
    std::cout << "player 1 won" << std::endl;
  } else if (player2.Life.returnLifeValue() > player1.Life.returnLifeValue()) {
    std::cout << "player 2 won" << std::endl;
  } else {
    std::cout << "Its a tie" << std::endl;
  }

  return 0;
}
