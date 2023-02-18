#include "file.hpp"

#include <iostream>
#include <experimental/filesystem>
#include <fstream>
#include <vector>

void clToFile(std::string outPath) {
    std::experimental::filesystem::path fileName {outPath};
    std::ofstream ofs {fileName, std::ios::out};

    std::cout << "Input a word to the file " << outPath << std::endl;
    std::cout << "[q] to quit" << std::endl;

    while(1) {
        std::string in;

        std::cin >> in;

        if (tolower(in.at(0)) == 'q') {
            ofs << '\n';
            break;
        } else {
            ofs << in << "\n";
        }
    }
}

void addLineNumbersToFile(std::string outPath) {
    std::experimental::filesystem::path fileName {outPath};
    std::ifstream ifs {fileName, std::ios::in};

    std::vector<std::string> strs;

    if (!ifs) 
    {
        std::cout << "Input file not found." << std::endl;
        exit(1);
    } 
    else 
    {
        int num {1};
        for (std::string line; std::getline(ifs, line);) {
            std::string newLine {std::to_string(num) + " " + line + "\n"};
            strs.push_back(newLine);
            num++;
        }
    }

    std::ofstream ofs {fileName, std::ios::out};

    if (!ofs)
    {
        std::cout << "Cannot create output file " << fileName << std::endl; 
        exit(1);
    } 
    else 
    {
        for (const auto& line : strs) {
            ofs << line;
        }
    }
}

void analyzeFile(std::string outpath) {
    std::experimental::filesystem::path fileName {outpath};
    std::ifstream ifs {fileName, std::ios::in};

    // Characters 'a' to 'z' will be in the first vector, 'a' in first position.

    constexpr int lowerLim {static_cast<int>('a')};
    std::vector<int> characters (26, 0);

    if (!ifs)
    {
        std::cout << "Cannot read file " << fileName << std::endl;
        exit(1);
    }
    else
    {
        std::string word;
        while (ifs >> word) {
            for (const char& c : word) {
                if (isalpha(c)) {
                    characters.at(static_cast<int>(tolower(c)) - lowerLim)++;
                }
            }
        }
    }

    for (int i = 0; i < characters.size(); i++) {
        std::cout << static_cast<char>(lowerLim + i) << ": " << characters.at(i) << std::endl;
    }
}
