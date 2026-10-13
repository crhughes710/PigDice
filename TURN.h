#ifndef PIGDICE__MY_VERSION__TURN_H
#define PIGDICE__MY_VERSION__TURN_H
#include "DIE.h"
//#include "PDGame.h"

class PDGame; // 3.

class TURN {
private:
    int m_turnCount;
    int m_scoreThisTurn;
    bool m_turnOver;
    char m_choice;
    Die m_myDie;
    PDGame* m_parentGame = nullptr; // 4.
public:
    TURN();
    void setParentGame(PDGame* parentGame); // 5.
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
