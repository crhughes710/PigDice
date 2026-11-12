#ifndef PIGDICE__MY_VERSION__MULTIPLAYER_H
#define PIGDICE__MY_VERSION__MULTIPLAYER_H
#include <vector>
#include "PDGameV2.h"

class Multiplayer {
private:
    std::vector <PDGameV2> m_players;
    bool m_gameOver;
public:
    Multiplayer();
    void mpPlayGame();
private:
    void checkForWinner();
    void displayScoreBoard();
};

#endif //PIGDICE__MY_VERSION__MULTIPLAYER_H
