#include "AnimationWindow.h"

using namespace TDT4102;

void pythagoras() {
    AnimationWindow win{100, 100, 1024, 1024, "Pythagoras"};

    // Trekant med punkt 1 nede venstre hjørne, tegnet med klokka
    Point point1{400, 400};
    Point point2{400, 200};
    Point point3{600, 400};

    win.draw_triangle(point1, point2, point3, Color::grey);

    // Firkant venstre katet (mot klokka)
    win.draw_quad(
        point1, point2, Point{200, 200}, Point{200, 400},
        Color::green_yellow
    );

    // Firkant nedre katet (med klokka)
    win.draw_quad(
        point1, point3, Point{600, 600}, Point{400, 600},
        Color::blue_violet
    );

    
    // Firkant hypotenus (mot klokka)
    win.draw_quad(
        point2, point3, Point{800, 200}, Point{600, 0},
        Color::orange_red
    );

    win.wait_for_close();
}