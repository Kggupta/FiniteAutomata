#ifndef __DFA_H
#define __DFA_H
#include "State.h"
#include "InvalidState.h"
#include <array>
#include <set>
#include <vector>
using namespace std;
const int TRANSITION_NUM = 128;
const int MAX_STATES = 128;

class DFA {
    set<State> states;
    array<array<State, TRANSITION_NUM>, MAX_STATES> transitions;
    State & currentState;
    State & startState; 
    State & getDestination(string state, char read);
    public:
    void addState(string state);
    void setAccept(string state, bool set);
    void addTransition(string src, string dest, string read);
    void setStart(string state);

    void isFailed() const;
    void isAccept() const;

    void reset();

    vector<string> munch(string in);
    bool parse(string in);
};

#endif