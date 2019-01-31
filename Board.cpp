#include "Board.h"
#include <iostream>

using namespace std;
board::board()
{
	board(3, 3, '*');
}
board::board(int rows, int cols, char element) // creats board and fills it with *'s
{
	_rows = rows;
	_cols = cols;
	_apiece = element;

	//creates board
	pieces = new char*[_rows]; //create rows of board
	for (int row = 0; row < _rows; row++)
	{
		pieces[row] = new char[_cols]; //create columns of board
		for (int col = 0; col < _cols; col++)
		{
			pieces[row][_cols] = _apiece;
		}
	}

	//fills board
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			pieces[r][c] = '*';
		}

	}
}

void board::drawBoard()//draws board so players can see it
{
	cout << endl;
	for (int num = 0; num < _cols; num++)
	{
		cout << "   "<< num << " ";
	}
	cout << endl;
	for (int r = 0; r < _rows; r++)
	{
		cout << r;
		for (int c = 0; c < _cols; c++)
		{
			cout << "| " << pieces[r][c] << " |";
		}
		cout << endl << " ";
		for (int i = 0; i < _cols; i++)
		{
			cout << "|___|";
		}
		cout << endl;
	}
}

void board::setTTTPiece(char piece)//sets a X or O on the ttt board
{
	int row = 0;
	int col = 0;
	int y = 0;
	while (y == 0)
	{
		cout << "Enter a row and then column using the numbers above for " << piece << endl;
		cin >> row;
		cin >> col;
		if (pieces[row][col] != '*')
		{
			cout << " please pick an a vailable space \n";
		}
		else if (pieces[row][col] = '*')
		{
			pieces[row][col] = piece;
			y++;
		}
	}
}

char board::getPiece(int r, int c) //returns a peice on the board
{
	return pieces[r][c];
}

void board::setPieceCfour(int colPieces[], int turn, int col) //sets connect four peice
{

	if (turn % 2 != 0)
	{
		cout << "X's turn." << endl;
		cout << "Please Enter a column(numbers 0-6) you wish to drop your piece into" << endl;
		cin >> col;
		if ((col > 6) || (5 - colPieces[col] < 0))	//error trapping coordinates
		{
			cout << "Error, Please enter valid column" << endl;
			turn--;
		}
		else
		{
			pieces[5 - colPieces[col]][col] = 'X';
			colPieces[col]++;
		}
	}
	if (turn % 2 == 0)
	{
		cout << "O's turn." << endl;
		cout << "Please Enter a column(numbers 0-6) you wish to drop your piece into" << endl;
		cin >> col;
		if ((col > 6) || (5 - colPieces[col] < 0))
		{
			cout << "Error, Please enter valid column" << endl;
		}
		else
		{
			pieces[5 - colPieces[col]][col] = 'O';
			colPieces[col]++;
		}
	}
}