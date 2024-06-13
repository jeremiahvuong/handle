#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <map>
#include <random>
#include <iostream>

enum Card { blackSpades, blackSuits, redHearts, redDiamonds };
// spades (♠) | clubs (♣)
// hearts (♥) | diamonds (♦)

std::map <Card, std::string> cardSymbols = {
  {blackSpades, "♠"},
  {blackSuits, "♣"},
  {redHearts, "♥"},
  {redDiamonds, "♦"}
};

class Player {
public:
  std::string name;

  Player(std::string name) {
    this->name = name;
  }

private:
  int spadeCount;
  int suitCount;
  int heartCount;
  int diamondCount;
};

class Game {
public:
  Card goalSuit;
  Card commonSuit; // 12 card same-color suit

  int totalCards = 40;
  int totalSpades;
  int totalSuits;
  int totalHearts;
  int totalDiamonds;

  Game() {
    Player player1 = Player("John");
    Player player2 = Player("Jane");
    Player player3 = Player("Jack");
    Player player4 = Player("Jill");

    generateSuits();
  }

private:
  void generateSuits() {
    std::vector<Card> suits = { blackSpades, blackSuits, redHearts, redDiamonds };
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(suits.begin(), suits.end(), g);
    goalSuit = suits[0];

    std::map<Card, Card> suitPairs = {
      {blackSpades, blackSuits},
      {blackSuits, blackSpades},
      {redHearts, redDiamonds},
      {redDiamonds, redHearts}
    };
    commonSuit = suitPairs[goalSuit];

    // assign the common suit total to 12
    switch (commonSuit) {
    case blackSpades:
      totalSpades = 12;
      break;
    case blackSuits:
      totalSuits = 12;
      break;
    case redHearts:
      totalHearts = 12;
      break;
    case redDiamonds:
      totalDiamonds = 12;
      break;
    }

    std::vector<Card> remainingSuits;
    if (commonSuit != blackSpades) remainingSuits.push_back(blackSpades);
    if (commonSuit != blackSuits) remainingSuits.push_back(blackSuits);
    if (commonSuit != redHearts) remainingSuits.push_back(redHearts);
    if (commonSuit != redDiamonds) remainingSuits.push_back(redDiamonds);

    // Shuffle remaining suits
    std::shuffle(remainingSuits.begin(), remainingSuits.end(), g);

    // Assign 8, 10, 10 to the shuffled suits
    int counts[] = { 8, 10, 10 };
    for (int i = 0; i < remainingSuits.size(); ++i) {
      switch (remainingSuits[i]) {
      case blackSpades:
        totalSpades = counts[i];
        break;
      case blackSuits:
        totalSuits = counts[i];
        break;
      case redHearts:
        totalHearts = counts[i];
        break;
      case redDiamonds:
        totalDiamonds = counts[i];
        break;
      }
    }
  };
};

int main() {
  Game game;
  std::cout << "Goal suit: " << cardSymbols[game.goalSuit] << std::endl;
  std::cout << "Common suit: " << cardSymbols[game.commonSuit] << std::endl;

  std::cout << "♠: " << game.totalSpades << std::endl;
  std::cout << "♣: " << game.totalSuits << std::endl;
  std::cout << "♥: " << game.totalHearts << std::endl;
  std::cout << "♦: " << game.totalDiamonds << std::endl;
  return 0;
}