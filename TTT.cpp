#include "Board.h"
#include "TTT.h"
#include <iostream>
using namespace std;

TicTacToe::TicTacToe(board t)
{
	ttt = t;
}
bool TicTacToe::isGameWon() //checks for TicTacToe win
{
		{
			char value;
			int count = 0;
			int runs = 0;
			for (int a = 0; a < 3; a++)
			{
				value = ttt.getPiece(a, 0);
				runs = 0;
				for (int b = 0; b < 3; b++)
				{
					runs++;
					if (value == ttt.getPiece(a, b) && value != '*')
					{
						count++;
					}
					if (runs == 3 && count != 3)
					{
						count = 0;
					}
					if (count == 3)
					{
						return true;
					}
				}
			}

			count = 0;

			runs = 0;
			for (int b = 0; b < 3; b++)
			{
				value = ttt.getPiece(0, b);
				runs = 0;
				for (int a = 0; a < 3; a++)
				{
					runs++;
					if (value == ttt.getPiece(a, b) && value != '*')
					{
						count++;
					}
					if (runs == 3 && count != 3)
					{
						count = 0;
					}
					if (count == 3)
					{
						return true;
					}
				}
			}

			count = 0;

			if (ttt.getPiece(0, 0) == 'X' && ttt.getPiece(1, 1) == 'X' && ttt.getPiece(2, 2) == 'X' || ttt.getPiece(0, 0) == 'O' && ttt.getPiece(1, 1) == 'O' && ttt.getPiece(2, 2) == 'O')
			{
				return true;
			}
			if (ttt.getPiece(0, 2) == 'X' && ttt.getPiece(1, 1) == 'X' && ttt.getPiece(2, 0) == 'X' || ttt.getPiece(0, 2) == 'O' && ttt.getPiece(1, 1) == 'O' && ttt.getPiece(2, 0) == 'O')

			{
				return true;
			}

			return false;
		}
	}