#ifndef FRAME_H
#define FRAME_H

#include <vector>

class Frame {
public:
    Frame(bool isTenth = false);

    void addRoll(int pins);
    int getScore() const;
    bool isStrike() const;
    bool isSpare() const;
    bool isComplete() const;
    std::vector<int> getRolls() const;
    bool isTenthFrame() const;

private:
    std::vector<int> rolls;
    bool tenthFrame;
};

#endif