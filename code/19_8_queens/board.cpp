#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Board
{
private:
    int n;                      // Size of the board (size x size)
    vector<vector<bool>> board; // 2D board representation
    vector<bool> cols;          // Tracks if a column is occupied
    vector<bool> diag1;         // Tracks if a major diagonal (\) is occupied
    vector<bool> diag2;         // Tracks if a minor diagonal (/) is occupied

public:
    // Constructor to initialize board and helper arrays
    Board(int n) : n(n),
                   board(n, vector<bool>(n, false)),
                   cols(n, false),
                   diag1(2 * n - 1, false),
                   diag2(2 * n - 1, false) {}

    // Checks if it's safe to place a queen at (r, c)
    bool isSafe(int r, int c)
    {
        return !cols[c] && !diag1[r - c + n - 1] && !diag2[r + c];
    }

    int size() { return this->n; }

    // Places a queen at (r, c)
    void place(int r, int c)
    {
        board[r][c] = true;
        cols[c] = true;
        diag1[r - c + n - 1] = true;
        diag2[r + c] = true;
    }

    // Removes a queen from (r, c)
    void remove(int r, int c)
    {
        board[r][c] = false;
        cols[c] = false;
        diag1[r - c + n - 1] = false;
        diag2[r + c] = false;
    }

    // Returns a string representation of the board
    string toString()
    {
        ostringstream oss;
        for (int r = 0; r < n; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                oss << (board[r][c] ? "Q " : ". ");
            }
            oss << "\n";
        }
        return oss.str();
    }
};
