#ifndef _COURSE_CATALOG_H_
#define _COURSE_CATALOG_H_

#include <map>
#include <string>
#include <iostream>

class CourseCatalog {
private:
    std::map<std::string, std::string> courseMap;

public:
    CourseCatalog() {};
    void addCourse(std::string code, std::string name);
    void removeCourse(std::string code);
    std::string getCourse(std::string code) const;

    friend std::ostream& operator<< (std::ostream& os, const CourseCatalog& c);

    void toFile(std::string path) const;
    void fromFile(std::string path);
};

#endif
