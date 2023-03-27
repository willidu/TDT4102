#include "meeting.hpp"

#include <cmath>

std::string to_string(const Campus& c)
{
    switch (c)
    {
    case Campus::Trondheim:
        return "Trondheim";
        break;

    case Campus::Alesund:
        return "Ålesund";
        break;
    
    case Campus::Gjovik:
        return "Gjøvik";
        break;
    
    default:
        return "";
    }
}

std::ostream& operator<< (std::ostream& os, const Campus& c)
{
    os << to_string(c);
    return os;
}

Meeting::Meeting(
    unsigned day, unsigned startTime, unsigned endTime,
    Campus location, std::string subject, std::shared_ptr<Person> leader
) : m_day{day}, m_startTime{startTime}, m_endTime{endTime}, m_loc{location}, m_subject{subject}, m_leader{leader}
{
    m_participants.push_back(m_leader);
}

void Meeting::addParticipant(std::shared_ptr<Person> p)
{
    m_participants.push_back(p);
}

std::vector<std::shared_ptr<Person>> Meeting::findPotentialCoDriving(const Meeting& otherMeeting) const
{
    std::vector<std::shared_ptr<Person>> people;

    bool samePlace = to_string(this->getLocation()) == to_string(otherMeeting.getLocation());
    bool sameDay = this->getDay() == otherMeeting.getDay();

    int diffStartTime = this->getStartTime() - otherMeeting.getStartTime();
    int diffEndTime = this->getEndTime() - otherMeeting.getEndTime();

    bool correctStartTime = std::abs(diffStartTime) <= 1;
    bool correctEndTime = std::abs(diffEndTime) <= 1;

    bool canCoDrive = samePlace && sameDay && correctStartTime && correctEndTime;

    if (canCoDrive)
        for (const auto& p : otherMeeting.m_participants)
            if (p->hasAvailableSeats())
                people.push_back(p);

    return people;
}

unsigned Meeting::getDay() const
{
    return m_day;
}

unsigned Meeting::getStartTime() const
{
    return m_startTime;
}

unsigned Meeting::getEndTime() const
{
    return m_endTime;
}

Campus Meeting::getLocation() const
{
    return m_loc;
}

std::string Meeting::getSubject() const
{
    return m_subject;
}

std::shared_ptr<Person> Meeting::getLeader() const
{
    return m_leader;
}

std::vector<std::string> Meeting::getParticipantList() const
{
    std::vector<std::string> names;
    for (const auto& p_ptr : m_participants)
    {
        names.push_back(p_ptr->getName());
    }
    return names;
}

std::ostream& operator<< (std::ostream& os, const Meeting& m)
{
    os << "Day: " << m.getDay() << '\n'
       << "Starting time: " << m.getStartTime() << '\n'
       << "End time: " << m.getEndTime() << '\n'
       << "Location: " << to_string(m.getLocation()) << '\n'
       << "Subject: " << m.getSubject() << '\n'
       << "Leader information: " << '\n' 
       << *m.getLeader() << '\n'
       << "Participants: ";

    for (const auto& p : m.getParticipantList())
    {
        os << p << ", ";
    }
    
    return os;
}
