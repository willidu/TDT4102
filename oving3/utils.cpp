#include <random>
#include "utils.hpp"

int randomWithLimits(int lowerLim, int upperLim) {
    std::random_device rd;
    std::default_random_engine generator (rd());
    std::uniform_int_distribution distribution (lowerLim, upperLim);
    return distribution(generator);
}
