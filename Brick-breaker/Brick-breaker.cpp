// Brick-breaker.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <easyx.h>
#include <conio.h>
#include "ball.h"
#include "board.h"
#include "brick.h"

using namespace std;

#ifndef HAW
#define HAW
#define HEIGHT 700
#define WIDTH 600
#endif // !HAW

extern bool PlayerLose; // 游戏结束信号
extern bool PlayerWin;  // 游戏胜利信号

int main()
{
	initgraph(WIDTH, HEIGHT);

	Board board0(WIDTH / 2, HEIGHT - 20, WIDTH_OF_BOARD, HEIGHT_OF_BOARD, 20); // 创建木板
	Ball ball0(WIDTH / 2, (double)HEIGHT - 20 - RADIUS, 0.4, -0.4, YELLOW);    // 创建小球
	BeginBatchDraw();
	initbricks();
	PlayerLose = false;
	PlayerWin = false;
	while (!PlayerLose && !PlayerWin)
	{
		cleardevice();				 // 清除显示
		drawbricks();                // 刷新砖块显示
		collision(ball0, board0);    // 碰撞检测
		drawball(ball0);             // 刷新球的位置
		drawboard(board0);           // 刷新木板的位置
		FlushBatchDraw();
	}
	EndBatchDraw();
	int ch = _getch();
	closegraph();
	return 0;

}

