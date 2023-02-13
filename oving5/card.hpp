#ifndef _CARD_H_
#define _CARD_H_

#include <string>
#include <map>

// Task 1
enum class Suit {
    clubs, diamonds, hearts, spades
};

enum class Rank {
    ace = 1, two, three, four, five, six, seven,
    eight, nine, ten, jack, queen, king,
};

std::string suitToString(Suit suit);
std::string rankToString(Rank rank);

// Task 2
class Card {
private:
    Suit s;
    Rank r;

public:
    Card(Suit s, Rank r);
    std::string getSuit() const;
    std::string getRank() const;
    std::string toString() const;
    int getRankInt() const;  // Task 4
};

#endif
