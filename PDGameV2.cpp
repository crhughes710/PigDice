#include "PDGameV2.h"
#include "PDGame.h"
#include <iostream>

PDGameV2::PDGameV2(std::string &playerName) {
    if (playerName == "") {
        int i = 1;
        m_playerName = "Anonymous Player " + std::to_string(i);
        i++;
    }
    else {
        m_playerName = playerName;
    }
}


void PDGameV2::playGame() {
        m_myTurn.takeTurn();
}

void PDGameV2::displayRules() {
    std::cout << "\n\nLet's Play PIG Dice!\n\n";
    std::cout << "* See which player will reach 50 points in the fewest turns.\n";
    std::cout << "* Turn ends when you hold or roll a 1\n";
    std::cout << "* If you roll a 1, you lose all points for the turn.\n";
    std::cout << "* If you hold, you save all points for the turn.\n\n";

}

std::string PDGameV2::getPlayerName() {
    return m_playerName;
}