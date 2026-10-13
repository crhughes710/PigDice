#include "TURN.h"
#include "DIE.h"
#include <iostream>
#include "PDGame.h" // 8.

TURN::TURN() {
    m_turnCount = 0;
    m_scoreThisTurn = 0;
    m_turnOver = false;
    m_choice = 'p';
}

void TURN::setParentGame(PDGame* parentGame) { // 6.
    m_parentGame = parentGame;
}

void TURN::takeTurn() {
    m_turnCount++;
    std::cout << "TURN " << m_turnCount << " - Game Score: "  << m_parentGame->getGameScore() << "\n"; // 9.
    while (m_turnOver == false) {
        std::cout << "roll or hold? (r/h): ";
        std::cin >> m_choice;
        if (m_choice == 'r') {
            roll();
        }
        else if (m_choice == 'h') {
            m_turnOver = true;
        }
        else {
            std::cout<< "Invalid choice. Please either (r/h)\n";
        }
    }
    std::cout << "Score Banked This Turn: " << m_scoreThisTurn<< "\n\n";
}

int TURN::getTurnScore() const {
    return m_scoreThisTurn;
}

void TURN::resetTurnover() {
    m_turnOver = false;
}

int TURN::getTurnCount() const {
    return m_turnCount;
}

void TURN::resetScoreThisTurn() {
    m_scoreThisTurn = 0;
}

void TURN::roll() {
    m_myDie.rollDie();
    if (m_myDie.getDieValue() == 1) {
        std::cout << "Die: " << m_myDie.getDieValue() << "\n";
        m_turnOver = true;
        m_scoreThisTurn= 0;
        std::cout << "Turn over. No score.\n";
    }
    else {
        m_scoreThisTurn= m_myDie.getDieValue() + m_scoreThisTurn;
        std::cout << "Die: " << m_myDie.getDieValue() << " - Running score this turn: " << m_scoreThisTurn << "\n";
    }
}