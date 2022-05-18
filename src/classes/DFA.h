#ifndef __DFA_H
#define __DFA_H
#include "State.h"
#include "InvalidState.h"
#include "Transition.h"
#include <vector>
using namespace std;

class DFA {
    vector<State *> states;
    vector<Transition *> transitions;
    State * currentState;
    State * startState; 
    bool hasState(string & state);
    bool hasTransition(string & src, char read);
    State * getDestination(char read);
    State * getState(string & name);
    public:
    void addState(string state);
    void setAccept(string state, bool set);
    void addTransition(string src, string dest, char read);
    void setStart(string state);

    bool isFailed() const;
    bool isAccept() const;

    void reset();

    vector<string> munch(string in);
    bool parse(string in);
};

#endif