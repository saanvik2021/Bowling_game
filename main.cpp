#include "BowlingGame.h"
#include <iostream>

int main() {
    try {
        BowlingGame game;
        int numPlayers;

        std::cout << "Enter number of players: ";
        std::cin >> numPlayers;

        for (int i = 0; i < numPlayers; ++i) {
            std::string name;
            std::cout << "\nEnter name for player " << (i + 1) << ": ";
            std::cin >> name;

            Player player(name);
            game.inputPlayerFrames(player);
            game.addPlayer(player);
        }

        std::cout << "\n--- Final Scores ---\n";
        game.scoreGame();
    }
    catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}

