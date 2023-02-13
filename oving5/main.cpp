#include "card.hpp"
#include "carddeck.hpp"
#include "blackjack.hpp"

#include <iostream>
#include <vector>

void testSuitAndRank() {
    Rank r = Rank::king;
    Suit s = Suit::hearts;
    std::string rank = rankToString(r);
    std::string suit = suitToString(s);
    std::cout << "Rank: " << rank << " Suit: " << suit << std::endl;
}

void testCardClass() {
    Card c {Suit::spades, Rank::ace};
    std::cout << c.toString() << std::endl;
}

void testCardDeckClass() {
    CardDeck deck;
    deck.print();
    std::cout << "Suffling now" << std::endl;
    deck.shuffle();
    deck.print();
    Card c {deck.drawCard()};
    std::cout << "Popped card: " << c.toString() << std::endl;
}

void testCardValue() {
    std::vector<Card> cardVec1 {Card{Suit::clubs, Rank::ace}, Card{Suit::clubs, Rank::king}};
    Hand h1 {cardVec1};
    std::cout << h1 << "score " << h1.score() << std::endl;

    std::vector<Card> cardVec2 {Card{Suit::clubs, Rank::ace}, Card{Suit::spades, Rank::ace}};
    Hand h2 {cardVec2};
    std::cout << h2 << "score " << h2.score() << std::endl;
}

void testBlackjack() {
    Blackjack b {};
    b.playGame();
}


int main() {
    unsigned in {0};
    std::cout << "1: Test Suit and Rank enums" << std::endl;
    std::cout << "2: Test Card class" << std::endl;
    std::cout << "3: Test Card deck class" << std::endl;
    std::cout << "4: Test card value Blackjack" << std::endl;
    std::cout << "5: Play Blackjack" << std::endl;

    std::cin >> in;

    switch (in) {
    case 1:
        testSuitAndRank();
        break;

    case 2:
        testCardClass();
        break;

    case 3:
        testCardDeckClass();
        break;

    case 4:
        testCardValue();
        break;

    case 5:
        testBlackjack();
        break;
    
    default:
        break;
    }

    return 0;
}
