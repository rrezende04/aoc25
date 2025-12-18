#include <iostream>
#include <sstream>
#include "solver.h"

Solver::Solver(const std::string& filePath) 
: _input(filePath)
{
    parseRanges();
}

void Solver::testPrint() {
    std::cout << "Printing parse results" << std::endl;

    for (const auto& pair: _ranges) {
        std::cout << "Lower bound : " << pair.first << std::endl
            << "Upper bound : " << pair.second << std::endl
            << std::endl;
    }
}


/**
 * Made with input format in mind
 * very error prone without this assumption
 */
void Solver::parseRanges() {
    std::string line;
    getline(_input, line);

    std::string numBuf;
    long long lower = 0;

    for (size_t i = 0; i < line.length(); i++) {
        char c = line[i];

        if (isdigit(c)) {
            numBuf += c;
        }
        else {
            if (c == '-') { lower = std::stoll(numBuf); }
            if (c == ',') { _ranges.push_back({lower, std::stoll(numBuf)}); }
            numBuf = "";
        }
    }

    // Don't forget the last range (no trailing comma)
    if (!numBuf.empty()) {
        long long upper = std::stoll(numBuf);
        _ranges.push_back({lower, upper});
    }
}