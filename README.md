# Deterministic Finite Automaton (DFA)

## Overview

This repository is my attempt at a DFA using C++.

In the theory of computation, a branch of theoretical computer science, a deterministic finite automaton (DFA)—also known as deterministic finite acceptor (DFA), deterministic finite-state machine (DFSM), or deterministic finite-state automaton (DFSA)—is a finite-state machine that accepts or rejects a given string of symbols, by running through a state sequence uniquely determined by the string. ([Source](https://en.wikipedia.org/wiki/Deterministic_finite_automaton))

## Motivation

After creating the [MIPS emulator](https://github.com/Kggupta/MipsEmulator), I created this DFA project as another step towards creating my own programming language. The DFA will allow me to tokenize the input and do basic syntax checking.

Further syntax and semantic checks will have to be done with a context sensitive grammar.

## Features

This project contains the following features.
- Add states to the DFA
- Add transitions between states
- Reset the DFA
- Change whether a state is accepting or not
- Munch an input string into tokens
- Parse an input string and determine if it's accepting or not

## Next Steps

As an interesting task, I want to add a GUI which visualizes the DFA graphically.

In the next step of creating a programming language, I will create a context sensitive grammar algorithm which will do further syntax and semantic analysis.
