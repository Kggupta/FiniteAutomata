#ifndef __TRANSITION_H
#define __TRANSITION_H
#include <string>
using std::string;
class State;

class Transition {
    State * src;
    char read;
    State * dest;
    public:
    Transition(State * src, char read, State * dest);
    State * getDestination() const;
    char getRead() const;
    State * getSource() const;
};

bool operator== (const Transition &left, const Transition &right);


#endif