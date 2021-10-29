/*
 * Created on Fri Oct 29 2021
 *
 * Arthur Lang
 * utils.cpp
 */


#include "utils.hpp"

std::vector<std::string> splitOutput(const std::string &output) {
    std::stringstream stream(output);
    std::string segment;
    std::vector<std::string> result;
    while(std::getline(stream, segment, '\n')) {
        result.push_back(segment);
    }
    return (result);
}
