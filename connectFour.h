#include "Board.h"
#pragma once
class connectFour
{
private:
	board cFour;
public:
	connectFour(board connectfour);
	bool checkWinConnectFour(int colPieces[], int turn, int col); // checks for connect four win
};