// Brick-breaker.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <time.h>
#include <easyx.h>
#include <conio.h>
#include "board.h"
#include "ball.h"
#include "brick.h"
using namespace std;

#define HEIGHT 1000
#define WIDTH 600
#define RADIUS 10
#define HEIGHT_OF_BOARD 20
#define WIDTH_OF_BOARD 200


int main()
{
	initgraph(HEIGHT, WIDTH);

	Board board(HEIGHT - 200, WIDTH / 2, HEIGHT_OF_BOARD, WIDTH_OF_BOARD, 20, 4);//创建木板
	Ball ball(RADIUS, 2, 2, YELLOW);
	//BeginBatchDraw()、FlushBatchDraw()、EndBatchDraw()用于防闪烁
	BeginBatchDraw();
	//sample(); //初始化砖块
	while (1)
	{
		cleardevice();				//清除显示，刷新砖块显示
		drawbrick();
		drawball(ball);
		collsion(ball, board);
		drawboard0(board);
		FlushBatchDraw();
	}
	EndBatchDraw();
	_getch();
	closegraph();
	return 0;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
