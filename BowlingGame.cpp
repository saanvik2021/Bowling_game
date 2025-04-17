#include <stdexcept>
#include "BowlingGame.h"

BowlingGame::BowlingGame() {}

void BowlingGame::addPlayer(const std::string& name) {
    players.emplace_back(name);
}

void BowlingGame::roll(const std::string& playerName, int pins) {
    for (auto& p : players) {
        if (p.getName() == playerName) {
            p.roll(pins);
            return;
        }
    }
    throw std::invalid_argument("Player not found");
}

int BowlingGame::getPlayerScore(const std::string& name) const {
    for (const auto& p : players) {
        if (p.getName() == name) {
            return p.getTotalScore();
        }
    }
    throw std::invalid_argument("Player not found");
}

Player BowlingGame::getPlayer(const std::string& name) const {
    for (const auto& p : players) {
        if (p.getName() == name) return p;
    }
    throw std::invalid_argument("Player not found");
}
