#pragma once

#ifndef __BALL_H__
#define __BALL_H__

class Ball
{
public:
	Ball(int circle, int vx, int vy, COLORREF color);
	int circle;
	int x = 300;
	int y = 300;
	int vx;
	int vy;
	COLORREF color;
	Ball();
	~Ball();

private:

};

Ball::Ball()
{

}

void drawball(Ball& ball)
{

}

#endif // !__BALLS_H__
