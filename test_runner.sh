#!/bin/bash

make clean
make
./TicTacToeBoardTest
gcov TicTacToeBoard.cpp
