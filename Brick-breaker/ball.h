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
	double x;     // 小球中心的x坐标
	double y;     // 小球中心的y坐标
	double vx;    // 小球的x方向速度
	double vy;    // 小球的y方向速度
	double up;    // 小球上边缘的y坐标
	double down;  // 小球下边缘的y坐标
	double left;  // 小球左边缘的x坐标
	double right; // 小球右边缘的x坐标
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
	ball.down += ball.vy;  // 更新小球位置
	
	setfillcolor(ball.color);
	fillcircle(ball.x, ball.y, RADIUS);
}


#endif // !__BALLS_H__
