#pragma once

#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include "AnimationWindow.h"
#include "Color.h"
#include "person.hpp"

#include <iostream>
#include <vector>

class MeetingWindow : public TDT4102::AnimationWindow
{
private:
    static constexpr int pad {40};
    static constexpr int btnW {100};
    static constexpr int btnH {60};
    static constexpr int fieldW {240};
    static constexpr int fieldH {60};
    static constexpr int fieldPad {3*pad};

    TDT4102::TextInput nameField;
    TDT4102::TextInput emailField;
    TDT4102::Button quitBtn;
    TDT4102::Button addPersonBtn;

    std::vector<std::shared_ptr<Person>> m_people;

public:
    MeetingWindow(int x, int y, int w, int h, std::string title);
    void cb_quit();
    void newPerson();

    friend std::ostream& operator<< (std::ostream& os, const MeetingWindow& mwin);
};
