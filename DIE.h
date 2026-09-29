//
// Created by chris on 9/29/26.
//

#ifndef PIGDICE_MY_VERSION_DIE_H
#define PIGDICE_MY_VERSION_DIE_H

class Die {
private:
    int m_value;
    int m_numOfSides;
public:
    Die();
    void setNumOfSides(int numOfSides);
    int getNumOfSides();
    void setValue() ;
    int getValue();
};

#endif //PIGDICE_MY_VERSION_DIE_H
