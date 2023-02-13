#include "carddeck.hpp"
#include "card.hpp"
#include "utils.hpp"

#include <iostream>

typedef unsigned long long ull;
constexpr ull numberOfShuffels {100000};

// Task 3
CardDeck::CardDeck() {
    for (unsigned s = static_cast<unsigned>(Suit::clubs); s < 4; s++) {
        for (unsigned r = static_cast<unsigned>(Rank::ace); r <= 13; r++) {
            Card c{static_cast<Suit>(s), static_cast<Rank>(r)};
            cards.push_back(c);
        }
    }
}

void CardDeck::print() {
    for (Card c : cards) {
        std::cout << c.toString() << '\n';
    }
}

void CardDeck::swap(unsigned a, unsigned b) {
    Card temp = cards.at(a);
    cards.at(a) = cards.at(b);
    cards.at(b) = temp;
}

void CardDeck::shuffle() {
    for (ull i = 0; i < numberOfShuffels; i++) {
        swap(getRandomDeckIndex(), getRandomDeckIndex());
    }
}

Card CardDeck::drawCard() {
    Card c {cards.back()};
    cards.pop_back();
    return c;
}

// Task 4
unsigned CardDeck::getSize() const {
    return cards.size();
}
