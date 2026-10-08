#ifndef PIGDICE__MY_VERSION__TURN_H
#define PIGDICE__MY_VERSION__TURN_H
#include "DIE.h"


class TURN {
private:
    int m_turnCount;
    int m_scoreThisTurn;
    bool m_turnOver;
    char m_choice;
    Die m_myDie;
public:
    TURN();
    //TURN(&);
    void takeTurn();
    int getTurnScore() const;
    void resetTurnover();
    int getTurnCount() const;
    void resetScoreThisTurn();
private:
    void roll();
};

#endif //PIGDICE__MY_VERSION__TURN_H
