#include<stdio.h>
#include<math.h>
#include<unistd.h>
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

void make_data(int,int,char[]);
void put(void);

char map[20][40];
int check[20][20];//visit 0  yet 1
int cell[400][2];
unsigned int S_state[2];
int treasure_num=0;
int moves=0;
int score=0;
long int start=0;

int bomb_num=0;
int KABE_num=0;

void goal(void){
	
	system("stty echo -icanon min 1 time 0");
	system("mpv \"goal.mp4\" --window-scale=1.33");
}
void death(void){
	
	system("stty echo -icanon min 1 time 0");
	system("mpv \"die.mp4\" --window-scale=3.2");
}
int checkRoot(void){
	int cell_count = 0;
	int now=0;
	int x=0;
	int y=0;
	
	cell[0][0]=1;
	cell[0][1]=1;
	if(check[1][1]==0){
//		printf("can't start\n");
		return 1;
	}
	while(1){

		x=cell[now][0];
		y=cell[now][1];//座標取り出し
		
		if(map[x][y]==GOAL){
			return 0;
		}
		
		if(check[x+1][y]){
			cell_count++;
			cell[cell_count][0]=x+1;
			cell[cell_count][1]=y;
			check[x+1][y]=0;
		}
		if(check[x][y+1]){
			cell_count++;
			cell[cell_count][0]=x;
			cell[cell_count][1]=y+1;
			check[x][y+1]=0;
		}
		if(check[x-1][y]){
			cell_count++;
			cell[cell_count][0]=x-1;
			cell[cell_count][1]=y;
			check[x-1][y]=0;
		}
		if(check[x][y-1]){
			cell_count++;
			cell[cell_count][0]=x;
			cell[cell_count][1]=y-1;
			check[x][y-1]=0;
		}
		now++;
		if(now>=cell_count){
//			printf("no goal\n");
			return 1;
		}
		
	}
}


