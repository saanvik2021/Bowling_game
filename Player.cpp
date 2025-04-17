#include <stdexcept>
#include "Player.h"


Player::Player(const std::string& name) : name(name) {}

void Player::roll(int pins) {
    if (frames.size() == 10 && frames.back().isComplete())
        throw std::logic_error("All frames are completed.");

    if (frames.empty() || frames.back().isComplete()) {
        bool isTenth = frames.size() == 9;
        frames.emplace_back(isTenth);
    }

    frames.back().addRoll(pins);
}

int Player::getTotalScore() const {
    int score = 0;
    for (size_t i = 0; i < frames.size(); ++i) {
        const Frame& frame = frames[i];
        score += frame.getScore();

        if (frame.isStrike() && i + 1 < frames.size()) {
            auto nextRolls = frames[i + 1].getRolls();
            if (nextRolls.size() < 2 && i + 2 < frames.size()) {
                auto next2 = frames[i + 2].getRolls();
                nextRolls.insert(nextRolls.end(), next2.begin(), next2.end());
            }
            score += nextRolls.size() > 0 ? nextRolls[0] : 0;
            score += nextRolls.size() > 1 ? nextRolls[1] : 0;
        } else if (frame.isSpare() && i + 1 < frames.size()) {
            auto nextRolls = frames[i + 1].getRolls();
            score += nextRolls.size() > 0 ? nextRolls[0] : 0;
        }
    }
    return score;
}

std::string Player::getName() const {
    return name;
}

std::vector<Frame> Player::getFrames() const {
    return frames;
}
