#ifndef TICTACTOEFUNCS_H
#define TICTACTOEFUNCS_H
#include <iostream>
#include <string>
#include "board.h"

board make_move(board currBoard, char player,int xCord, int yCord);

char get_winner(board currBoard);
bool board_full(board currBoard);

#endif