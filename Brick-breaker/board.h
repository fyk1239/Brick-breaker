#pragma once

#ifndef __BOARD_H__
#define __BOARD_H__

#include <easyx.h>
#include <Windows.h>

class Board
{
public:
	Board(int x, int y, int width, int height, int speed, COLORREF color); //x坐标和y坐标均为
	int x;
	int y;
	int width;
	int height;
	int speed;
	COLORREF color;
	~Board(){}

private:

};

Board::Board(int x, int y, int width, int height, int speed, COLORREF color)
{

}

Board::~Board()
{
}

void drawboard0(Board& board)
{

}

#endif // !__BOARD_H__
