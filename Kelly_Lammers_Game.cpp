#include "Board.h"
#include "TTT.h"
#include "connectFour.h"
#include <iostream>
using namespace std;
int main()
{
	int driver = 0;
	int i = 1;
	char piece = 'X';
	bool victory = false;

	cout << "enter 1 for TicTacToe \n";
	cout << "enter 2 for connect 4 \n";
	cin >> driver;
	if (driver == 1)
	{
		board tttBoard(3, 3, '*');
		TicTacToe ttt(tttBoard);
		do
		{
			tttBoard.drawBoard();
			tttBoard.setTTTPiece(piece);
			victory = ttt.isGameWon();
			if (i == 0)
			{
				i++;
				piece = 'X';
			}
			else
			{
				i--;
				piece = 'O';
			}
		} while (victory != true);
		tttBoard.drawBoard();
		if (i == 1)
		{
			cout << "O wins!\n";
		}
		if (i == 0)
		{
			cout << "X wins!\n";
		}
	}
	if (driver == 2)
	{
		int winner = 0;
		const int COLSIZE = 10;
		int colPieces[COLSIZE];
		for (int num = 0; num <= 6; num++)
		{
			colPieces[num] = 0;
		}
		int turn = 1;
		int col = 0;
		board cfourBoard(6, 7, '*');
		connectFour cfour(cfourBoard);
		cfourBoard.drawBoard();
		while (turn<43)
		{
			cfourBoard.setPieceCfour(colPieces, turn, col);
			cfourBoard.drawBoard();
			if (cfour.checkWinConnectFour(colPieces, turn, col) == true)
			{
				turn = 44;
			}
			turn++;
		}
	}
	system("pause");
	return 0;
}