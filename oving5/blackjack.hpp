#ifndef _BLACKJACK_H_
#define _BLACKJACK_H_

#include "carddeck.hpp"

#include <vector>

struct Hand{
    std::vector<Card> cards;

    int score() const;
};

std::ostream& operator<< (std::ostream& stream, const Hand& h);

// Task 4
class Blackjack {
private:
    CardDeck deck;
    Hand playerHand;
    Hand dealerHand;

public:
    Blackjack();
    bool askPlayerDrawCard() const;
    void drawPlayerCard();
    void drawDealerCard();
    void playGame();
};

#endif
