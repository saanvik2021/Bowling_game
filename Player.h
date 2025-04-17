#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Frame.h"

class Player {
public:
    Player(const std::string& name);

    void roll(int pins);
    int getTotalScore() const;
    std::string getName() const;
    std::vector<Frame> getFrames() const;

private:
    std::string name;
    std::vector<Frame> frames;
};

#endif
