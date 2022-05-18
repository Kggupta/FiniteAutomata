#include "Transition.h"
#include "State.h"

Transition::Transition(State & src, char read, State & dest): src(src), read(read), dest(dest) {}

State & Transition::getDestination() const {return dest;}

char Transition::getRead() const {return read;}

State & Transition::getSource() const {return src;}

bool operator== (const Transition &left, const Transition &right) {
    return left.getRead() == right.getRead() && (left.getSource() == right.getSource());
}