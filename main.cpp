#include "board.h"
#include "ticTacToeFuncs.h"

int main()
{
    board myBoard = board(3);

    std::cout << "Player 1 goes first and is X Player 2 is 0" << std::endl;
    
    myBoard.print_board();
    int currXCord;
    int currYCord;

    char currPlayer;
    char winner;
    while(1)
    {
        //I should make this a get_move function, something that returns an int array, like int[] get_move(char currPlayer)
        currPlayer = 'X';
        std::cout << "Player 1's Turn"<< std::endl <<"What is your X-Cord: ";
        std::cin >> currXCord;
        std::cout << std::endl;

        std::cout << "What is your Y-Cord: ";
        std::cin >> currYCord;
        std::cout << std::endl;
        
        board tempBoard = make_move(myBoard,currPlayer,currXCord, currYCord);
        tempBoard.print_board();
        myBoard = tempBoard;

        winner = get_winner(myBoard);

        switch(winner) 
        {
            case 'X' :
                std::cout << "Player 1 Won" << std::endl; 
                return 0;
            case 'D' :
                std::cout << "It is a draw" << std::endl; 
                return 0;
            case 'Q' :

            default :
                winner = '!';
        }

        currPlayer = 'O';
        std::cout << "Player 2's Turn" << std::endl <<"What is your X-Cord: ";
        std::cin >> currXCord;
        std::cout << std::endl;

        std::cout << "What is your Y-Cord: ";
        std::cin >> currYCord;
        std::cout << std::endl;
        
        tempBoard = make_move(myBoard,currPlayer,currXCord, currYCord);
        tempBoard.print_board();
        myBoard = tempBoard;

        winner = get_winner(myBoard);

        switch(winner) 
        {
            case 'O' :
                std::cout << "Player 2 Won" << std::endl; 
                return 0;
            case 'D' :
                std::cout << "It is a draw" << std::endl; 
                return 0;
            case 'Q' :

            default :
                winner = '!';
        }

    }

    return 0;
}