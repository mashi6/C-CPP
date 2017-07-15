#include <stdio.h>
#define KABE '#'
#define START 'S'
#define GOAL 'G'
#define PLAYER '@'
#define TREASURE '$'
#define BOMB '*'
#define GRASS '.'

char map[20][20]; // マップを保持する二次元配列

void make_map(void)
{
	int i, j;

	for(i = 0; i < 20; i++)
	{
		for(j = 0; j < 20; j++)
		{
			if(i == 1 && j == 0)
				map[i][j] = START; // スタートの設置
			else if(i == 18 && j == 19)
				map[i][j] = GOAL; // ゴールの設置
			else if(i == 0 || i == 19)
				map[i][j] = KABE;
			else if(j == 0 || j == 19)
				map[i][j] = KABE;
			else
				map[i][j] = '.';
			printf("\x1b[46m"); // 背景色の設定
			printf("\x1b[35m"); // 文字色の設定
			printf("%c", map[i][j]);
			printf("\x1b[49m"); // 背景色をデフォルトに戻す
			printf("\x1b[39m"); // 文字色をデフォルトに戻す
		}
		printf("\n");
	}

	printf("\n");
}

int main(int argc, char** argv)
{
	make_map(); // マップの設定
	return 0;
}
