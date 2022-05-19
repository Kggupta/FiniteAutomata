CXX = g++
CXXFLAGS = -std=c++14 -Isrc/classes -Isrc/exceptions -g -Wall -MMD
EXEC = dfa
OBJECTS = src/main.o src/classes/DFA.o src/classes/State.o src/classes/Transition.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${DEPENDS} ${OBJECTS} ${EXEC}
