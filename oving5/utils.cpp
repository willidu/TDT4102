#include "utils.hpp"
#include "card.hpp"

#include <random>

// Task 3
unsigned getRandomDeckIndex() {
    std::random_device rd;
    std::default_random_engine generator (rd());
    std::uniform_int_distribution distribution (0, 51);
    return distribution(generator);
}

// Task 4
bool isAce(const Card& c) {
    return c.getRank() == "Ace";
}

int getCardValue(const Card& c) {
    switch (c.getRankInt()) {
        case 1:  // Ace
            return 11;
        case 11:  // Jack
            return 10;
        case 12:  // Queen
            return 10;
        case 13:  // King
            return 10;
        default:  // All others
            return c.getRankInt();
    }
}

bool realBlackjack(const std::vector<Card>& cards) {
    bool gotAce {false};
    bool got10OrPicture {false};

    for (const auto c : cards) {
        if (isAce(c)) {
            gotAce = true;
        } else if (c.getRankInt() == 10) {
            got10OrPicture = true;
        }
    }

    return gotAce && got10OrPicture;
}
