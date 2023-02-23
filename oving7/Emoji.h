#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji
{
public:
    virtual void draw(AnimationWindow&) = 0;
    virtual ~Emoji(){}; //destruktør
};

class Face : public Emoji
{
protected:
    Point c;
    int r;

public:
    void draw(AnimationWindow& win) override;  // det står i 2a at den skal være pure virtual men i 2c at den skal være noe annet
    Face(Point c, int r) : c{c}, r{r} { }
};

class EmptyFace : public Face
{
protected:
    int eye_r;
    Face* face;

public:
    void draw(AnimationWindow& win) override;
    EmptyFace(Point c, int r, int eyeRadius) : Face{c, r} {
        face = new Face{c, r};
        eye_r = eyeRadius;
    } 
};

class SmilingFace : public EmptyFace
{
public:
    void draw(AnimationWindow& win) override;
    SmilingFace(Point c, int r, int eyeRadius) : EmptyFace{c, r, eyeRadius} { }
};

class SadFace : public EmptyFace
{
public:
    void draw(AnimationWindow& win) override;
    SadFace(Point c, int r, int eyeRadius) : EmptyFace{c, r, eyeRadius} { }
};
