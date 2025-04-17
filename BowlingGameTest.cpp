#include <cassert>
#include <iostream>
#include "BowlingGame.h"

void testPerfectGame() {
    BowlingGame game;
    game.addPlayer("Arjun");
    for (int i = 0; i < 12; ++i) game.roll("Arjun", 10);
    assert(game.getPlayerScore("Arjun") == 300);
}

void testAllSpares() {
    BowlingGame game;
    game.addPlayer("Ram");
    for (int i = 0; i < 21; ++i) game.roll("Ram", 5);
    assert(game.getPlayerScore("Ram") == 150);
}

void testAllZeros() {
    BowlingGame game;
    game.addPlayer("Jessy");
    for (int i = 0; i < 20; ++i) game.roll("Jessy", 0);
    assert(game.getPlayerScore("Jessy") == 0);
}

int main() {
    testPerfectGame();
    testAllSpares();
    testAllZeros();
    std::cout << "All tests passed!\n";
}
