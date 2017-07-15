
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define KABE '#'
#define START 'S'
#define GOAL 'G'
#define PLAYER '@'
#define TREASURE '$'
#define BOMB '*'
#define GRASS '.'
#define right 'f'
#define left 's'
#define up 'e'
#define down 'd'



char map[20][20]; // マップを保持する二次元配列]
unsigned int S_state[2];


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
		}
	}
}

void output(void){
	FILE *fp;
	fp = fopen("test.txt","w");
	if(fp == NULL)
	{
		printf("ファイルを開けませんでした\n");
		exit(-1);
	}

	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			fprintf(fp,"%c",map[i][j]);
		}
		fprintf(fp,"\n");
	}
	fprintf(fp,"\n");
	fclose(fp);
}

int main (int argc, char *argv[]) {
	S_state[0] = 1;
	S_state[1] = 0;
	Mix_Init(0);
	Mix_Music *talk=0;
	talk = Mix_LoadMUS("goalMusic.mp3");
	Mix_VolumeMusic(3);
	Mix_PlayMusic(talk,1);

	make_map(); // マップの設定
	output();

	char input[10];

	while(1){
		scanf("%s",input);
		map[S_state[0]][S_state[1]] = GRASS;

		if(input[0] == down){
			printf("down\n");

			S_state[0]=S_state[0]+1;

			if(map[S_state[0]][S_state[1]]==KABE){
				S_state[0]=S_state[0]-1;
			}
		}
		if(input[0] == up){
			printf("up\n");
			S_state[0]=S_state[0]-1;
			if(map[S_state[0]][S_state[1]]==KABE){
				S_state[0]=S_state[0]+1;
			}
		}
		if(input[0] == right){
			printf("right\n");
			S_state[1]=S_state[1]+1;
			if(map[S_state[0]][S_state[1]]==KABE){
				S_state[1]=S_state[1]-1;
			}
		}
		if(input[0] == left){
			printf("left\n");
			S_state[1]=S_state[1]-1;
			if(map[S_state[0]][S_state[1]]==KABE){
				S_state[1]=S_state[1]+1;
			}
		}

		printf("state[0]:%d state[1]:%d\n",S_state[0],S_state[1]);
		map[S_state[0]][S_state[1]] = PLAYER;
		output();
	}
	return 0;
}
