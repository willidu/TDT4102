#include "car.hpp"
#include "person.hpp"
#include "meeting.hpp"
#include "meetingwindow.hpp"

void testPerson();
void testMeeting();
void MeetingGUI();

int main()
{
    int key {0};

    std::cout << "1. Test Person class" << std::endl;
    std::cout << "2. Test Meeting class" << std::endl;
    std::cout << "3. Meeting GUI" << std::endl;
    std::cin >> key;

    switch (key)
    {
    case 1:
        testPerson();
        break;

    case 2:
        testMeeting();
        break;

    case 3:
        MeetingGUI();
        break;
    
    default:
        break;
    }
    return 0;
}

void testPerson()
{
    Person albrekt {"Albrekt", "albrekt@gmail.com"};
    std::cout << albrekt << '\n'
              << "Any available seats: " 
              << (albrekt.hasAvailableSeats()? "Yes" : "No")
              << std::endl;

    Person notAlbrekt {"William", "William@gmail.com", std::make_unique<Car>(1)};
    std::cout << (notAlbrekt.hasAvailableSeats()? "Yes" : "No") << std::endl;
}

void testMeeting()
{
    std::shared_ptr<Person> p1 (new Person{"Albrekt", "albrekt@gmail.com"});
    std::shared_ptr<Person> p2 (new Person{"William", "William@gmail.com", std::make_unique<Car>(1)});
    Meeting m {1, 14, 15, Campus::Trondheim, "C++ Eksamen", p1};
    m.addParticipant(p2);
    std::cout << m << std::endl;

    Meeting m2 {1, 13, 16, Campus::Trondheim, "Kjøretime", p2};
    auto coDriving = m.findPotentialCoDriving(m2);
    for (const auto& p : coDriving)
        std::cout << p->getName() << ", ";
    std::cout << std::endl;
}

void MeetingGUI()
{
    MeetingWindow mwin{100, 100, 1024, 640, "Meeting GUI"};
    mwin.wait_for_close();
    std::cout << mwin << std::endl;
}
