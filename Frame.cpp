#include <stdexcept>
#include "Frame.h"

Frame::Frame(bool isTenth) : tenthFrame(isTenth) {}

void Frame::addRoll(int pins) {
    if (pins < 0 || pins > 10)
        throw std::invalid_argument("Invalid number of pins");

    if (isComplete())
        throw std::logic_error("Frame is already complete");

    rolls.push_back(pins);

    // Special handling for 10th frame
    if (tenthFrame && rolls.size() == 2 && (rolls[0] + rolls[1] < 10)) {
        rolls.resize(2); // no third ball
    }
    if (tenthFrame && rolls.size() == 3) {
        rolls.resize(3);
    }
}

int Frame::getScore() const {
    int total = 0;
    for (int r : rolls) total += r;
    return total;
}

bool Frame::isStrike() const {
    return rolls.size() > 0 && rolls[0] == 10;
}

bool Frame::isSpare() const {
    return rolls.size() >= 2 && rolls[0] + rolls[1] == 10 && !isStrike();
}

bool Frame::isComplete() const {
    if (!tenthFrame) {
        return isStrike() || rolls.size() == 2;
    } else {
        if (rolls.size() < 2) return false;
        if (rolls.size() == 2 && (rolls[0] + rolls[1] < 10)) return true;
        return rolls.size() == 3;
    }
}

std::vector<int> Frame::getRolls() const {
    return rolls;
}

bool Frame::isTenthFrame() const {
    return tenthFrame;
}
