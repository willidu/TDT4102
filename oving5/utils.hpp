#ifndef _CARD_DECK_UTILS_H_
#define _CARD_DECK_UTILS_H_

#include "card.hpp"

#include <vector>

// Task 3
unsigned getRandomDeckIndex();

// Task 4
bool isAce(const Card& c);
int getCardValue(const Card& c);
bool realBlackjack(const std::vector<Card>& cards);

#endif
