#pragma once
class board
{
private:
	int _rows;
	int _cols;
	char _apiece;
	char **pieces;
public:
	board();
	board(int rows, int cols, char element);//creates board and fills it
	void drawBoard();//prints board
	char getPiece(int r, int c);
	void setTTTPiece(char piece);//places a piece for tictactoe
	void setPieceCfour(int colPieces[], int turn, int col); // places a piece for connect four
};