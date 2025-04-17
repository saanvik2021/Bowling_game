#include <iostream>
#include "BowlingGame.h"

int main() {
    try {
        BowlingGame game;
        game.addPlayer("Alice");

        for (int i = 0; i < 12; ++i) game.roll("Alice", 10); // Perfect game

        std::cout << "Alice's total score: " << game.getPlayerScore("Alice") << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}
