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
	Board(int x, int y, int width, int height, int speed); // x坐标和y坐标均为上表面中心点的坐标
	int x;      // 木板上表面的x坐标
	int y;      // 木板上表面的y坐标
	int width;  // 木板的宽度
	int height; // 木板的高度
	int left;   // 木板左边缘
	int right;  // 木板右边缘
	int speed;  // 木板速度
	~Board(){}

private:

};

Board::Board(int x, int y, int width, int height, int speed)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->left = x - width / 2;
	this->right = x + width / 2;
	this->speed = speed;
}

void drawboard(Board& board)
{
	POINT p;
	GetCursorPos(&p);
	board.speed = p.x - board.x; // 更新木板的速度
	board.x = p.x;               
	board.left = board.x - board.width / 2;
	board.right = board.x + board.width / 2;// 更新木板的位置
	setfillcolor(WHITE);
	fillrectangle(board.left, board.y, board.right, board.y + board.height); // 更新木板的位置
}

#endif // !__BOARD_H__
