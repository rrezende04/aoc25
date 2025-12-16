#include "solver.h"

Solver::Solver(const std::string& filePath, bool click)
: _input(filePath)
, _click(click)
{}

void Solver::solve() {
    std::cout << solutionLoop() << std::endl;
}

int Solver::solutionLoop() {
    std::string textBuf;

    while(getline (_input, textBuf)) {
        char direction = textBuf[0];
        int turnValue = std::stoi(textBuf.substr(1));

        turnDial(direction, turnValue);

        if (_dialValue == 0)
            _result++;
    }

    return _result;
}

void Solver::turnDial(char direction, int turnValue) {
    bool left = (direction == 'L');

    if (_click) clickLogic(left, turnValue);

    turnValue *= left ? -1 : 1;

    _dialValue += turnValue;
    _dialValue = (_dialValue % DIAL_RANGE + DIAL_RANGE) % DIAL_RANGE;
}

void Solver::clickLogic(bool left, int turnValue) {
    _result += turnValue / DIAL_RANGE;

    int zeroDistance = left ? _dialValue : DIAL_RANGE - _dialValue;

    if (turnValue % DIAL_RANGE > zeroDistance && _dialValue != 0) _result++;
}