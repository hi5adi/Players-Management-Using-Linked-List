#include "Player.h"
#include <iostream>
#include <cstring>

using namespace std;

Player::Player() : jersynum(0), run(0), wicket(0), totalmatch(0) {
    std::strcpy(name, "not given");
}

Player::Player(int jersey,  char* playerName, int runs, int wickets, int matches)
    : jersynum(jersey), run(runs), wicket(wickets), totalmatch(matches) {
    std::strcpy(name, playerName);
    name[sizeof(name) - 1] = '\0';
}

void Player::setJersynum(int jersey) {
    jersynum = jersey;
}

void Player::setName( char* playerName) {
    std::strncpy(name, playerName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
}

void Player::setRun(int runs) {
    cout << "Setting runs to: " << runs << endl;
    run = runs;
}

void Player::setWicket(int wickets) {
    cout << "Setting wickets to: " << wickets << endl;
    wicket = wickets;
}

void Player::setTotalMatch(int matches) {
    cout << "Setting total matches to: " << matches << endl;
    totalmatch = matches;
}

int Player::getJersynum() const {
    return jersynum;
}

const char* Player::getName() const {
    return name;
}

int Player::getRun() const {
    return run;
}

int Player::getWicket() const {
    return wicket;
}

int Player::getTotalMatch() const {
    return totalmatch;
}

void Player::display() {
    std::cout << "\nJersey Number: " << jersynum;
    std::cout << "\nName: " << name;
    std::cout << "\nRuns: " << run;
    std::cout << "\nWickets: " << wicket;
    std::cout << "\nTotal Matches: " << totalmatch;
    std::cout << "\n-----------------------\n";
}

ostream& operator<<(std::ostream& os, const Player& player) {
    os << player.getJersynum() << " " << player.getName() << " " << player.getRun() << " " << player.getWicket() << " " << player.getTotalMatch();
    return os;
}

istream& operator>>(std::istream& is, Player& player) {
    is >> player.jersynum >> player.name >> player.run >> player.wicket >> player.totalmatch;
    return is;
}
