#include "blackjack.hpp"
#include "utils.hpp"

#include <iostream>

// Task 4
std::ostream& operator<< (std::ostream& stream, const Hand& h) {
    for (const auto c : h.cards) {
        stream << c.toString() << ", ";
    }
    return stream;
}

int Hand::score() const {
    int res {0};
    for (const auto c : cards) {
        res += getCardValue(c);

        // Sets value of Ace to 1 instead of 11.
        if (res > 21 && isAce(c)) { res -= 10; } 
    }
    return res;
}

Blackjack::Blackjack() {
    this->deck = CardDeck();
    deck.shuffle();

    std::vector<Card> playerVec;
    std::vector<Card> dealerVec;

    playerVec.push_back(deck.drawCard());
    dealerVec.push_back(deck.drawCard());
    playerVec.push_back(deck.drawCard());
    dealerVec.push_back(deck.drawCard());

    this->playerHand = Hand{playerVec};
    this->dealerHand = Hand{dealerVec};
}

bool Blackjack::askPlayerDrawCard() const {
    std::string in;
    std::cout << "Do you want to draw another card? [y/n]: ";
    std::cin >> in;
    return (static_cast<char>(std::tolower(in.at(0))) == 'y' ? true : false);
}

void Blackjack::drawPlayerCard() {
    playerHand.cards.push_back(deck.drawCard());
}

void Blackjack::drawDealerCard() {
    dealerHand.cards.push_back(deck.drawCard());
}

void Blackjack::playGame() {
    std::cout << "Game starting." << std::endl;

    std::cout << "Your hand: " << playerHand << "value " << playerHand.score() << std::endl;
    std::cout << "Dealer card 1: " << dealerHand.cards.at(0).toString() << std::endl;

    while (dealerHand.score() < 17) {
        drawDealerCard();
    }

    bool playerWon {false};

    while (1)
    {
        if (askPlayerDrawCard()) {
            drawPlayerCard();
        }

        std::cout << "Your hand: " << playerHand << "score " << playerHand.score() << std::endl;
        std::cout << '\n';


        if (playerHand.score() > 21) {
            break;
        } else if (realBlackjack(playerHand.cards)) {
            playerWon = true;
            break;
        } else if (playerHand.score() > dealerHand.score()) {
            playerWon = true;
            break;
        } else if (dealerHand.score() > 21) {
            playerWon = true;
            break;
        }
    }

    if (playerWon) {
        std::cout << "You won the game!" << std::endl;
    } else {
        std::cout << "You lost the game..." << std::endl;
    }

    std::cout << "Your hand: " << playerHand << "score " << playerHand.score() << std::endl;
    std::cout << "Dealers hand: " << dealerHand << "score " << dealerHand.score() << std::endl; 
}
