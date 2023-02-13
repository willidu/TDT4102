#include "mastermind.hpp"
#include "utils.hpp"

#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


// Task 4
void playMastermind() {
    constexpr int size {4};
    constexpr int letters {6};
    const char upperBound = 'A' + (letters - 1);
    const unsigned totalGuessCount {5};

    std::string code = randomizeString(size, 'A', upperBound);

    cout << "Game starting." << endl;
    // cout << "Code: " << code << endl;

    unsigned guessCount {0};
    bool wonGame {false};

    while (guessCount < totalGuessCount) {
        cout << "Attempt " << guessCount+1 << "/" << totalGuessCount << endl;

        std::string guess = readInputToString(size, 'A', upperBound);
        cout << "Guess: " << guess << endl;

        int correctWithPos = checkCharAndPos(guess, code);
        cout << "Count (w pos): " << correctWithPos << endl;

        int correctNoPos = checkChar(guess, code);
        cout << "Count (no pos): " << correctNoPos << endl;

        if (correctNoPos >= size && correctWithPos == size) {
            wonGame = true;
            break;
        } else {
            guessCount += 1;
        }
    }
    
    if (wonGame) {
        cout << "You won the game!" << endl;
    } else {
        cout << "Sorry, you lost the game... Better luck next time." << endl;
    }
}

int checkCharAndPos(std::string guess, std::string correct) {
    int res {0};
    
    for (unsigned i = 0; i < correct.size(); i++) {
        if (guess[i] == correct[i]) {
            res += 1;
        }
    }

    return res;
}

int checkChar(std::string guess, std::string correct) {
    int res {0};

    for (unsigned i = 0; i < correct.size(); i++) {
        res += countChar(guess, correct[i]);
    }

    return res;
}
