#include "PDGame.h"
#include "TURN.h"
#include <iostream>

PDGame::PDGame() {
    m_gameOver = false;
    m_gameScore = 0;
    displayRules();
    playGame();
}

void PDGame::displayRules() {
    std::cout << "Let's Play PIG Dice!\n\n" <<
        "* See how many turns it takes you to get to 20 points.\n" <<
        "* Turn ends when you hold or roll a 1.\n" << "* If you roll a 1, you lose all points for the turn.\n" <<
        "* If you hold, you bank all points for the turn to the game score.\n\n";
}

void PDGame::playGame() {
    while (m_gameOver == false) {
        if (m_gameScore < 20) {
            m_myTurn.resetTurnover();
            m_myTurn.resetScoreThisTurn();
            m_myTurn.takeTurn();
            m_gameScore= m_myTurn.getTurnScore() + m_gameScore;
            // ^^^^^^^^^DELETE THIS AFTER POINTER^^^^^^^^^^^
        }
        else {
            std::cout << "You finished with a final score of " << m_gameScore << " in " << m_myTurn.getTurnCount() << " turns!\n" <<
            "Thanks for playing PIG Dice!\n";
            m_gameOver = true;
        }
    }
}
