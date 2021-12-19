#pragma once
#ifndef __BRICK_H__
#define __BRICK_H__
#define MAX 100
#define SPACE 20
#include <easyx.h>
#include "ball.h"
#include "board.h"
#include <time.h>
#include <math.h>

static bool PlayerLose;   // 游戏失败信号
static bool PlayerWin;    // 游戏胜利信号
static int ClearedBricks = 0; // 已清除的砖块数量
static int TotalBricks = 0;   // 所有砖块数量

#ifndef HAW
#define HAW
#define HEIGHT 700
#define WIDTH 600
#endif // !HAW

#define HEIGHT_OF_BRICKS 4
#define WIDTH_OF_BRICKS 30

class Brick
{
public:
	Brick() 
	{
		this->color = 0;
	}
	~Brick() {};
	friend void initbricks();                           // 初始化砖块
	friend void drawbricks();                           // 绘制砖块
	friend void collision(Ball& ball, Board& board);    // 碰撞检测


private:
	int x;       // 横坐标
	int y;       // 纵坐标
	int color;   // 颜色
};

Brick brickarray[HEIGHT_OF_BRICKS][WIDTH_OF_BRICKS];

void initbricks()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < HEIGHT_OF_BRICKS; i++)
	{
		for (int j = 0; j < WIDTH_OF_BRICKS; j++)
		{
			if (j == 10 || j == 20 || i == HEIGHT_OF_BRICKS - 1)
			{
				brickarray[i][j].color = rand() % 5 + 1;
				brickarray[i][j].x = j * SPACE;
				brickarray[i][j].y = i * SPACE;
				TotalBricks++;
			}
			else
			{
				brickarray[i][j].color = 0;
			}
		}
	}
}

void drawbricks()
{
	IMAGE img01, img02, img03, img04, img05;
	//导入砖块素材
	loadimage(&img01, _T("..\\img\\blue.png"));
	loadimage(&img02, _T("..\\img\\green.png"));
	loadimage(&img03, _T("..\\img\\yellow.png"));
	loadimage(&img04, _T("..\\img\\red.png"));
	loadimage(&img05, _T("..\\img\\cyan.png"));

	for (int i = 0; i < HEIGHT_OF_BRICKS; i++)
	{
		for (int j = 0; j < WIDTH_OF_BRICKS; j++)
		{
			switch (brickarray[i][j].color)
			{
			case 1:
				putimage(brickarray[i][j].x, brickarray[i][j].y, &img01);
				break;
			case 2:
				putimage(brickarray[i][j].x, brickarray[i][j].y, &img02);
				break;
			case 3:
				putimage(brickarray[i][j].x, brickarray[i][j].y, &img03);
				break;
			case 4:
				putimage(brickarray[i][j].x, brickarray[i][j].y, &img04);
				break;
			case 5:
				putimage(brickarray[i][j].x, brickarray[i][j].y, &img05);
				break;
			default:
				break;
			}
		}
	}
}

// 碰撞检测
void collision(Ball& ball, Board& board)
{
	// 进入砖块区域，开始检测是否与砖块碰撞
	if (ball.up < (double)HEIGHT_OF_BRICKS * SPACE)
	{
		// 小球上边缘碰到砖块
		if (ball.up > 0 && brickarray[(int)(ball.up / SPACE)][(int)(ball.x / SPACE)].color != 0)
		{
			ball.vy = -ball.vy;
			brickarray[(int)(ball.up / SPACE)][(int)(ball.x / SPACE)].color = 0;
			ClearedBricks++;
		}
		
		// 小球下边缘碰到砖块
		if (ball.down < (double)HEIGHT_OF_BRICKS * SPACE && brickarray[(int)(ball.down / SPACE)][(int)(ball.x / SPACE)].color != 0)
		{
			ball.vy = -ball.vy;
			brickarray[(int)(ball.down / SPACE)][(int)(ball.x / SPACE)].color = 0;
			ClearedBricks++;
		}

		// 小球左边缘碰到砖块
		if (ball.y < (double)HEIGHT_OF_BRICKS * SPACE && ball.left > 0 && brickarray[(int)(ball.y / SPACE)][(int)(ball.left / SPACE)].color != 0)
		{
			ball.vx = -ball.vx;
			brickarray[(int)(ball.y / SPACE)][(int)(ball.left / SPACE)].color = 0;
			ClearedBricks++;
		}

		// 小球右边缘碰到砖块
		if (ball.y < (double)HEIGHT_OF_BRICKS * SPACE && ball.right < WIDTH && brickarray[(int)(ball.y / SPACE)][(int)(ball.right / SPACE)].color != 0)
		{
			ball.vx = -ball.vx;
			brickarray[(int)(ball.y / SPACE)][(int)(ball.right / SPACE)].color = 0;
			ClearedBricks++;
		}
	}

	// x轴方向与边界的碰撞
	if (ball.right >= WIDTH || ball.left <= 0) // 撞到x方向的边界
	{
		ball.vx = -ball.vx; // 小球反弹，x方向速度变为反向
	}

	// y轴方向与边界的碰撞
	if (ball.up <= 0) // 撞到y方向边界
	{
		ball.vy = -ball.vy; // 小球反弹，y方向速度变为反向
	}

	// 小球下边缘撞到木板
	if (ball.down >= board.y && ball.x > board.left && ball.x < board.right)
	{
		ball.vy = -ball.vy;                      // y方向速度变为反向
		ball.vx = -ball.vx - 0.1 * board.speed;  // x方向速度变为其相对于木板的速度
	}

	// 小球触碰到下边界,游戏结束
	if (ball.up >= HEIGHT)
	{
		PlayerLose = true;
		settextcolor(YELLOW);
		outtextxy(300, 370, _T("游戏结束"));
	}

	// 清除所有砖块
	if (ClearedBricks == TotalBricks)
	{
		PlayerWin = true;
		cleardevice();
		settextcolor(YELLOW);
		outtextxy(240, 370, _T("游戏结束,您已通关！"));
	}
}

#endif // !__BRICKS_H__
