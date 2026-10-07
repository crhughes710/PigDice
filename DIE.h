#ifndef PIGDICE_MY_VERSION_DIE_H
#define PIGDICE_MY_VERSION_DIE_H

class Die {
private:
    int m_dieValue;
public:
    Die();
    void rollDie();
    int getDieValue() const;
};

#endif //PIGDICE_MY_VERSION_DIE_H
