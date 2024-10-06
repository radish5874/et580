#include <iostream>
#include <cmath>

using namespace std;

const int BOARD_SIZE = 8;

// Function to check if queens are safe
bool queensAreSafe(int board[])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = i + 1; j < BOARD_SIZE; j++)
        {
            // Check for queens sharing the same column
            if (board[i] == board[j])
            {
                return false;
            }

            // Check for queens sharing the same diagonal
            if (abs(i - j) == abs(board[i] - board[j]))
            {
                return false;
            }
        }
    }
    return true;
}

// Function to display the board
void displayBoard(int board[])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i] == j)
            {
                cout << "Q ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int board[BOARD_SIZE];
    bool safe = true;

    // Request values for the array from the console
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        cout << "请输入第 " << i + 1 << " 个皇后的位置：";
        cin >> board[i];
    }

    // Check if queens are safe
    safe = queensAreSafe(board);

    // Display the board and the result
    cout << endl;
    displayBoard(board);
    cout << endl;

    if (safe)
    {
        cout << "皇后是安全的。" << endl;
    }
    else
    {
        cout << "皇后不是安全的。" << endl;
    }

    return 0;
}