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
    for (auto i : states) {
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

void DFA::addTransition(string src, string dest, string read) {
    for (char i : read) {
        if (hasTransition(src, i)) throw InvalidScan("Transition already exists.");
        
        State * srcState = getState(src);
        State * destState = getState(dest);
        transitions.emplace_back(new Transition(srcState, i, destState));
    }
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

bool DFA::parse(string in) {
    reset();
    for (char i : in) {
        try {
            currentState = getDestination(i);
        } catch (InvalidScan & e) {
            return false;
        }
    }
    return isAccept();
}

vector<string> DFA::munch(string in) {
    vector<string> res;
    reset();

    string munched;

    for (string::const_iterator pos = in.begin(); pos != in.end();) {
        State *src = currentState;
        currentState = getDestination(*pos);
        if (isAccept()) {
            munched += *pos;
            src = currentState;
            pos++;
        }

        if (pos == in.end() || isFailed()) {
            if (src->isAccept()) {
                res.push_back(src->getName());
                munched = "";
                currentState = startState;
            } else {
                if (isFailed()) {
                    munched += *pos;
                }
                throw InvalidScan("Could not tokenize: " + munched + ".");
            }
        }
    }
    return res;
}

DFA::~DFA() {
    for (auto i : states) {
        delete i;
        i = nullptr;
    }
    for (auto i : transitions) {
        delete i;
        i = nullptr;
    }
}