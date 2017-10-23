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
	int char_HP=GetRandom(1000,2000);

	char nakama_name[8] = "naka-ma";
	int nakama_attack=GetRandom(100,200);
	int nakama_defence=GetRandom(100,200);
	int nakama_HP=GetRandom(1000,2000);
	printf("名前を入力>");
	scanf("%s",char_name);

	int enemy_attack = GetRandom(100,200);
	int enemy_defence = GetRandom(100,200);
	int enemy_HP = GetRandom(10000,20000);

	printf("デスタムーアが現れた！\n");


while(1){
	if(char_HP > 0){
	printf("%sはどうする\n1 > 攻撃\n2 > 回復\n",char_name);
	int command;
	int command2;
	scanf("%d",&command);
	switch(command){
		case 1:
			printf("%sはオルゴデミーラに攻撃した！\n",char_name);
			printf("オルゴデミーラに%dダメージ！\n",char_attack * 2 - enemy_defence);
			enemy_HP = enemy_HP - (char_attack * 2 - enemy_defence);
			break;
		case 2:
			printf("誰を回復？\n1 > %s\n 2 > naka-ma\n",char_name);
			scanf("%d",&command2);

			switch(command2){
				case 1:
					printf("%sの体力が%d回復した！\n",char_name,char_HP / 4);
					char_HP += char_HP / 4;
					break;
				case 2:
					printf("%sの体力が%d回復した！\n",nakama_name,nakama_HP / 4);
					nakama_HP += nakama_HP / 4;
					break;
		}	
	}
}

	if(enemy_HP <= 0){
		printf("%sたちはバトルに勝利した！\n",char_name);
		return 0;
	}
	if(nakama_HP > 0){
	int nakamapattern = GetRandom(1,100);

	if(nakamapattern < 30){
		printf("%sはオルゴデミーラに攻撃した！\n",nakama_name);
		printf("オルゴデミーラに%dダメージ！\n",nakama_attack * 2 - enemy_defence);
		enemy_HP = enemy_HP - (nakama_attack * 2 - enemy_defence);
	}else if(nakamapattern < 60){
		printf("%sは回復呪文を唱えた！\n",nakama_name);
		printf("%sの体力が%d回復した！\n",char_name,char_HP / 4);
		char_HP += char_HP / 4;
	}else{
		printf("%sは回復呪文を唱えた！\n",nakama_name);
		printf("%sの体力が%d回復した！\n",nakama_name,nakama_HP / 4);
		char_HP += char_HP / 4;
	}
}

	if(enemy_HP <= 0){
		printf("%sたちはバトルに勝利した！\n",char_name);
		return 0;
	}



	int enemypattern = GetRandom(1,100);
	if(enemypattern < 50){
		printf("オルゴデミーラは%sを攻撃した！\n",char_name);
		printf("%sに%dダメージ！\n",char_name,enemy_attack * 2 - char_defence);
		char_HP = char_HP - (enemy_attack * 2 - char_defence);
	}else{
		printf("オルゴデミーラは%sを攻撃した！\n",nakama_name);
		printf("%sに%dダメージ！\n",nakama_name,enemy_attack * 2 - nakama_defence);
		nakama_HP = nakama_HP - (enemy_attack * 2 - nakama_defence);
	}
	if(char_HP < 0 && nakama_HP < 0){
		printf("%sたちは全滅してしまった...\n",char_name);
		return 0;
	}

	
}


	return 0;
}