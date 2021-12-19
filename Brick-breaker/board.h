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
	Board(int x, int y, int width, int height, int speed); // x�����y�����Ϊ�ϱ������ĵ������
	int x;      // ľ���ϱ����x����
	int y;      // ľ���ϱ����y����
	int width;  // ľ��Ŀ��
	int height; // ľ��ĸ߶�
	int left;   // ľ�����Ե
	int right;  // ľ���ұ�Ե
	int speed;  // ľ���ٶ�
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
	board.speed = p.x - board.x; // ����ľ����ٶ�
	board.x = p.x;               
	board.left = board.x - board.width / 2;
	board.right = board.x + board.width / 2;// ����ľ���λ��
	setfillcolor(WHITE);
	fillrectangle(board.left, board.y, board.right, board.y + board.height); // ����ľ���λ��
}

#endif // !__BOARD_H__
