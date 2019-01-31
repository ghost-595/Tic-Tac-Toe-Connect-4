#pragma once
#include "Board.h"
class TicTacToe
{
private:
	board ttt;
public:
	TicTacToe(board t);
	bool isGameWon(); //checks for TicTacToe win
};