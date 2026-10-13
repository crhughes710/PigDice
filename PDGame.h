#ifndef PIGDICE__MY_VERSION__PDGAME_H
#define PIGDICE__MY_VERSION__PDGAME_H
#include "TURN.h"

class PDGame {
private:
    TURN m_myTurn;
    bool m_gameOver;
    int m_gameScore;
public:
    PDGame();
    int getGameScore(); // 1.
private:
    static void displayRules();
    void playGame();
};

#endif //PIGDICE__MY_VERSION__PDGAME_H
