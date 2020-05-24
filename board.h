#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>

class board
{
private:
    
public:
    
    char boardState[3][3];
    int size;

    board();
    board(int size);
 
    void print_board(void);

};
 
#endif