#include "ai.h"


board randMove(char player, board currBoard)
{
    int xCord;
    int yCord;

    srand(time(NULL));

    /* generate secret number between 1 and 10: */
    xCord = rand() % 3;
    yCord = rand() % 3;

    while (!isspace(currBoard.boardState[xCord][yCord]))
    {
        xCord = rand() % 3;
        yCord = rand() % 3;
    }

    board tempBoard = make_move(currBoard,player,xCord,yCord);

    return tempBoard;
}
