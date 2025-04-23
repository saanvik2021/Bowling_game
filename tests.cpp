#include "Player.h"
#include <iostream>
#include <cassert>

void testNormalFrame() {
    Frame f;
    f.setRolls(3, 5);
    assert(f.getFrameScore() == 8);
    assert(!f.isStrike());
    assert(!f.isSpare());
}

void testSpare() {
    Frame f;
    f.setRolls(4, 6);
    assert(f.isSpare());
    assert(!f.isStrike());
}

void testStrike() {
    Frame f;
    f.setRolls(10, 0);
    assert(f.isStrike());
    assert(!f.isSpare());
}

void testTenthFrameWithBonus() {
    Frame f(true);
    f.setRolls(10, 0);
    f.setBonus(10);
    assert(f.getFrameScore() == 20);
}

void testPlayerScore() {
    Player p("Test");

    Frame f1;
    f1.setRolls(10, 0); // Strike

    Frame f2;
    f2.setRolls(4, 3);  // Next frame: 7 + bonus 4 from strike

    p.addFrame(f1);
    p.addFrame(f2);

    assert(p.calculateScore() == 24); // 10+4+3 + 4+3
}

void testInvalidFrameInput() {
    bool exceptionThrown = false;
    try {
        Frame f;
        f.setRolls(6, 7); // Invalid: sum > 10
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
}

int main() {
    try {
        testNormalFrame();
        testSpare();
        testStrike();
        testTenthFrameWithBonus();
        testPlayerScore();
        testInvalidFrameInput();
        std::cout << "All tests passed successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
    }
    return 0;
}
