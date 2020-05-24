#include "board.h"

board::board()
{
    int size = 3;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            boardState[i][j] = ' ';
    }

}

board::board(int boardSize)
{
    size = boardSize;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            boardState[i][j] = ' ';
    }
}

void board::print_board(void)
{
	std::cout << " "; 
	for (int k = 0; k < size; k++) 
		std::cout << " " << k;

	std::cout << "\n";	

	for (int i = 0; i < size; i++)
	{
		std::cout << i;	
		for (int j = 0; j < size; j++)
			std::cout << " " << boardState[i][j];

		std::cout << "\n";
	}
    
}

