#include "file.hpp"
#include "test.hpp"

#include <iostream>

int main() {
    std::cout << "1: Write words to file" << std::endl;
    std::cout << "2: Add line numbers to file" << std::endl;
    std::cout << "3: Count words in file" << std::endl;
    std::cout << "4: Test Course Catalog class" << std::endl;
    std::cout << "5: Test course renaming" << std::endl;
    std::cout << "6: Test course file read/write" << std::endl;
    std::cout << "7: Test operator>> on Temps struct" << std::endl;
    std::cout << "8: Test readTemps func + stats" << std::endl;

    int in;
    std::cin >> in;

    switch (in)
    {
    case 1:
        clToFile("test.txt");
        break;

    case 2:
        addLineNumbersToFile("test.txt");
        break;

    case 3:
        analyzeFile("grunnlov.txt");
        break;
    
    case 4:
        testCourseCatalog();
        break;

    case 5:
        testOverwriteCourse();
        break;

    case 6:
        testCourseFile();
        break;

    case 7:
        testTempStruct();
        break;

    case 8:
        testReadTemps();
        break;
    
    default:
        break;
    }

    return 0;
}