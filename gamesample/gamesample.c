#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define KABE '#'
#define START 'S'
#define GOAL 'G'
#define PLAYER '@'
#define TREASURE '$'
#define TREASURED '8'
#define BOMB '*'
#define GRASS '.'
#define right 'f'
#define left 's'
#define up 'e'
#define down 'd'

void make_data(int,int,char[]);


char map[20][40];
unsigned int S_state[2];
int treasure_num=0;
int moves=0;
int score=0;

void goal(void){

	system("stty echo -icanon min 1 time 0");
	system("mpv \"goal.mp4\" --window-scale=1.33");
}
void death(void){

	system("stty echo -icanon min 1 time 0");
	system("mpv \"die.mp4\" --window-scale=3.2");
}
void checkRoot(void){

}
void make_treasure(void){
	int i;
	int j=rand()%10+2;
	for(i=0;i<j;i++){
		while(1){
			int x = rand()%18+1;
			int y= rand()%18+1;
			char a = map[x][y];
			if(a!=TREASURE&&a!=START&&a!=GOAL&&a!=KABE){
				map[x][y]=TREASURE;
				break;
			}
		}
	}
}
void make_bomb(void){
	int i;
	treasure_num=rand()%10+2;

	for(i=0;i<treasure_num;i++){
		while(1){
			int x = rand()%18+1;
			int y= rand()%18+1;
			char a = map[x][y];
			if(a!=TREASURE&&a!=START&&a!=GOAL&&a!=KABE&&a!=BOMB){
				map[x][y]=BOMB;
				break;
			}
		}
	}
}
void make_kabe(void){
		int i;
		treasure_num=rand()%10+2;

		for(i=0;i<treasure_num;i++){
			while(1){
				int x = rand()%18+1;
				int y= rand()%18+1;
				char a = map[x][y];
				if(a!=TREASURE&&a!=START&&a!=GOAL&&a!=KABE&&a!=BOMB){
					map[x][y]=KABE;
					break;
				}
			}
		}
	}

void make_moves(void){
	char a[20];
	sprintf(a," MOVES : %d",moves);
	make_data(2,21,a);
	return;
}
void make_score(void){
	char a[20];
	sprintf(a," SCORE : %d",score);
	make_data(4,21,a);
	return;
}
void make_rate(void){
	char a[20];
	sprintf(a," FINAL RATE : %0.1f",(float)score/(float)moves);
	make_data(8,21,a);
	return;
}
void make_time(void){
	char a[20];
	sprintf(a," NOW : %d",time(NULL));
	make_data(6,21,a);
	return;
}

void make_data(int x,int y,char a[]){
	if(40-y > 20){
		printf("out of range\n");
		return;
	}

	int num = strlen(a);
	for(int i=0;i<num;i++){
		map[x][y+i]=a[i];
	}
	return;
}

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
		for(int j=0;j<40;j++){
			fprintf(fp,"%c",map[i][j]);
		}
		fprintf(fp,"\n");
	}
	fprintf(fp,"\n");
	fclose(fp);
}

int main (int argc, char *argv[]) {
	system("stty -echo -icanon min 1 time 0");
	srand(time(NULL));

	S_state[0] = 1;
	S_state[1] = 0;
	int on_treasure=0;
	int bombDeath = 0;

	make_map(); // マップの設定
	make_treasure();
	make_bomb();
	make_kabe();
	make_moves();
	make_score();
	make_time();
	output();

	char input;

	while(1){
		system("clear");

		input = getchar();

		map[S_state[0]][S_state[1]] = GRASS;
		if(on_treasure){
			map[S_state[0]][S_state[1]] = TREASURED;
			on_treasure=0;
		}
		map[1][0] = KABE;


		if(input == down){
			printf("down\n");
			S_state[0]=S_state[0]+1;
			moves++;
			if(map[S_state[0]][S_state[1]]==KABE || map[S_state[0]][S_state[1]] == TREASURED){
				S_state[0]=S_state[0]-1;
				moves--;
			}else if(map[S_state[0]][S_state[1]] == TREASURE){
				on_treasure = 1;
				score=score+100;

			}else if(map[S_state[0]][S_state[1]] == BOMB){
				bombDeath = 1;
				break;
			}
		}
		if(input == up){
			printf("up\n");
			S_state[0]=S_state[0]-1;
			moves++;
			if(map[S_state[0]][S_state[1]]==KABE|| map[S_state[0]][S_state[1]] == TREASURED){
				S_state[0]=S_state[0]+1;
				moves--;
			}else if(map[S_state[0]][S_state[1]] == TREASURE){
				on_treasure = 1;
				score=score+100;

			}else if(map[S_state[0]][S_state[1]] == BOMB){
				bombDeath = 1;
				break;
			}
		}
		if(input == right){
			printf("right\n");
			S_state[1]=S_state[1]+1;
			moves++;
			if(map[S_state[0]][S_state[1]]==KABE|| map[S_state[0]][S_state[1]] == TREASURED){
				S_state[1]=S_state[1]-1;
				moves--;
			}else if(map[S_state[0]][S_state[1]] == TREASURE){
				on_treasure = 1;
				score=score+100;

			}else if(map[S_state[0]][S_state[1]] == BOMB){
				bombDeath = 1;
				break;
			}
		}
		if(input == left){
			printf("left\n");
			S_state[1]=S_state[1]-1;
			moves++;
			if(map[S_state[0]][S_state[1]]==KABE|| map[S_state[0]][S_state[1]] == TREASURED){
				moves--;
				S_state[1]=S_state[1]+1;
			}else if(map[S_state[0]][S_state[1]] == TREASURE){
				on_treasure = 1;
				score=score+100;

			}else if(map[S_state[0]][S_state[1]] == BOMB){
				bombDeath = 1;
				break;
			}
		}

		printf("state[0]:%d state[1]:%d\n",S_state[0],S_state[1]);
		if(map[S_state[0]][S_state[1]] == GOAL){
			map[S_state[0]][S_state[1]] = PLAYER;
			output();
			break;
		}
		map[S_state[0]][S_state[1]] = PLAYER;
		make_moves();
		make_score();
		make_time();
		output();
	}
	if(bombDeath){
		map[S_state[0]][S_state[1]] = PLAYER;
		score = 0;
		make_score();
		make_rate();
		output();
		death();
	}else{
		make_rate();
		output();
		goal();
	}
	return 0;
}
