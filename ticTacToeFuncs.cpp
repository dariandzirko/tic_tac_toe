#include "ticTacToeFuncs.h"

board make_move(board currBoard, char player,int xCord, int yCord)
{
    
    if(xCord > currBoard.size-1 ||  xCord < 0 )
    {
        std::cout << "That X-Cord is invalid please select another X-Cord" << std::endl;
        std::cout << "X-Cord: ";
        std::cin >> xCord;
        std::cout << std::endl;
    }

    if(yCord > currBoard.size-1 || yCord < 0)
    {
        std::cout << "That Y-Cord is invalid please select another Y-Cord" << std::endl;
        std::cout << "Y-Cord: ";
        std::cin >> yCord;
        std::cout << std::endl;
    }
    board tempBoard = currBoard;

    while( !( isspace(currBoard.boardState[yCord][xCord]) ) )
    {
        std::cout << "That move is invalid please make another move" << std::endl;
        std::cout << "X-Cord: ";
        std::cin >> xCord;
        std::cout << std::endl;

        std::cout << "Y-Cord: ";
        std::cin >> yCord;
        std::cout << std::endl;
    }

    tempBoard.boardState[yCord][xCord] = player;
    return tempBoard;
}

char get_winner(board currBoard)
{

    int count = 0;

    //Check cols
    for (int i = 0; i < currBoard.size; i++)
    {
        for (int j = 1; j < currBoard.size; j++)
        {
            if (currBoard.boardState[j][i] == ' ')
                break;
            if(currBoard.boardState[j][i] != currBoard.boardState[j-1][i])
                break;
            if(j==currBoard.size-1)
                return currBoard.boardState[j][i];
        }
    }

    //Check rows
    for (int i = 0; i < currBoard.size; i++)
    {
        for (int j = 1; j < currBoard.size; j++)
        {
            if (currBoard.boardState[i][j] == ' ')
                break;
            if(currBoard.boardState[i][j] != currBoard.boardState[i][j-1])
                break;
            if(j==currBoard.size-1)
                return currBoard.boardState[i][j];
        }
    }

    //Check Diag
    for (int i = 1; i < currBoard.size; i++)
    {
        if (currBoard.boardState[i][i] == ' ')
            break;
        if(currBoard.boardState[i][i] != currBoard.boardState[i-1][i-1])
            break;
        if(i==currBoard.size-1)
            return currBoard.boardState[i][i];
    }
    
    //Check Anti-diag
    for (int i = 1; i < currBoard.size; i++)
    {
        if (currBoard.boardState[i][currBoard.size-1-i] == ' ')
            break;
        if(currBoard.boardState[i][currBoard.size-1-i] != currBoard.boardState[i-1][currBoard.size-i])
            break;
        if(i==currBoard.size-1)
            return currBoard.boardState[i][currBoard.size-i-1];
    }
    
    if(board_full(currBoard))
        return 'D';
    
    return 'Q';
}

bool board_full(board currBoard)
{
    for (int i = 0; i < currBoard.size; i++)
    {
        for (int j = 0; j < currBoard.size; j++)
        {
            if( isspace(currBoard.boardState[i][j]) )
                return false; 
        }
    }
    return true;
    
}

