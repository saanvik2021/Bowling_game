#include "Player.h"

Player::Player(const std::string& playerName) : name(playerName) {}

void Player::addFrame(const Frame& frame) {
    if (frames.size() >= 10) {
        throw std::runtime_error("Cannot add more than 10 frames.");
    }
    frames.push_back(frame);
}

const std::string& Player::getName() const {
    return name;
}

const std::vector<Frame>& Player::getFrames() const {
    return frames;
}

int Player::calculateScore() const {
    int totalScore = 0;

    for (size_t i = 0; i < frames.size(); ++i) {
        const Frame& current = frames[i];
        totalScore += current.getRoll1() + current.getRoll2();

        if (current.isStrike() && i + 1 < frames.size()) {
            const Frame& next = frames[i + 1];
            totalScore += next.getRoll1();
            if (next.isStrike() && i + 2 < frames.size()) {
                totalScore += frames[i + 2].getRoll1();
            } else {
                totalScore += next.getRoll2();
            }
        } else if (current.isSpare() && i + 1 < frames.size()) {
            totalScore += frames[i + 1].getRoll1();
        }

        if (i == 9) {
            totalScore += current.getBonus();
        }
    }

    return totalScore;
}