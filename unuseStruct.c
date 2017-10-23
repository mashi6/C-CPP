#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int GetRandom(int min,int max){
	return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

int main(void){
	srand((unsigned int)time(NULL));
	char char_name[100];
	int char_attack=GetRandom(100,200);
	int char_defence=GetRandom(100,200);
	int char_HP=GetRandom(100,200);

	char nakama_name[7] = "naka-ma";
	int nakama_attack=GetRandom(100,200);
	int nakama_defence=GetRandom(100,200);
	int nakama_HP=GetRandom(100,200);
	printf("名前を入力>");
	scanf("%s",char_name);

	printf("デスタムーアが現れた！\n");

	printf("%sはどうする\n1 > 逃げる\n2 > たたかう\n",char_name);
	int command;
	scanf("%d",&command);
	switch(command){
		case 1:
			printf("うまく逃げ....た....\nん？......あれ、夢だったのか。\n");
			break;
		case 2:
			printf("%sの攻撃！デスタムーアに%dダメージ！\n",char_name,char_attack / GetRandom(100,200));
			printf("こちらの攻撃がまるで通用しない！\n");
			printf("デスタムーアの攻撃！\n%sに%dダメージ！\n%sに%dダメージ！\n",char_name,GetRandom(5000,10000),nakama_name,GetRandom(5000,10000));
			printf("%sたちは力尽き......た...........\n....ん？.......あれ、夢だったのか。\n",char_name);
	}
	return 0;
}