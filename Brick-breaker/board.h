#pragma once

#ifndef __BOARD_H__
#define __BOARD_H__

class Board
{
public:
	Board(int x, int y, int width, int height, int speed, COLORREF color);
	int x;
	int y;
	int width;
	int height;
	int speed;
	COLORREF color;
	Board();
	~Board();

private:

};

Board::Board()
{
}

Board::~Board()
{
}

void drawboard0(Board& board)
{

}

#endif // !__BOARD_H__
