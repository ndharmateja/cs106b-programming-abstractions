/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "board.cpp"
using namespace std;

bool solveQueens(Board &board, int row = 0)
{
    if (row == board.size())
    {
        cout << board.toString() << endl;
        return true;
    }

    // In row'th row, try all cols to place the queen and explore recursively
    for (int c = 0; c < board.size(); c++)
    {
        if (board.isSafe(row, c))
        {
            board.place(row, c);
            bool isDone = solveQueens(board, row + 1);

            // If we want all possible solutions
            // don't exit the function here
            if (isDone)
                return true;

            board.remove(row, c);
        }
    }

    return false;
}

int main()
{
    Board board(20);
    solveQueens(board);
    return 0;
}
