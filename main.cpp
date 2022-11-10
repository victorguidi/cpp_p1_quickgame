#include "entities/match.h"
#include "entities/person.h"
#include <iostream>
#include <iterator>
#include <stdlib.h>

int main() {

  Player player1("Bob");

  Player player2("Alice");

  Match match;

  player1.addItems("sword");
  player1.addItems("shield");
  // player1.returnPlayerInfo();

  player2.addItems("sword");
  player2.addItems("shield");
  // player2.returnPlayerInfo();

  std::cout << "The Players in the game are \n" << std::endl;

  bool pl = false;
  while (!pl) {

    std::srand(time(0));
    int value = rand() % 10;

    pl = player1.attack(value, &player2);

    value = rand() % 10;
    pl = player2.attack(value, &player1);
  }

  match.P.addPlayers(&player1);
  match.P.addPlayers(&player2);

  match.P.listPlayers();

  if (player1.Life.returnLifeValue() > player2.Life.returnLifeValue()) {
    std::cout << "player 1 won" << std::endl;
  } else if (player2.Life.returnLifeValue() > player1.Life.returnLifeValue()) {
    std::cout << "player 2 won" << std::endl;
  } else {
    std::cout << "Its a tie" << std::endl;
  }

  return 0;
}
