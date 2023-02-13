#include "card.hpp"

// Task 1
// Gets a linker error if the maps are placed in card.hpp
std::map<Suit, std::string> suitMap {
    {Suit::clubs, "Clubs"},
    {Suit::diamonds, "Diamonds"},
    {Suit::hearts, "Hearts"},
    {Suit::spades, "Spades"}
};

std::map<Rank, std::string> rankMap {
    {Rank::ace, "Ace"},
    {Rank::two, "Two"},
    {Rank::three, "Three"},
    {Rank::four, "Four"},
    {Rank::five, "Five"},
    {Rank::six, "Six"},
    {Rank::seven, "Seven"},
    {Rank::eight, "Eight"},
    {Rank::nine, "Nine"},
    {Rank::ten, "Ten"},
    {Rank::jack, "Jack"},
    {Rank::queen, "Queen"},
    {Rank::king, "King"}
};

std::string suitToString(Suit suit) {
    return suitMap.at(suit);
}

std::string rankToString(Rank rank) {
    return rankMap.at(rank);
}

// Task 2
Card::Card(Suit s, Rank r): s{s}, r{r} {}

std::string Card::getSuit() const {
    return suitToString(s);
}

std::string Card::getRank() const {
    return rankToString(r);
}

std::string Card::toString() const {
    return getRank() + " of " + getSuit();
}

// Task 4
int Card::getRankInt() const {
    return static_cast<int>(r);
}
