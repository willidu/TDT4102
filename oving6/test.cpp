#include "test.hpp"
#include "coursecatalog.hpp"
#include "temps.hpp"

#include <experimental/filesystem>
#include <fstream>

void testCourseCatalog() {
    CourseCatalog c = CourseCatalog();
    c.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    c.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    c.addCourse("TMA4100", "Matematikk 1");

    std::cout << c << std::endl;

    c.removeCourse("TMA4100");

    std::cout << c << std::endl;
}

void testOverwriteCourse() {
    CourseCatalog c = CourseCatalog();
    c.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    c.addCourse("TDT4102", "C++");

    std::cout << c << std::endl;
}

void testCourseFile() {
    CourseCatalog c = CourseCatalog();
    c.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    c.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    c.addCourse("TMA4100", "Matematikk 1");

    c.toFile("courses.csv");
    std::cout << c << std::endl;

    CourseCatalog c1 = CourseCatalog();
    c1.fromFile("courses.csv");
    std::cout << c1 << std::endl;
}

void testTempStruct() {
    std::experimental::filesystem::path tempFile {"temperatures.txt"};
    std::ifstream temp_file {tempFile};
    Temps t;
    temp_file >> t;
    std::cout << t << std::endl;
}

void testReadTemps() {
    auto temps = readTemps("temperatures.txt");
    std::cout << temps << std::endl;
    tempStats(temps);
}
