#pragma once
#ifndef __BRICK_H__
#define __BRICK_H__
#define MAX 100
#include <easyx.h>

class Brick
{
public:
	Brick();
	~Brick(){}

private:

};

Brick::Brick()
{
}

void drawbricks()
{
	IMAGE img01, img02, img03, img04;
	//µ¼Èë×©¿éËØ²Ä
	loadimage(&img01, L"01.jpeg", space, space);
	loadimage(&img02, L"02.jpeg", space, space);
	loadimage(&img03, L"03.jpeg", space, space);
	loadimage(&img04, L"04.jpeg", space, space);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			switch (brickarry[i][j])
			{
			case 1:
				putimage(j * space, i * space, &img01);
				break;
			case 2:
				putimage(j * space, i * space, &img02);
				break;
			case 3:
				putimage(j * space, i * space, &img03);
				break;
			case 4:
				putimage(j * space, i * space, &img04);
				break;
			default:
				break;
			}
		}
	}
}

#endif // !__BRICKS_H__
