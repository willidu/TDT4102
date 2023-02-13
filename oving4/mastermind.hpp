#ifndef _MASTERMIND_H
#define _MASTERMIND_H

#include <string>

// Task 4
void playMastermind();
int checkCharAndPos(std::string guess, std::string correct);
int checkChar(std::string guess, std::string correct);

#endif