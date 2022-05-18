#ifndef __STATE_H
#define __STATE_H
#include <string>
using std::string;

class State {
    const string name;
    bool accepting;
    public:
    State(string name, bool accept = false);
    string getName() const;
    bool isAccept() const;
    void setAccepting(bool accept);
};

bool operator< (const State &left, const State &right);
bool operator== (const State &left, const State &right);
bool operator== (const State &left, const string &right);
#endif