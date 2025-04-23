#include "BowlingGame.h"
#include <iostream>

void BowlingGame::addPlayer(const Player& player) {
    players.push_back(player);
}

void BowlingGame::inputPlayerFrames(Player& player) {
    for (int i = 0; i < 10; ++i) {
        int r1, r2 = 0, bonus = 0;
        bool isTenth = (i == 9);

        std::cout << "Frame " << (i + 1) << " - Roll 1: ";
        std::cin >> r1;

        if (r1 != 10 || isTenth) {
            std::cout << "Frame " << (i + 1) << " - Roll 2: ";
            std::cin >> r2;
        }

        if (isTenth && (r1 == 10 || (r1 + r2) == 10)) {
            std::cout << "Frame " << (i + 1) << " - Bonus Roll: ";
            std::cin >> bonus;
        }

        Frame frame(isTenth);
        frame.setRolls(r1, r2);
        if (isTenth) {
            frame.setBonus(bonus);
        }

        player.addFrame(frame);
    }
}

void BowlingGame::scoreGame() const {
    for (const Player& player : players) {
        std::cout << "Player: " << player.getName()
                  << " | Total Score: " << player.calculateScore() << std::endl;
    }
}
