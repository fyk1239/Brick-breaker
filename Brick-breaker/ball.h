#pragma once

#ifndef __BALL_H__
#define __BALL_H__

#define RADIUS 10

#include <easyx.h>

class Ball
{
public:
	Ball(int x, int y,int vx, int vy, COLORREF color);
	int x;
	int y;
	int vx;
	int vy;
	COLORREF color;
};

Ball::Ball(int x, int y,int vx, int vy, COLORREF color)
{
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
	this->color = color;
}

void drawball(Ball& ball)
{
	ball.x += ball.vx;
	ball.y += ball.vy;
	setfillcolor(ball.color);
	fillcircle(ball.x, ball.y, RADIUS);
}

#endif // !__BALLS_H__
