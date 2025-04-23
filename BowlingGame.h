#ifndef BOWLINGGAME_H
#define BOWLINGGAME_H

#include "Player.h"
#include <vector>
#include <string>

class BowlingGame {
private:
    std::vector<Player> players;

public:
    void addPlayer(const Player& player);
    void inputPlayerFrames(Player& player);
    void scoreGame() const;
};

#endif
