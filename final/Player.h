#include <iostream>
#ifndef PLAYER_H
#define PLAYER_H
class Player {

    int jersynum;
    char name[30];
    int run;
    int wicket;
    int totalmatch;
public:
    Player();
    Player(int, char*, int, int, int);
    void setJersynum(int);
    void setName(char*);
    void setRun(int);
    void setWicket(int);
    void setTotalMatch(int);
    int getJersynum() const;
    const char* getName() const;
    int getRun() const;
    int getWicket() const;
    int getTotalMatch() const;
    void display();
    friend std::ostream& operator<<(std::ostream&, const Player&);
    friend std::istream& operator>>(std::istream&, Player&);
};
#endif



