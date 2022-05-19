#include "DFA.h"
#include <iostream>
using namespace std;

int main() {
    DFA *dfa = new DFA();
    string command;
    while (true) {
        string value;
        string dest;
        string read;
        cin >> command;
        
        if (cin.fail() || command == "exit") break;
        try {
            if (command == "reset") {
                dfa->reset();
            } else if (command == "stateadd") {
                cin >> value;
                dfa->addState(value);
            } else if (command == "transadd") {
                cin >> value;
                cin >> dest;
                cin >> read;
                dfa->addTransition(value, dest, read);
            } else if (command == "setstart") {
                cin >> value;
                dfa->setStart(value);          
            } else if (command == "setaccept") {
                cin >> value;
                dfa->setAccept(value, true);
            } else if (command == "munch") {
                cin >> value;
                vector<string> munched = dfa->munch(value);
                for (auto i : munched) {
                    cout << i  << " ";
                }
                cout << endl;
            } else if (command == "parse") {
                cin >> value;
                cout << ((dfa->parse(value)) ? "ACCEPT" : "FAILED") << endl;
            }
        } catch (InvalidScan & e) {
            cout << e.what() << endl;
        }
    }
    delete dfa;

}