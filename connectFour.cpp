#include "connectFour.h"
#include "Board.h"
#include <iostream>

using namespace std;
connectFour::connectFour(board connectfour)
{
	cFour = connectfour; 
}
bool connectFour::checkWinConnectFour(int colcpiece[], int turn, int col) //checks for connect for win
{
	int wantWin;
	cout << "Check for win?" << endl;
	cout << "Press 1 to check for win" << endl;
	cout << "Press 2 to continue on with game" << endl;
	cin >> wantWin;
	if (wantWin == 1)
	{
		cout << "Checking for win..." << endl;
		if (turn % 2 == 0)
		{
			int i, j, k, count;
			for (i = 0; i<7; i++)
			{
				for (j = 0; j<6 - 3; j++)
				{
					//checks horizontal win
					if (cFour.getPiece(i, j) != '*' && cFour.getPiece(i, j) == cFour.getPiece(i, j + 1) && cFour.getPiece(i, j) == cFour.getPiece(i, j + 2) && cFour.getPiece(i, j) == cFour.getPiece(i, j + 3))
					{
						cout << "X wins" << endl;
						system("Pause");
						return true;
					}
					//checks vertical win
					if (cFour.getPiece(i, j) != '*' && cFour.getPiece(i, j) == cFour.getPiece(i + 1, j) && cFour.getPiece(i, j) == cFour.getPiece(i + 2, j) && cFour.getPiece(i, j) == cFour.getPiece(i + 3, j))
					{
						cout << "X wins" << endl;
						system("Pause");
						return true;
					}
					//checks diagonal win
					count = 0;
					for (k = 1; k<4; k++)
					{
						if (cFour.getPiece(i, j) == cFour.getPiece(i + k, j + k) && cFour.getPiece(i, j) != '*')
						{
							count++;
						}
						else
						{
							count = 0;
						}
						if (count == 3)
						{
							cout << "X wins" << endl;
							system("Pause");
							return true;
						}
						else
						{
							return false;
						}
					}
				}
			}
		}
		if (turn % 2 != 0)
		{
			int i, j, k, count;
 			for (i = 0; i<7; i++)
			{
				for (j = 0; j<6 - 3; j++)
				{
					//checks horizontal win
					if (cFour.getPiece(i, j) != '*' && cFour.getPiece(i, j) == cFour.getPiece(i, j + 1) && cFour.getPiece(i, j) == cFour.getPiece(i, j + 2) && cFour.getPiece(i, j) == cFour.getPiece(i, j + 3))
					{
						cout << "O wins" << endl;
						system("Pause");
						return true;
					}
					//checks vertical win
					if (cFour.getPiece(i, j) != '*' && cFour.getPiece(i, j) == cFour.getPiece(i + 1, j) && cFour.getPiece(i, j) == cFour.getPiece(i + 2, j) && cFour.getPiece(i, j) == cFour.getPiece(i + 3, j))
					{
						cout << "O wins" << endl;
						system("Pause");
						return true;
					}
					//checks diagonal win
					count = 0;
					for (k = 1; k<4; k++)
					{
						if (cFour.getPiece(i, j) == cFour.getPiece(i + k, j + k) && cFour.getPiece(i, j) != '*')
						{
							count++;
						}
						else
						{
							count = 0;
						}
						if (count == 3)
						{
							cout << "O wins" << endl;
							system("Pause");
							return true;
						}
						else
						{
							return false;
						}

					}
				}
			}
		}
	}
}