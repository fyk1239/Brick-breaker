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

static bool PlayerLose;   // ��Ϸʧ���ź�
static bool PlayerWin;    // ��Ϸʤ���ź�
static int ClearedBricks = 0; // �������ש������
static int TotalBricks = 0;   // ����ש������

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
	friend void initbricks();                           // ��ʼ��ש��
	friend void drawbricks();                           // ����ש��
	friend void collision(Ball& ball, Board& board);    // ��ײ���


private:
	int x;       // ������
	int y;       // ������
	int color;   // ��ɫ
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
	//����ש���ز�
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

// ��ײ���
void collision(Ball& ball, Board& board)
{
	// ����ש�����򣬿�ʼ����Ƿ���ש����ײ
	if (ball.up < (double)HEIGHT_OF_BRICKS * SPACE)
	{
		// С���ϱ�Ե����ש��
		if (ball.up > 0 && brickarray[(int)(ball.up / SPACE)][(int)(ball.x / SPACE)].color != 0)
		{
			ball.vy = -ball.vy;
			brickarray[(int)(ball.up / SPACE)][(int)(ball.x / SPACE)].color = 0;
			ClearedBricks++;
		}
		
		// С���±�Ե����ש��
		if (ball.down < (double)HEIGHT_OF_BRICKS * SPACE && brickarray[(int)(ball.down / SPACE)][(int)(ball.x / SPACE)].color != 0)
		{
			ball.vy = -ball.vy;
			brickarray[(int)(ball.down / SPACE)][(int)(ball.x / SPACE)].color = 0;
			ClearedBricks++;
		}

		// С�����Ե����ש��
		if (ball.y < (double)HEIGHT_OF_BRICKS * SPACE && ball.left > 0 && brickarray[(int)(ball.y / SPACE)][(int)(ball.left / SPACE)].color != 0)
		{
			ball.vx = -ball.vx;
			brickarray[(int)(ball.y / SPACE)][(int)(ball.left / SPACE)].color = 0;
			ClearedBricks++;
		}

		// С���ұ�Ե����ש��
		if (ball.y < (double)HEIGHT_OF_BRICKS * SPACE && ball.right < WIDTH && brickarray[(int)(ball.y / SPACE)][(int)(ball.right / SPACE)].color != 0)
		{
			ball.vx = -ball.vx;
			brickarray[(int)(ball.y / SPACE)][(int)(ball.right / SPACE)].color = 0;
			ClearedBricks++;
		}
	}

	// x�᷽����߽����ײ
	if (ball.right >= WIDTH || ball.left <= 0) // ײ��x����ı߽�
	{
		ball.vx = -ball.vx; // С�򷴵���x�����ٶȱ�Ϊ����
	}

	// y�᷽����߽����ײ
	if (ball.up <= 0) // ײ��y����߽�
	{
		ball.vy = -ball.vy; // С�򷴵���y�����ٶȱ�Ϊ����
	}

	// С���±�Եײ��ľ��
	if (ball.down >= board.y && ball.x > board.left && ball.x < board.right)
	{
		ball.vy = -ball.vy;                      // y�����ٶȱ�Ϊ����
		ball.vx = -ball.vx - 0.1 * board.speed;  // x�����ٶȱ�Ϊ�������ľ����ٶ�
	}

	// С�������±߽�,��Ϸ����
	if (ball.up >= HEIGHT)
	{
		PlayerLose = true;
		settextcolor(YELLOW);
		outtextxy(300, 370, _T("��Ϸ����"));
	}

	// �������ש��
	if (ClearedBricks == TotalBricks)
	{
		PlayerWin = true;
		cleardevice();
		settextcolor(YELLOW);
		outtextxy(240, 370, _T("��Ϸ����,����ͨ�أ�"));
	}
}

#endif // !__BRICKS_H__
