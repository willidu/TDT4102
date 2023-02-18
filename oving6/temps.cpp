#include "temps.hpp"

#include <experimental/filesystem>
#include <fstream>

std::istream& operator>> (std::istream& is, Temps& t) {
    is >> t.max;
    is >> t.min;
    return is;
}

std::ostream& operator<< (std::ostream& os, Temps& t) {
    os << t.max << ", " << t.min;
    return os;
}

std::vector<Temps> readTemps(std::string path) {
    std::experimental::filesystem::path tempFile {path};
    std::ifstream temp_file {tempFile};
    std::vector<Temps> temps;

    Temps t;

    while (temp_file >> t) {
        temps.push_back(t);  // Copy {max, min} to vector
    }

    return temps;
}

// Helper function to print temperature vector
std::ostream& operator<< (std::ostream& os, std::vector<Temps> temps) {
    for (auto& t : temps) {
        os << t << '\n';
    }
    return os;
}

void tempStats(const std::vector<Temps>& temps) {
    double maxTemp {temps.at(0).max};
    int maxTempIndex {0};
    double minTemp {temps.at(0).min};
    int minTempIndex {0};

    for (int i = 0; i < temps.size(); i++) {
        if (temps.at(i).max > maxTemp) {
            maxTemp = temps.at(i).max;
            maxTempIndex = i;
        }
        if (temps.at(i).min < minTemp) {
            minTemp = temps.at(i).min;
            minTempIndex = i;
        }
    }

    std::cout << "Max temperature at day " << maxTempIndex + 1
              << " with temperature " << maxTemp << '\n'
              << "Minimum temperature at day " << minTempIndex + 1
              << " with temperature " << minTemp << std::endl;
}
