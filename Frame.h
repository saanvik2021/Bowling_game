#ifndef FRAME_H
#define FRAME_H

#include <stdexcept>

class Frame {
private:
    int roll1;
    int roll2;
    int bonus; // For 10th frame only
    bool isTenth;

public:
    Frame(bool tenth = false);

    void setRolls(int r1, int r2);
    void setBonus(int b);
    int getRoll1() const;
    int getRoll2() const;
    int getBonus() const;
    int getFrameScore() const;
    bool isStrike() const;
    bool isSpare() const;
};

#endif
