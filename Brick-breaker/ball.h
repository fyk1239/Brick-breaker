#pragma once

#ifndef __BALL_H__
#define __BALL_H__

#include <easyx.h>

class Ball
{
public:
	Ball(int r, int vx, int vy, COLORREF color);
	int radius;
	int x;
	int y;
	int vx;
	int vy;
	COLORREF color;
};

Ball::Ball(int r, int vx, int vy, COLORREF color)
{
	this->radius = r;
	this->vx = vx;
	this->vy = vy;
	this->color = color;
}

void drawball(Ball& ball)
{
	ball.x += ball.vx;
	ball.y += ball.vy;
	setfillcolor(ball.color);
	fillcircle(ball.x, ball.y, ball.circle);
}

#endif // !__BALLS_H__
