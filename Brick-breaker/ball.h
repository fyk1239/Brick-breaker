#pragma once

#ifndef __BALL_H__
#define __BALL_H__

#ifndef HAW
#define HAW
#define HEIGHT 700
#define WIDTH 600
#endif // !HAW

#include <easyx.h>

#define RADIUS 10

class Ball
{
public:
	Ball(double x, double y, double vx, double vy, COLORREF color);
	double x;     // С�����ĵ�x����
	double y;     // С�����ĵ�y����
	double vx;    // С���x�����ٶ�
	double vy;    // С���y�����ٶ�
	double up;    // С���ϱ�Ե��y����
	double down;  // С���±�Ե��y����
	double left;  // С�����Ե��x����
	double right; // С���ұ�Ե��x����
	COLORREF color;
};

Ball::Ball(double x, double y, double vx, double vy, COLORREF color)
{
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
	this->left = x + vx - RADIUS;
	this->right = x + vx + RADIUS;
	this->up = y + vy - RADIUS;
	this->down = y + vy + RADIUS;
	this->color = color;
}

void drawball(Ball& ball)
{
	ball.x += ball.vx;
	ball.y += ball.vy;
	ball.left += ball.vx;
	ball.right += ball.vx;
	ball.up += ball.vy;
	ball.down += ball.vy;  // ����С��λ��
	
	setfillcolor(ball.color);
	fillcircle(ball.x, ball.y, RADIUS);
}


#endif // !__BALLS_H__
