#pragma once

#include "person.hpp"

#include <iostream>
#include <vector>

enum class Campus
{
    Trondheim = 0, Alesund, Gjovik
};

std::string to_string(const Campus& c);
std::ostream& operator<< (std::ostream& os, const Campus& c);

class Meeting
{
private:
    unsigned m_day;
    unsigned m_startTime;
    unsigned m_endTime;
    Campus m_loc;
    std::string m_subject;
    const std::shared_ptr<Person> m_leader;
    std::vector<std::shared_ptr<Person>> m_participants;

public:
    Meeting(
        unsigned day, unsigned startTime, unsigned endTime,
        Campus location, std::string subject, std::shared_ptr<Person> leader
    );
    void addParticipant(std::shared_ptr<Person> p);
    std::vector<std::shared_ptr<Person>> findPotentialCoDriving(const Meeting& otherMeeting) const;

    unsigned getDay() const;
    unsigned getStartTime() const;
    unsigned getEndTime() const;
    Campus getLocation() const;
    std::string getSubject() const;
    std::shared_ptr<Person> getLeader() const;
    std::vector<std::string> getParticipantList() const;
};

std::ostream& operator<< (std::ostream& os, const Meeting& m);
