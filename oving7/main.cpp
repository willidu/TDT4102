#include "test.hpp"
#include "Emoji.h"
#include "AnimationWindow.h"

#include <iostream>

void emojiMain();

int main() {
    std::cout << "1: Test Animal class" << std::endl;
    std::cout << "2: Test emojies" << std::endl;

    int i {0};
    std::cin >> i;

    switch (i)
    {
    case 1:
        testAnimal();
        break;

    case 2:
        emojiMain();
        break;
    
    default:
        break;
    }
}

void emojiMain() {
    constexpr int xmax = 1000;
    constexpr int ymax = 600;
    constexpr int emojiRadius = 50;
    constexpr int eyeRadius {5};

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

    EmptyFace face {tl, emojiRadius, eyeRadius};
    face.draw(win);

    SmilingFace face2 {Point{tl.x+3*emojiRadius, tl.y}, emojiRadius, eyeRadius};
    face2.draw(win);

    SadFace face3 {Point{tl.x+6*emojiRadius, tl.y}, emojiRadius, eyeRadius};
    face3.draw(win);

	/* TODO:
	 *  - initialiser emojiene
	 *  - Tegn emojiene til vinduet
	 **/

	win.wait_for_close();
}
