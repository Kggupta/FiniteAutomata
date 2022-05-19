#include "State.h"

string State::getName() const {return name;}

bool State::isAccept() const {return accepting;}

State::State(string name, bool accept): name(name), accepting(accept) {}

State::State(string name): name(name), accepting(false) {}

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