void make_treasure(void){
	int i;
	for(i=0;i<treasure_num;i++){
		while(1){
			int x = rand()%18+1;
			int y= rand()%18+1;
			char a = map[x][y];
			if(a!=TREASURE&&a!=START&&a!=GOAL&&a!=KABE&&a!=BOMB){
				map[x][y]=TREASURE;
				break;
			}
		}
	}
}
void make_bomb(void){
	int i;
	for(i=0;i<bomb_num;i++){
		while(1){
			int x = rand()%18+1;
			int y= rand()%18+1;
			char a = map[x][y];
			if(a!=TREASURE&&a!=START&&a!=GOAL&&a!=KABE&&a!=BOMB){
				map[x][y]=BOMB;
				check[x][y]=0;
				break;
			}
		}
	}
}
void make_kabe(void){
	int i;
	for(i=0;i<KABE_num;i++){
		while(1){
			int x = rand()%18+1;
			int y= rand()%18+1;
			char a = map[x][y];
			if(a!=TREASURE&&a!=START&&a!=GOAL&&a!=KABE&&a!=BOMB){
				map[x][y]=KABE;
				check[x][y]=0;
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
	sprintf(a," TIME : %lds",time(NULL)-start);
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
			if(i == 1 && j == 0){
				map[i][j] = START; // スタートの設置
				check[i][j]=0;
			}else if(i == 18 && j == 19){
				map[i][j] = GOAL; // ゴールの設置
				check[i][j]=1;
			}else if(i == 0 || i == 19){
				map[i][j] = KABE;
				check[i][j]=0;
			}else if(j == 0 || j == 19){
				map[i][j] = KABE;
				check[i][j]=0;
			}else{
				map[i][j] = '.';
				check[i][j]=1;
			}
		}
	}
}

void output(void){
	
	for(int i=0;i<20;i++){
		for(int j=0;j<40;j++){
			if(map[i][j]==KABE){
				printf("\x1b[36m");
				printf("\x1b[40m");
			}else if(map[i][j]==START){
				printf("\x1b[34m");
				printf("\x1b[47m");
			}else if(map[i][j]==GOAL){
				printf("\x1b[34m");
				printf("\x1b[47m");
			}else if(map[i][j]==PLAYER){
				printf("\x1b[30m");
				printf("\x1b[47m");
			}else if(map[i][j]==TREASURE){
				printf("\x1b[33m");
				printf("\x1b[40m");
			}else if(map[i][j]==TREASURED){
				printf("\x1b[30m");
				printf("\x1b[43m");
			}else if(map[i][j]==BOMB){
				printf("\x1b[31m");
				printf("\x1b[40m");
			}else if(map[i][j]==GRASS){
				printf("\x1b[32m");
				printf("\x1b[40m");
			}
			if(j>=20){
				printf("\x1b[37m");
				printf("\x1b[40m");
			}
			printf("%c\x1b[37m",map[i][j]);
			printf("\x1b[40m");
		}
		printf("\n");
	}
	printf("\n");
}

void select_difficulty(void){
	system("stty -echo -icanon min 1 time 0");
	char a;
	int select = 1;
	while(1){
		if(select == 1){
				bomb_num=5;
				treasure_num=5;
				KABE_num=5;
		}else if(select == 2){
				bomb_num=20;
				treasure_num=10;
				KABE_num=15;
		}else if(select == 3){
				bomb_num=40;
				treasure_num=15;
				KABE_num=20;
		}else if(select == 4){
				bomb_num=100;
				treasure_num=20;
				KABE_num=45;
		
		}
		
		system("clear");
		printf("Select Difficulty u(up) or d(down)\n\n");
		if(select == 1)printf("\x1b[46m");
		printf("1Much0n\x1b[40m\n");
		if(select == 2)printf("\x1b[46m");
		printf("2Much0n\x1b[40m\n");
		if(select == 3)printf("\x1b[46m");
		printf("3Much0n\x1b[40m\n");
		if(select == 4)printf("\x1b[46m");
		printf("5*10^15Much0n\x1b[40m\n");
		printf("\nAre You Ready? -> Enter\n");
		
		a=getchar();
		
		if(a=='u'&&select!=1){
			select--;
		}
		if(a=='d'&&select!=4){
			select++;
		}
		if(a=='\n'){
			break;
		}
		
	}
	system("stty echo -icanon min 1 time 0");
}

int main (int argc, char *argv[]) {
	// system("stty -echo -icanon min 1 time 0");
	srand((int)time(NULL));
	
	select_difficulty();
	
	
	start = time(NULL);
	S_state[0] = 1;
	S_state[1] = 0;
	int on_treasure=0;
	int bombDeath = 0;
	int r=1;
	int cnt=1;
	int dot=1;
	system("clear");
	printf("Now Loading\n");
	
	
	
	do{
		long int now = time(NULL);
		if(now-start==cnt){
			system("clear");

			printf("Now Loading");
			for(int i=1;i<=dot;i++){
				printf(".");
			}
			printf("\n");
			dot=(dot%3)+1;
			cnt++;
		}
		
		make_map(); // マップの設定
		make_treasure();
		make_bomb();
		make_kabe();
	}while(checkRoot());
	
	
	make_moves();
	make_score();
	system("clear");
	output();
	start = time(NULL);
	
	char inputs[1000];
	scanf("%s",inputs);
	
	for(int i=0;i<strlen(inputs);i++){
		system("clear");
		
		char input = inputs[i];
		
		map[S_state[0]][S_state[1]] = GRASS;
		if(on_treasure){
			map[S_state[0]][S_state[1]] = TREASURED;
			on_treasure=0;
		}
		map[1][0] = KABE;
		
		if(input == 'F'||input == 'f'){
		}else if(input=='R'||input=='r'){
			r=r%4+1;
			moves++;
			make_moves();
			make_time();
			output();
			continue;
		}
		
		
		if(r==2){
			// printf("down\n");
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
		if(r==4){
			// printf("up\n");
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
		if(r==1){
			// printf("right\n");
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
		if(r==3){
			// printf("left\n");
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
		
		// printf("state[0]:%d state[1]:%d\n",S_state[0],S_state[1]);
		if(map[S_state[0]][S_state[1]] == GOAL){
			map[S_state[0]][S_state[1]] = PLAYER;
			make_rate();
			make_time();
			output();
			goal();
			exit(-1);
		}
		map[S_state[0]][S_state[1]] = PLAYER;
		make_moves();
		make_score();
		make_time();
		output();
		usleep(250000);
	}
	if(bombDeath){
		map[S_state[0]][S_state[1]] = PLAYER;
		score = 0;
		make_score();
		make_rate();
		make_time();
		output();
		death();
	}
	return 0;
}
