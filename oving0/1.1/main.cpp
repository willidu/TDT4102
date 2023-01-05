//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	// Show a nice message in the Terminal window
	cout << "Hello, World!" << endl;

	// This lets the operating system (Windows, Mac, Linux, etc.) know that the program
	// did not encounter any errors
	return 0;
}

//------------------------------------------------------------------------------
