#include "meetingwindow.hpp"

MeetingWindow::MeetingWindow(int x, int y, int w, int h, std::string title)
 : TDT4102::AnimationWindow{x, y, w, h, title},
   nameField{{fieldPad, pad}, fieldW, fieldH, "Ola Nordmann"},
   emailField{{fieldPad, pad+fieldH}, fieldW, fieldH, "ola.nordmann@gmail.com"},
   quitBtn{{fieldPad, 4*pad}, btnW, btnH, "Quit"},
   addPersonBtn{{fieldPad+btnW+pad, 4*pad}, btnW, btnH, "Add"}
{
    add(quitBtn);
    quitBtn.setButtonColor(TDT4102::Color::crimson);
    quitBtn.setButtonColorHover(TDT4102::Color::dark_red);
    quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit, this));

    add(nameField);
    add(emailField);

    add(addPersonBtn);
    addPersonBtn.setButtonColor(TDT4102::Color::medium_spring_green);
    addPersonBtn.setButtonColorHover(TDT4102::Color::green);
    addPersonBtn.setCallback(std::bind(&MeetingWindow::newPerson, this));
}

void MeetingWindow::cb_quit()
{
    close();
}

void MeetingWindow::newPerson()
{
    std::string name = nameField.getText();
    std::string email = emailField.getText();

    if (name.size() && email.size())
    {
        m_people.emplace_back(new Person{name, email});
    }

    nameField.setText("");
    emailField.setText("");
}

std::ostream& operator<< (std::ostream& os, const MeetingWindow& mwin)
{
    os << mwin.m_people.size() << " added people: ";
    for (const auto& p : mwin.m_people)
    {
        os << p->getName() << '\t';
    }
    return os;
}

