#pragma once

#ifndef __BOARD_H__
#define __BOARD_H__

#define HEIGHT_OF_BOARD 20
#define WIDTH_OF_BOARD 200

#include <easyx.h>
#include <Windows.h>

class Board
{
public:
	Board(int x, int y, int width, int height, int speed, COLORREF color); //x�����y�����Ϊ�ϱ������ĵ������
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
