#ifndef BOWLINGGAME_H
#define BOWLINGGAME_H

#include "Player.h"
#include <vector>

class BowlingGame {
public:
    BowlingGame();

    void addPlayer(const std::string& name);
    void roll(const std::string& playerName, int pins);
    int getPlayerScore(const std::string& name) const;
    Player getPlayer(const std::string& name) const;

private:
    std::vector<Player> players;
};

#endif
