#include "coursecatalog.hpp"

#include <experimental/filesystem>
#include <fstream>

void CourseCatalog::addCourse(std::string code, std::string name) {
    courseMap[code] = name;  // Gjør at navnet endres hvis det allerede eksisterer.
    // courseMap.insert({code, name});
}

void CourseCatalog::removeCourse(std::string code) {
    courseMap.erase(code);
}

std::string CourseCatalog::getCourse(std::string code) const{
    return courseMap.at(code);
}

std::ostream& operator<< (std::ostream& os, const CourseCatalog& c) {
    for (const auto& course : c.courseMap) {
        os << course.first << "," << course.second << std::endl;
    }
    return os;
}

void CourseCatalog::toFile(std::string path) const{
    std::experimental::filesystem::path fileName {path};
    std::ofstream ofs {fileName, std::ios::out};

    if (!ofs) {
        std::cout << "Cannot open output file " << path << std::endl;
    }

    ofs << (*this);
}

void CourseCatalog::fromFile(std::string path) {
    std::experimental::filesystem::path fileName {path};
    std::ifstream ifs {fileName, std::ios::out};

    if (!ifs) {
        std::cout << "Cannot open input file " << path << std::endl;
    }

    for (std::string line; std::getline(ifs, line);) {
        std::string code;
        std::string name;

        int delimIndex = line.size();
        for (int i = 0; i < line.size(); i++) {
            if (line.at(i) == ',') {
                delimIndex = i;
            }

            if (i < delimIndex) {  // Code is before ','
                code += line.at(i);
            } else if (i > delimIndex) { // Name is after ','
                name += line.at(i);
            }
        }
        addCourse(code, name);
    }
}
