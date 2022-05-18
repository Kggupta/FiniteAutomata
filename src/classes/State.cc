#include "State.h"

string State::getName() const {return name;}

bool State::isAccept() const {return accepting;}

State::State(string name, bool accept = false): name(name), accepting(accepting) {}

void State::setAccepting(bool accept) {accepting = accept;}

bool operator<(const State &left, const State &right) {
    return left.getName() < right.getName();
}

bool operator==(const State &left, const State &right) {
    return left.getName() == right.getName();
}

bool operator==(const State &left, const string &right) {
    return left.getName() == right;
}
