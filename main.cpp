#include <iostream>
#include <vector>

class BowlingGame {
private:
    std::vector<int> rolls;

public:
    void roll(int pins) {
        rolls.push_back(pins);
    }

    int score() {
        int totalScore = 0;
        int frameIndex = 0;

        for (int frame = 0; frame < 10; ++frame) {
            if (isStrike(frameIndex)) {  // Strike
                totalScore += 10 + strikeBonus(frameIndex);
                frameIndex += 1;
            } else if (isSpare(frameIndex)) {  // Spare
                totalScore += 10 + spareBonus(frameIndex);
                frameIndex += 2;
            } else {  // Normal frame
                totalScore += sumOfBallsInFrame(frameIndex);
                frameIndex += 2;
            }
        }

        return totalScore;
    }

private:
    bool isStrike(int index) {
        return rolls[index] == 10;
    }

    bool isSpare(int index) {
        return rolls[index] + rolls[index + 1] == 10;
    }

    int strikeBonus(int index) {
        return rolls[index + 1] + rolls[index + 2];
    }

    int spareBonus(int index) {
        return rolls[index + 2];
    }

    int sumOfBallsInFrame(int index) {
        return rolls[index] + rolls[index + 1];
    }
};

// ---- Driver Code ----
int main() {
    BowlingGame bowl;
    std::cout << "Enter the number of pins knocked down in each roll (up to 21 rolls max):" << std::endl;

    int pins;
    int rollCount = 0;
    while (rollCount < 21) {
        std::cout << "Roll " << (rollCount + 1) << ": ";
        std::cin >> pins;

        if (pins < 0 || pins > 10) {
            std::cout << "Invalid input. Pins must be between 0 and 10.\n";
            continue;
        }

        bowl.roll(pins);
        ++rollCount;

        // Optional break condition to stop early after 10 frames
        if (rollCount >= 12 && bowl.score() >= 0) break;
    }

    std::cout << "\nFinal Score: " << bowl.score() << std::endl;
    return 0;
}
