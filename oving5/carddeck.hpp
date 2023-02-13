#ifndef _CARD_DECK_H_
#define _CARD_DECK_H_

#include "card.hpp"

#include <vector>

// Task 3
class CardDeck {
private:
    std::vector<Card> cards;

public:
    CardDeck();
    void print();
    void swap(unsigned a, unsigned b);
    void shuffle();
    Card drawCard();
    unsigned getSize() const;  // Task 4
};

#endif
