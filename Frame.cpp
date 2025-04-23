#include "Frame.h"

Frame::Frame(bool tenth) : roll1(0), roll2(0), bonus(0), isTenth(tenth) {}

void Frame::setRolls(int r1, int r2) {
    if (r1 < 0 || r2 < 0 || r1 > 10 || r2 > 10) {
        throw std::invalid_argument("Invalid roll values.");
    }
    if (r1 + r2 > 10 && !isTenth && r1 != 10) {
        throw std::invalid_argument("Frame total exceeds 10.");
    }
    roll1 = r1;
    roll2 = r2;
}

void Frame::setBonus(int b) {
    if (b < 0 || b > 10) throw std::invalid_argument("Invalid bonus value.");
    bonus = b;
}

int Frame::getRoll1() const { return roll1; }
int Frame::getRoll2() const { return roll2; }
int Frame::getBonus() const { return bonus; }

int Frame::getFrameScore() const {
    return roll1 + roll2 + bonus;
}

bool Frame::isStrike() const {
    return roll1 == 10;
}

bool Frame::isSpare() const {
    return roll1 < 10 && (roll1 + roll2 == 10);
}
