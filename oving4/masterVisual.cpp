#include "masterVisual.h"
#include "std_lib_facilities.h"
#include "utils.hpp"
#include "mastermind.hpp"

// Task 5
void playMastermindVisual() {
	constexpr int size {4};
    constexpr int letters {6};
    const char upperBound = 'A' + (letters - 1);
    const unsigned totalGuessCount {5};

    std::string code = randomizeString(size, 'A', upperBound);

    cout << "Game starting." << endl;
    // cout << "Code: " << code << endl;

    MastermindWindow mwin {800, 20, winW, winH, size, "Mastermind"};
	mwin.setCodeHidden(false);

    unsigned guessCount {1};
    bool wonGame {false};

    while (guessCount < totalGuessCount) {
        cout << "Attempt " << guessCount << "/" << totalGuessCount << endl;

        std::string guess = mwin.getInput(size, 'A', upperBound);
        cout << "Guess: " << guess << endl;

		addGuess(mwin, guess, 'A');

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

std::map<int, Color> colorConverter{
    {1, Color::red},
    {2, Color::green},
    {3, Color::yellow},
    {4, Color::blue},
    {5, Color::blue_violet},
    {6, Color::dark_cyan}
};

void addGuess(MastermindWindow &mwin, const std::string code, const char startLetter)
{
	Guess g {code, startLetter};
	mwin.guesses.push_back(g);
}

void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter)
{
	// definer addFeedback
}

void MastermindWindow::drawCodeHider()
{
	if(code_hidden) {
		draw_rectangle(Point{padX, 3 * padY}, winW - size * padX, padY, Color::black);
	}
}

MastermindWindow::MastermindWindow(int x, int y, int w, int h, int size, const std::string &title) 
: AnimationWindow(x, y, w, h, title),
guessBtn{{upperLeftCornerBtn.x, upperLeftCornerBtn.y}, btnW, btnH, "Add"},
guess{{upperLeftCornerInBox.x, upperLeftCornerInBox.y}, inBoxW, inBoxH, ""},
size(size)
{
	add(guess);
	add(guessBtn);
	guessBtn.setCallback(std::bind(&MastermindWindow::newGuess, this));
};

string MastermindWindow::wait_for_guess()
{
	while (!button_pressed && !should_close())
	{
		int xPos = 20;
		for(int guessIndex = 0; guessIndex < static_cast<int>(guesses.size()); guessIndex++) {
			//Implementer gjett slik at det vises fargede rektangler i grafikkvinduet
			{
				draw_rectangle(Point{xPos, 100}, padX, padY, colorConverter.at(guessIndex));
				xPos += 20;
                // Tegn rektangler ved bruk av draw_rectangle(). Bruk: colorConverter.at() for å få riktig farge

			}
		}

		for(int feedbackIndex = 0; feedbackIndex < static_cast<int>(feedbacks.size()); feedbackIndex++) {
			// Implementer feedback

			for (int i = 0; i < size; i++)
			{
				// Tegn sirkler ved hjelp av draw_circle
				
			}
		}

		// Burde tegnes sist siden den skal ligge på toppen
		drawCodeHider();

		next_frame();
	}
	button_pressed = false;

	string newGuess = guess.getText();
	guess.setText("");
	
	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput && !should_close())
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input.at(i);
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again" << endl;
		}
	}
	return guess;
}

void MastermindWindow::setCodeHidden(bool hidden) {
	code_hidden = hidden;
}
