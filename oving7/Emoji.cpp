#include "Emoji.h"

void Face::draw(AnimationWindow& win) {
    win.draw_circle(c, r, Color::yellow);
}

void EmptyFace::draw(AnimationWindow& win) {
    this->face->draw(win);  // Drawing yellow circle
    Point leftEyeCenter {c.x - r/4, c.y - r/4};
    Point rightEyeCenter {c.x + r/4, c.y - r/4};

    win.draw_circle(leftEyeCenter, eye_r, Color::black);
    win.draw_circle(leftEyeCenter, eye_r/2, Color::white);

    win.draw_circle(rightEyeCenter, eye_r, Color::black);
    win.draw_circle(rightEyeCenter, eye_r/2, Color::white);
}

void SmilingFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);

    win.draw_arc(c, r-4*eye_r, r/2, 185, 360, Color::black);
}

void SadFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);

    win.draw_arc(Point{c.x, c.y+r/2}, r-4*eye_r, r/2, 5, 175, Color::black);
}
