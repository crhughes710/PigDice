#include "Multiplayer.h"

#include <algorithm>
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
}

void Multiplayer::mpPlayGame() {
    m_players[0].displayRules();
    while (!m_gameOver) {
        for (int i=0; i < m_players.size(); i++) {
            std::cout << "\n\n" << m_players[i].getPlayerName() << " (Score: " << m_players[i].getGameScore() << ") - ";
            m_players.at(i).playGame();
            displayScoreBoard();
        }
        checkForWinner();
    }
}

void Multiplayer::checkForWinner() {
    std::vector<int> check(m_players.size());
    for (int i=0; i < m_players.size(); i++) {
        if (m_players.at(i).getGameScore() >= 50){
            check.at(i) = m_players.at(i).getGameScore();
            m_gameOver = true;
        }
    }
    if (m_gameOver == true) {
        auto biggest = std::max_element(check.begin(), check.end());
        int index = std::distance(check.begin(), biggest);
        std::cout << "\n\nCongratulations! " << m_players[index].getPlayerName() << " you win with a score of " << m_players[index].getGameScore();
    }
}

void Multiplayer::displayScoreBoard() {
    for (int i=0; i < m_players.size(); i++) {
        std::cout << m_players[i].getPlayerName() << " (Score: " << m_players[i].getGameScore() << ") | ";
    }
}