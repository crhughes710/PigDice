#ifndef PIGDICE__MY_VERSION__PDGAMEV2_H
#define PIGDICE__MY_VERSION__PDGAMEV2_H
#include <string>
#include "PDGame.h"


class PDGameV2:public PDGame {
private:
    std::string m_playerName;
public:
    PDGameV2(std::string &playerName);
    std::string getPlayerName();
    void playGame();
    void displayRules();
};

#endif //PIGDICE__MY_VERSION__PDGAMEV2_H
