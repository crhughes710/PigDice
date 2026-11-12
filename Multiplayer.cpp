#include "Multiplayer.h"
#include <iostream>
#include <ostream>
#include "PDGameV2.h"

Multiplayer::Multiplayer() {
    int count;
    std::string tempName;
    std::cout << "How many people are playing? ";
    std::cin >> count;
    std::cin.ignore();
    for (int i=0; i < count; i++) {
        std::cout << "Enter player " << i + 1 << "'s name: ";
        std::getline(std::cin, tempName);
        m_players.emplace_back(tempName);
    }
    //mpPlayGame();
}

void Multiplayer::mpPlayGame() {
    m_players[0].displayRules();
    while (!m_gameOver) {
        for (int i=0; i < m_players.size(); i++) {
            std::cout << "\n\n" << m_players[i].getPlayerName() << "";
            m_players.at(i).playGame();
            displayScoreBoard();
        }
        checkForWinner();
    }
}

void Multiplayer::checkForWinner() {

}

void Multiplayer::displayScoreBoard() {
    for (int i=0; i < m_players.size(); i++) {
        std::cout << m_players[i].getPlayerName() << " (Score: " << m_players[i].getGameScore() << ") | \n\n";
    }
}