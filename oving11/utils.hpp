#pragma once

#include "person.hpp"

#include <vector>
#include <string>
#include <set>
#include <list>

void replace(std::vector<std::string>& vec, std::string old, std::string replacement);
void replace(std::set<std::string>& set, std::string old, std::string replacement);

void printList(const std::list<Person>& l);
