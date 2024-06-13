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

class Game {
public:
  Card goalSuit;
  Card commonSuit; // 12 card same-color suit

  Game() {
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
  }
};

int main() {
  Game game;
  std::cout << "Goal suit: " << cardSymbols[game.goalSuit] << std::endl;
  std::cout << "Common suit: " << cardSymbols[game.commonSuit] << std::endl;
  return 0;
}