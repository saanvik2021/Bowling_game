#ifndef PLAYER_H
#define PLAYER_H

#include "Frame.h"
#include <string>
#include <vector>

class Player {
private:
    std::string name;
    std::vector<Frame> frames;

public:
    Player(const std::string& playerName);
    
    void addFrame(const Frame& frame);
    const std::string& getName() const;
    const std::vector<Frame>& getFrames() const;
    int calculateScore() const;
};

#endif
