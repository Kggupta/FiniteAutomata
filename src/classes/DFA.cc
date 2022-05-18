#include "DFA.h"

State * DFA::getDestination(char read) {
    for (Transition * i : transitions) {
        if (i->getSource() == currentState && i->getRead() == read) return i->getDestination();
    }
    throw InvalidScan("No transition found.");
}

bool DFA::hasState(string & name) {
    for (auto i : states) {
        if (*i == name) return true;
    }
    return false;
}

void DFA::addState(string name) {
    if (hasState(name)) throw InvalidScan("State " + name + " already exists.");

    states.emplace_back(new State(name));
}

State * DFA::getState(string & name) {
    for (State * i : states) {
        if (*i == name) return i;
    }
    throw InvalidScan("State " + name + " does not exist.");
}

void DFA::setAccept(string name, bool set) {
    State * state = getState(name);
    state->setAccepting(set);
}

bool DFA::hasTransition(string & name, char val) {
    for (Transition * i : transitions) {
        if (*i->getSource() == name && i->getRead() == val) return true;
    }
    return false;
}

void DFA::addTransition(string src, string dest, char read) {
    if (hasTransition(src, read)) throw InvalidScan("Transition already exists.");
    
    State * srcState = getState(src);
    State * destState = getState(dest);
    transitions.emplace_back(new Transition(srcState, read, destState));
}

void DFA::setStart(string state) {
    State * start = getState(state);
    startState = start;
    currentState = start;
}

bool DFA::isFailed() const {
    if (currentState == nullptr) throw InvalidScan("No state assigned. Set a start state or reset the DFA.");
    return !currentState->isAccept();
}

bool DFA::isAccept() const {
    if (currentState == nullptr) throw InvalidScan("No state assigned. Set a start state or reset the DFA.");
    return currentState->isAccept();
}

void DFA::reset() {
    if (startState == nullptr) throw InvalidScan("Set a start state.");
    currentState = startState;
}