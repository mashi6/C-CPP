#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
const int Enemy = 0;
const int Ally = 1;

const int superRare = 0;
const int veryRare = 1;
const int Rare = 2;
const int normal = 3;
const int dontmind = 4;
const int black = 0;
const int white = 1;
const int red = 2;
const int yellow = 3;
const int cyan = 4;
const int blue = 5;
const int green = 6;
const int bold = 7;
const int underlining = 8;

struct EnemyStatus{
	char name[25];
	int hitPoint;
	int attack;
	int defence;
	int speed;
	int IQ;
};
struct AllyStatus{
	char name[25];
	int hitPoint;
	int attack;
	int defence;
	int speed;
	int level;
	int IQ;
	int rarity;
};
struct Row{
	char margin1[20];
	char AllyHP[10];
	char margin2;
	char Allyname[25];
	char margin3[60];
	char Enemyname[25];
	char margin4;
	char EnemyHP[10];
	char margin5[20];
};
struct BattleField{
	struct Row row[5];
};
struct Sorted{
	int isAlly;
	int number;
};
struct textColor{
	int textColor;
	int backgroundColor;
};
struct rowColor{
	struct textColor AllyHP;
	struct textColor AllyName;
	struct textColor EnemyHP;
	struct textColor EnemyName;
};

int GetRandom(int,int);
int max(int,int);
int min(int,int);
void printStatus(struct AllyStatus);
void textColor_is(int);
void backgroundColor_is(int);
void printField(void);
void setupField(void);
void printLog(void);
void checkLog(void);
void clearLog(void);
void singleAttack(int,int);
void Bless(int,int);
void Heal(int,int);
void Guard(int,int);
void Rivival(int,int);
void Kobushi(int);
void KobushiAttack(int,int,int);
void die(int,int);
void checkFinish(int);
void attackedEffect(int,int);
void guardedEffect(int,int);
void healedEffect(int);
void rivivaledEffect(int);
void kobushiEffect(int);
void dieEffect(int,int);
void HPcheck(int,int);


char difficulty;
	
struct EnemyStatus Enemies[5];
struct AllyStatus jurengacha[10];
struct AllyStatus useCharactars[3];

struct BattleField Field;
struct rowColor FieldColor[5];

int isWhiling = 1;
int selected[10]={};
int canselect = 0;
int charnumber = 0;
int enemynumber = 0;

char Allynames[47][25];
char Enemynames[50][25];
int AllynameSelected[47]={};
int EnemynameSelected[50]={};

int AllyHP[3]={};
int EnemyHP[5]={};

char commands[4][50];

char Log[30][100];
int logrowCount=0;

int Max;
unsigned long int fieldlength;

int charorders[3];  //0..ガンガンいこうぜ 1..いろいろやろうぜ 2..いのちだいじに 3..こぶしでていこう

struct Sorted sorted[20];
int isSorted[20]={};

int kobushi[5]={};

int logrowBorder = 0;



int GetRandom(int min,int max){
	return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

int max(int x,int y){
	if (x > y){
		return x;
	}else{
		return y;
	}
}
int min(int x,int y){
	if(x < y){
		return x;
	}else{
		return y;
	}
}

void printStatus(struct AllyStatus charactar){
		printf("\n");
	 	switch(charactar.rarity){
	 		case superRare:
	 			printf("\x1b[41m");
	 			printf("---------[SuperRare]---------");
	 			break;
	 		case veryRare:
	 			printf("\x1b[33m");
	 			printf("----------[VeryRare]---------");
	 			break;
	 		case Rare:
	 			printf("\x1b[36m");
	 			printf("------------[Rare]-----------");
	 			break;
	 		case normal:
	 			printf("-----------[Normal]----------");
	 			break;
	 		case dontmind:
	 			printf("\x1b[37m");
	 			printf("----------[Dont mind]--------");

	 	}

 		printf("\x1b[49m\x1b[39m\x1b[0m");
 		printf("\n%s\n",charactar.name);

 		printf("　　　　　体力 : ");
 		if(charactar.hitPoint > 85){
 			printf("\x1b[31m");
 		}else if(charactar.hitPoint < 70){
 			printf("\x1b[36m");
 		}
 		printf("%d /100\n",charactar.hitPoint);
 		printf("\x1b[39m\x1b[0m");

 		printf("　　　　攻撃力 : ");
 		if(charactar.attack > 25){
 			printf("\x1b[31m");
 		}else if (charactar.attack < 15){
 			printf("\x1b[36m");
 		}
 		printf("%d /30\n",charactar.attack);
 		printf("\x1b[39m\x1b[0m");

 		printf("　　　　防御力 : ");
 		if(charactar.defence > 25){
 			printf("\x1b[31m");
 		}else if(charactar.defence < 15){
 			printf("\x1b[36m");
 		}
 		printf("%d /30\n",charactar.defence);
 		printf("\x1b[39m\x1b[0m");

 		printf("　　　　素早さ : ");
 		if(charactar.speed > 25){
 			printf("\x1b[31m");
 		}else if(charactar.speed < 15){
 			printf("\x1b[36m");
 		}
 		printf("%d /30\n",charactar.speed);
 		printf("\x1b[39m\x1b[0m");

 		printf("　　　　　賢さ : ");
 		if(charactar.IQ > 85){
 			printf("\x1b[31m");
 		}else if(charactar.IQ < 20){
 			printf("\x1b[36m");
 		}
 		printf("%d /100\n",charactar.IQ);
 		printf("\x1b[39m\x1b[0m");

 		printf("\x1b[39m\x1b[0m");

 		switch(charactar.rarity){
 			case superRare:
 				printf("\x1b[41m");
 				break;
 			case veryRare:
 				printf("\x1b[33m");
 				break;
 			case Rare:
 				printf("\x1b[36m");
 				break;
 			case normal:
 				break;
 			case dontmind:
 				printf("\x1b[37m");

 		}

 		printf("-----------------------------");
 		printf("\x1b[49m\x1b[39m\x1b[0m");
 		printf("\n");
}


void textColor_is(int color){
	switch(color){
		case black:
			printf("\x1b[30m");
			break;
		case white:
			printf("\x1b[39m");
			break;
		case red:
			printf("\x1b[31m");
			break;
		case yellow:
			printf("\x1b[33m");
			break;
		case cyan:
			printf("\x1b[36m");
			break;
		case blue:
			printf("\x1b[34m");
			break;
		case green:
			printf("\x1b[32m");
			break;
		case bold:
			printf("\x1b[1m");
			break;
		case underlining:
			printf("\x1b[4m");
			break;
	}
}
void backgroundColor_is(int color){
	switch(color){
		case black:
			printf("\x1b[40m");
			break;
		case red:
			printf("\x1b[41m");
			break;
		case yellow:
			printf("\x1b[43m");
			break;
		case cyan:
			printf("\x1b[46m");
			break;
		case blue:
			printf("\x1b[44m");
			break;
		case green:
			printf("\x1b[42m");
			break;
	}
}

void printField(void){
	system("clear");
	setupField();
	printf("┏");
	for(int i=0;i<fieldlength;i++){
		printf("━");
	} 
	printf("┓\n");
	for(int i=0;i<Max;i++){
		printf("┃");
		printf("%s",Field.row[i].margin1);

		textColor_is(FieldColor[i].AllyHP.textColor);
		backgroundColor_is(FieldColor[i].AllyHP.backgroundColor);
		printf("%s\x1b[49m\x1b[39m\x1b[0m",Field.row[i].AllyHP);
		printf("%c",Field.row[i].margin2);

		textColor_is(FieldColor[i].AllyName.textColor);
		backgroundColor_is(FieldColor[i].AllyName.backgroundColor);
		printf("%s\x1b[49m\x1b[39m\x1b[0m",Field.row[i].Allyname);
		printf("%s",Field.row[i].margin3);

		textColor_is(FieldColor[i].EnemyName.textColor);
		backgroundColor_is(FieldColor[i].EnemyName.backgroundColor);
		printf("%s\x1b[49m\x1b[39m\x1b[0m",Field.row[i].Enemyname);
		printf("%c",Field.row[i].margin4);

		textColor_is(FieldColor[i].EnemyHP.textColor);
		backgroundColor_is(FieldColor[i].EnemyHP.backgroundColor);
		printf("%s\x1b[49m\x1b[39m\x1b[0m",Field.row[i].EnemyHP);
		printf("%s",Field.row[i].margin5);
		printf("┃");
		printf("\n");
	}
	printf("┗");
	for(int i=0;i<fieldlength;i++){
		printf("━");
	}
	printf("┛\n");
}

void setupField(void){
	for(int i=0;i<Max;i++){//margin,HP 初期化
		strcpy(Field.row[i].margin1,"     ");
		Field.row[i].margin2 = ' ';
		Field.row[i].margin4 = ' ';
		strcpy(Field.row[i].margin5,"     ");
		if(i < charnumber){
			sprintf(Field.row[i].AllyHP,"%d/%d",AllyHP[i],useCharactars[i].hitPoint);
		}
		int count = 5;
		for(int j=strlen(Field.row[i].AllyHP);j<=7;j++){
			Field.row[i].margin1[count] = ' ';
			Field.row[i].margin1[count+1] = '\0';
			count++;
		}

		if(i < enemynumber){
			sprintf(Field.row[i].EnemyHP,"%d/%d",EnemyHP[i],Enemies[i].hitPoint);
		}
		count = 5;
		for(int j=strlen(Field.row[i].EnemyHP);j<=7;j++){
			Field.row[i].margin5[count] = ' ';
			Field.row[i].margin5[count+1] = '\0';
			count ++;
		}

	}

	for(int i=0;i<Max;i++){//Name,margin　初期化

		if(i < charnumber){
			strcpy(Field.row[i].Allyname,useCharactars[i].name);
		}

		if(i < enemynumber){
			strcpy(Field.row[i].Enemyname,Enemies[i].name);
		}
		int count = 0;

		for(int j=(strlen(Field.row[i].Enemyname) + strlen(Field.row[i].Allyname) )* 2 / 3;j<=34;j++){
				Field.row[i].margin3[count] = '\x0020';
				Field.row[i].margin3[count+1] = '\0';
				count++;
		}

	}

	fieldlength = strlen(Field.row[0].margin1);
	fieldlength += strlen(Field.row[0].AllyHP);
	fieldlength += strlen(Field.row[0].Allyname)*2/3;
	fieldlength += strlen(Field.row[0].margin3);
	fieldlength += strlen(Field.row[0].Enemyname)*2/3;
	fieldlength += strlen(Field.row[0].EnemyHP);
	fieldlength += strlen(Field.row[0].margin5);
	fieldlength += 2;
}

void printLog(void){
	checkLog();
	for(int i=0;i<logrowCount;i++){
		printf("%s",Log[i]);
	}
}

void checkLog(void){
	while(logrowCount>logrowBorder){
		for(int i=0;i<logrowCount-1;i++){
			strcpy(Log[i],Log[i+1]);
		}
		logrowCount--;
	}
}

void clearLog(void){
	for(int i=0;i<logrowCount;i++){
		strcpy(Log[i],"");
	}
	logrowCount = 0;
}

void singleAttack(int isAlly,int from){
	int minHP=100000;
	int who;

	if(isAlly){
		for(int i=0;i<enemynumber;i++){
			if(EnemyHP[i] == 0)continue;
			if(minHP != min(minHP,EnemyHP[i])){
				minHP = EnemyHP[i];
				who = i;
			}
		}
		int rand = GetRandom(1,100);
		if(rand > useCharactars[from].IQ){
			who = GetRandom(1,enemynumber) - 1;
		}

		int damage = useCharactars[from].attack * 20 / Enemies[who].defence;
		usleep(500000);
		sprintf(Log[logrowCount],"%s のこうげき！\n",useCharactars[from].name);
		logrowCount++;

		printField();
		printLog();
		system("afplay \"attackSound1.mp3\" &");

		usleep(300000);
		sprintf(Log[logrowCount],"　　%s に%dダメージ！\n",Enemies[who].name,damage);
		logrowCount++;
		printField();
		printLog();

		usleep(300000);
		if(EnemyHP[who] == 0){
			attackedEffect(0,who);
			FieldColor[who].EnemyHP.textColor = green;
			FieldColor[who].EnemyName.textColor = green;
			// die(0,who);
			sprintf(Log[logrowCount],"　　%sはもう死んでいる！\n",Enemies[who].name);
			logrowCount ++;
			printField();
			printLog();

			usleep(700000);
			sprintf(Log[logrowCount],"　　死体蹴りだ！！卑怯者！！\n");
			logrowCount ++;
			printField();
			printLog();
			usleep(700000);
		}else{
			EnemyHP[who] -= damage;
			if(EnemyHP[who] < 0){
				EnemyHP[who] = 0;
			
			}

			attackedEffect(0,who);

			printField();
			printLog();
			if(EnemyHP[who] == 0){
				die(0,who);
			}
		}


	}else{
		for(int i=0;i<charnumber;i++){
			if(AllyHP[i] == 0)continue;

			if(minHP != min(minHP,AllyHP[i])){
				minHP = AllyHP[i];
				who = i;
			}
		}
		int rand = GetRandom(1,100);
		if(rand > Enemies[from].IQ){
			who = GetRandom(1,charnumber) - 1;
		}

		int damage = Enemies[from].attack * 20 / useCharactars[who].defence;
		usleep(500000);
		sprintf(Log[logrowCount],"%s のこうげき！\n",Enemies[from].name);
		logrowCount++;

		printField();
		printLog();
		system("afplay \"attackSound1.mp3\" &");
		
		usleep(300000);
		sprintf(Log[logrowCount],"　　%s に%dダメージ！\n",useCharactars[who].name,damage);
		printField();
		printLog();
		logrowCount++;

		usleep(300000);
		if(AllyHP[who] == 0){
			attackedEffect(1,who);
			FieldColor[who].AllyHP.textColor = green;
			FieldColor[who].AllyName.textColor = green;

			sprintf(Log[logrowCount],"　　%sはもう死んでいる！\n",useCharactars[who].name);
			logrowCount ++;
			printField();
			printLog();

			usleep(700000);
			sprintf(Log[logrowCount],"　　死体蹴りだ！！卑怯者！！\n");
			logrowCount ++;
			printField();
			printLog();
			usleep(700000);

		}else{
			AllyHP[who] -= damage;
			if(AllyHP[who] < 0){
				AllyHP[who] = 0;
			}

			attackedEffect(1,who);
		
			printField();
			printLog();
			if(AllyHP[who] == 0){
				die(1,who);
			}else if (kobushi[who]){
				KobushiAttack(damage,who,from);
			}
		}
	}
}

void Bless(int isAlly,int who){
	if(isAlly){
		usleep(500000);
		sprintf(Log[logrowCount],"%s はブレスをはなった！\n",useCharactars[who].name);
		logrowCount ++;
		printField();
		printLog();
		system("afplay \"attackSound1.mp3\" &");

		for(int i=0;i<enemynumber;i++){
			if(EnemyHP[i]==0)continue;
			int damage = useCharactars[who].attack * 20 / Enemies[i].defence / enemynumber;
			usleep(300000);
			sprintf(Log[logrowCount],"　　%s に%dダメージ！\n",Enemies[i].name,damage);
			logrowCount ++;
			printField();
			printLog();
			
			EnemyHP[i] -= damage;
			if(EnemyHP[i] < 0){
				EnemyHP[i] = 0;
			}
			usleep(300000);

			attackedEffect(0,i);

			if(EnemyHP[i] == 0){
				die(0,i);
			}

		}
	}else{
		usleep(500000);
		sprintf(Log[logrowCount],"%s はブレスをはなった！\n",Enemies[who].name);
		logrowCount ++;
		printField();
		printLog();
		system("afplay \"attackSound1.mp3\" &");

		for(int i=0;i<charnumber;i++){
			if(AllyHP[i] == 0)continue;

			int damage = (((Enemies[who].attack * 20) / useCharactars[i].defence) / charnumber);
			usleep(300000);
			sprintf(Log[logrowCount],"　　%s に%dダメージ！\n",useCharactars[i].name,damage);
			logrowCount ++;
			printField();
			printLog();

			AllyHP[i] -= damage;
			if(AllyHP[i] < 0){
				AllyHP[i] = 0;
			}
			usleep(300000);

			attackedEffect(1,i);

			if(AllyHP[i] == 0){
				die(1,i);
			}else if(kobushi[i]){
				KobushiAttack(damage,i,who);
			}
		}
	}
}

void Heal(int from,int to){
	usleep(500000);
	sprintf(Log[logrowCount],"%s は回復魔法をとなえた！\n",useCharactars[from].name);
	logrowCount ++;
	printField();
	printLog();

	int heal = useCharactars[to].hitPoint * useCharactars[from].IQ / 200;
	usleep(300000);
	sprintf(Log[logrowCount],"　　%s の体力が%d回復！\n",useCharactars[to].name,heal);
	logrowCount ++;
	printField();
	printLog();

	AllyHP[to] += heal;
	if(AllyHP[to] > useCharactars[to].hitPoint){
		AllyHP[to] = useCharactars[to].hitPoint;
	}
	usleep(300000);
	healedEffect(to);
}

void Guard(int isAlly,int from){
	if(isAlly){
		usleep(500000);
		sprintf(Log[logrowCount],"%s はまもりをかためた！\n",useCharactars[from].name);
		logrowCount ++;
		printField();
		printLog();

		usleep(300000);
		sprintf(Log[logrowCount],"　　%s の防御力があがった！\n",useCharactars[from].name);
		logrowCount ++;
		printField();
		printLog();

		useCharactars[from].defence = useCharactars[from].defence * 120 / 100;

		usleep(300000);

		guardedEffect(1,from);

	}else{
		usleep(500000);
		sprintf(Log[logrowCount],"%s はまもりをかためた！\n",Enemies[from].name);
		logrowCount ++;
		printField();
		printLog();

		usleep(300000);
		sprintf(Log[logrowCount],"　　%s の防御力があがった！\n",Enemies[from].name);
		logrowCount ++;
		printField();
		printLog();

		Enemies[from].defence = Enemies[from].defence * 120 / 100;
		usleep(300000);

		guardedEffect(0,from);
	}
}

void Rivival(int from,int to){
	usleep(500000);
	sprintf(Log[logrowCount],"%s は復活の魔法をとなえた！\n",useCharactars[from].name);
	logrowCount ++;
	printField();
	printLog();

	usleep(300000);
	sprintf(Log[logrowCount],"　　%sが復活した！\n",useCharactars[to].name);
	logrowCount ++;
	printField();
	printLog();

	AllyHP[to] = useCharactars[to].hitPoint / 2;

	usleep(300000);

	rivivaledEffect(to);
}

void Kobushi(int who){
	usleep(500000);
	sprintf(Log[logrowCount],"%s は拳で抵抗している...\n",useCharactars[who].name);
	logrowCount ++;
	printField();
	printLog();

	kobushi[who] = 1;
	usleep(300000);
	//ここアニメーション？
	kobushiEffect(who);
}

void KobushiAttack(int damage,int from,int to){
	kobushi[from] = 0;

	usleep(500000);
	sprintf(Log[logrowCount],"　　%s は拳で抵抗した！\n",useCharactars[from].name);
	logrowCount ++;
	printField();
	printLog();
	system("afplay -v 2 \"kobushiSound1.mp3\"");


	int attackdamage = damage * 200 / useCharactars[from].hitPoint;
	usleep(300000);
	sprintf(Log[logrowCount],"　　　　%s に%dダメージ！\n",Enemies[to].name,attackdamage);
	logrowCount ++;
	printField();
	printLog();
	system("afplay -v 2 \"kobushiSound2.mp3\"");

	EnemyHP[to] -= attackdamage;
	if(EnemyHP[to] < 0){
		EnemyHP[to] = 0;
	}

	// usleep(300000);

	attackedEffect(0,to);

	if(EnemyHP[to] == 0){
		die(0,to);
	}
}

void die(int isAlly,int who){
	if(isAlly){

		kobushi[who] = 0;
		usleep(300000);
		sprintf(Log[logrowCount],"　　%s は力尽きた\n",useCharactars[who].name);
		dieEffect(1,who);
		logrowCount ++;
		printField();
		printLog();

		usleep(300000);

		checkFinish(1);
	}else{

		usleep(300000);
		sprintf(Log[logrowCount],"　　%s をたおした\n",Enemies[who].name);
		dieEffect(0,who);
		logrowCount ++;
		printField();
		printLog();

		usleep(300000);
		
		checkFinish(0);
	}
}

void checkFinish(int isAlly){

	if(isAlly){
		for(int i=0;i<charnumber;i++){
			if(AllyHP[i] != 0){
				return;
			}
		}
		system("stty echo -icanon min 1 time 0");
		system("killall afplay");
		system("afplay \"gameover.mp3\" &");
		char gameover[8] = "Game Ove";
		for(int i=0;i<8;i++){
			usleep(350000);
			printf("%c",gameover[i]);
			fflush(stdout);
		}
		usleep(250000);
		printf("ｒ\n");
		exit(-1);

	}else{
		for(int i=0;i<enemynumber;i++){
			if(EnemyHP[i] != 0){
				return;
			}
		}
		system("stty echo -icanon min 1 time 0");
		system("killall afplay");
		system("afplay \"gameclear.mp3\" &");
		char gameclear[9] = "Game Clea";
		for(int i=0;i<9;i++){
			usleep(250000);
			printf("%c",gameclear[i]);
			fflush(stdout);
		}
		usleep(250000);
		printf("ｒ\n");
		exit(-1);
	}
}

void attackedEffect(int isAlly,int attacked){

	system("afplay \"attackSound2.mp3\" &");
	if(isAlly){
		FieldColor[attacked].AllyName.textColor = red;
		FieldColor[attacked].AllyHP.textColor = red;
		printField();
		printLog();
		usleep(150000);
		FieldColor[attacked].AllyName.backgroundColor = red;
		FieldColor[attacked].AllyHP.backgroundColor = red;
		printField();
		printLog();
		usleep(150000);
		FieldColor[attacked].AllyName.textColor = white;
		FieldColor[attacked].AllyHP.textColor = white;
		printField();
		printLog();
		usleep(150000);
		FieldColor[attacked].AllyName.backgroundColor = black;
		FieldColor[attacked].AllyHP.backgroundColor = black;
		printField();
		printLog();
		usleep(150000);
		HPcheck(1,attacked);
	}else{
		FieldColor[attacked].EnemyName.textColor = red;
		FieldColor[attacked].EnemyHP.textColor = red;
		printField();
		printLog();
		usleep(150000);
		FieldColor[attacked].EnemyName.backgroundColor = red;
		FieldColor[attacked].EnemyHP.backgroundColor = red;
		printField();
		printLog();
		usleep(150000);
		FieldColor[attacked].EnemyName.textColor = white;
		FieldColor[attacked].EnemyHP.textColor = white;
		printField();
		printLog();
		usleep(150000);
		FieldColor[attacked].EnemyName.backgroundColor = black;
		FieldColor[attacked].EnemyHP.backgroundColor = black;
		printField();
		printLog();
		usleep(150000);
		HPcheck(0,attacked);
	}

}
void guardedEffect(int isAlly,int guarded){
	system("afplay \"healguardSound.mp3\" &");
	if(isAlly){
		FieldColor[guarded].AllyName.backgroundColor = cyan;
		printField();
		printLog();
		usleep(250000);
		FieldColor[guarded].AllyName.backgroundColor = black;
		printField();
		printLog();
		usleep(250000);
		FieldColor[guarded].AllyName.backgroundColor = cyan;
		printField();
		printLog();
		usleep(250000);
		FieldColor[guarded].AllyName.backgroundColor = black;
		printField();
		printLog();
		usleep(250000);
	}else{
		FieldColor[guarded].EnemyName.backgroundColor = cyan;
		printField();
		printLog();
		usleep(250000);
		FieldColor[guarded].EnemyName.backgroundColor = black;
		printField();
		printLog();
		usleep(250000);
		FieldColor[guarded].EnemyName.backgroundColor = cyan;
		printField();
		printLog();
		usleep(250000);
		FieldColor[guarded].EnemyName.backgroundColor = black;
		printField();
		printLog();
		usleep(250000);
	}
}
void healedEffect(int healed){
	system("afplay \"healguardSound.mp3\" &");
	FieldColor[healed].AllyHP.textColor = cyan;
	printField();
	printLog();
	usleep(250000);
	FieldColor[healed].AllyHP.backgroundColor = cyan;
	printField();
	printLog();
	usleep(250000);
	FieldColor[healed].AllyHP.textColor = white;
	printField();
	printLog();
	usleep(250000);
	FieldColor[healed].AllyHP.backgroundColor = black;
	printField();
	printLog();
	usleep(250000);
}
void rivivaledEffect(int rivivaled){
	system("afplay \"rivivalSound.mp3\" &");
	FieldColor[rivivaled].AllyHP.textColor = cyan;
	FieldColor[rivivaled].AllyName.textColor = cyan;
	printField();
	printLog();
	usleep(250000);
	FieldColor[rivivaled].AllyHP.backgroundColor = cyan;
	FieldColor[rivivaled].AllyName.backgroundColor = cyan;
	printField();
	printLog();
	usleep(250000);
	FieldColor[rivivaled].AllyHP.textColor = white;
	FieldColor[rivivaled].AllyName.textColor = white;
	printField();
	printLog();
	usleep(250000);
	FieldColor[rivivaled].AllyHP.backgroundColor = black;
	FieldColor[rivivaled].AllyName.backgroundColor = black;
	printField();
	printLog();
	usleep(250000);
}
void kobushiEffect(int who){
	FieldColor[who].AllyName.textColor = bold;
}
void dieEffect(int isAlly,int who){
	if(isAlly){
		FieldColor[who].AllyName.textColor = green;
		FieldColor[who].AllyHP.textColor = green;
		printField();
		printLog();
	}else{
		FieldColor[who].EnemyName.textColor = green;
		FieldColor[who].EnemyHP.textColor = green;
		printField();
		printLog();
	}
}

void HPcheck(int isAlly,int who){
	if(isAlly){
		int HPpercent = AllyHP[who] * 100 / useCharactars[who].hitPoint;
		if(HPpercent <= 30 && HPpercent > 0){
			FieldColor[who].AllyHP.textColor = red;
		}
	}else{
		int HPpercent = EnemyHP[who] * 100 / Enemies[who].hitPoint;
		if(HPpercent <= 30 && HPpercent > 0){
			FieldColor[who].EnemyHP.textColor = red;
		}
	}
}

int main(void){
	system("stty -echo -icanon min 1 time 0");
	system("clear");
	FILE *fpAllyname;
	FILE *fpEnemyname;

//名前の一覧ファイルを読み込み
	fpAllyname = fopen("Allyname.txt","r");
	fpEnemyname = fopen("Enemyname.txt","r");

	if(fpAllyname == NULL || fpEnemyname == NULL){
		printf("couldnt open textfile\n");
		system("stty -echo -icanon min 1 time 0");
		return 0;
	}
	for(int i=0;i<47;i++){
		char input[25];
		fscanf(fpAllyname,"%s",input);
		strcpy(Allynames[i],input);

		AllynameSelected[i] = 0;
	}
	for(int i=0;i<50;i++){
		char input[25];
		fscanf(fpEnemyname,"%s",input);
		strcpy(Enemynames[i],input);

		EnemynameSelected[i] = 0;
	}
// 	ここから
	unsigned int seed = abs(Allynames[1][1]);
	srand(seed);
//	ここまでfilehead.c

	fclose(fpAllyname);
	fclose(fpEnemyname);
//読み込み終了 

//設定等
	char enter;
	printf("テキストカラーは　白　\nバックグラウンドカラーは　黒　でプレイしてください\n\n>> Enter");
	scanf("%c",&enter);
	system("clear");
	printf("ウィンドウサイズは若干大きめに\n\n>> Enter");
	scanf("%c",&enter);
	system("clear");
	printf("移動は  W\n　　　 SDF  キーでお願いします\n\n>> Enter");
	scanf("%c",&enter);
	system("clear");
	printf("音が出ます...\n\n>> Enter");
	scanf("%c",&enter);
	system("clear");
	printf("それでは、RPGの世界へいざないましょう(課題だけど)(Enter押さないで！)");
	fflush(stdout);
	sleep(1);
	printf(".");
	fflush(stdout);
	sleep(1);
	printf(".");
	fflush(stdout);
	sleep(1);
	printf(".");
	fflush(stdout);
	sleep(1);

	system("clear");
	system("afplay \"Opening.mp3\" &");

	char op[23] = "Drag●n Quest ~II E~ ";
	for(int i=0;i<strlen(op);i++){
		usleep(500000);
		printf("%c",op[i]);
		fflush(stdout);
	}
	usleep(500000);
	printf("課");
	fflush(stdout);
	usleep(500000);
	printf("題");
	fflush(stdout);
	usleep(500000);
	printf("編");
	fflush(stdout);

	usleep(500000);
	printf("  (");
	fflush(stdout);
	usleep(300000);
	printf("こ");
	fflush(stdout);	
	usleep(300000);
	printf("こ");
	fflush(stdout);
	usleep(300000);
	printf("だ");
	fflush(stdout);
	usleep(300000);
	printf("け");
	fflush(stdout);
	usleep(300000);
	printf("凝");
	fflush(stdout);
	usleep(300000);
	printf("り");
	fflush(stdout);
	usleep(300000);
	printf("ま");
	fflush(stdout);
	usleep(300000);
	printf("し");
	fflush(stdout);
	usleep(300000);
	printf("た");
	fflush(stdout);
	usleep(300000);
	printf(")");
	fflush(stdout);
	printf("\n\n\n\n\n\n>> Enter");
	
	scanf("%c",&enter);
	system("killall afplay");
	system("clear");
	while(isWhiling){
		printf("バトルモード選択\nI: 1 vs 1    II: 2 vs 2    III: 3 vs 3\n");
		scanf("%c",&difficulty);
		if(difficulty - '0' > 0 && difficulty - '0' < 4){
			isWhiling = 0;
			system("afplay \"selectSound.mp3\" &");
		}else{
			printf("もう一度入力してください\n");
		}
	}
	switch(difficulty - '0'){
		case 1:
			canselect = 1;
			charnumber = 1;
			break;
		case 2:
			canselect = 2;
			charnumber = 2;
			break;
		case 3:
			canselect = 3;
			charnumber = 3;
	}
//設定終了

	system("clear");
	printf("初回限定　無料10連ガチャ!!(唐突だけど)\n");
	printf("引く >> Enter\n");
	char input;
	scanf("%c",&input);
	system("afplay \"selectSound.mp3\" &");

	for(int i=0;i<10;i++){
		struct AllyStatus charactar;

		while(1){
			int num = GetRandom(1,47);
			if(AllynameSelected[num-1]){
			}else{
				strcpy(charactar.name,Allynames[num-1]);
				AllynameSelected[num-1] = 1;
				break;
			}
		}

		charactar.hitPoint = GetRandom(50,100);
		charactar.attack = GetRandom(10,30);
		charactar.defence = GetRandom(10,30);
		charactar.speed = GetRandom(10,30);
		charactar.IQ = GetRandom(40,100);
		charactar.level = 1;
		

		int rarityCount = 0;
		if(charactar.hitPoint > 85){
			rarityCount ++;
		}else if(charactar.hitPoint < 70){
			rarityCount --;
		}
		if(charactar.attack > 25){
			rarityCount ++;
		}else if(charactar.attack < 15){
			rarityCount --;
		}
		if(charactar.defence > 25){
			rarityCount ++;
		}else if(charactar.defence < 15){
			rarityCount --;
		}
		if(charactar.speed > 25){
			rarityCount ++;
		}else if(charactar.speed < 15){
			rarityCount --;
		}
		if(charactar.IQ > 85){
			rarityCount ++;
		}else if(charactar.IQ < 60){
			rarityCount --;
		}

		if(rarityCount >= 3){
			charactar.rarity = superRare;
		}else if(rarityCount >= 2){
			charactar.rarity = veryRare;
		}else if(rarityCount >= 1){
			charactar.rarity = Rare;
		}else if(rarityCount == 0){
			charactar.rarity = normal;
		}else{
			charactar.rarity = dontmind;
		}

		jurengacha[i] = charactar;
	}


	for(int i=0;i<10;i++){
		
		system("clear");
		printf("%d\n",i+1);
		printStatus(jurengacha[i]);
		usleep(500000);
	}

	int cardCount = 0;
	
	while(1){
		system("clear");
		if(cardCount != 0){
			printf("   ↑\n ");
		}else{
			printf("\n ");
		}
		if(selected[cardCount]){
			printf("\x1b[41m%d枚目\x1b[49m",cardCount+1);
		}else{
			printf("%d枚目",cardCount+1);
		}
		printf("\n");
		if(cardCount != 9){
			printf("   ↓\n");
		}else{
			printf("\n");
		}
		printStatus(jurengacha[cardCount]);
		if(canselect == 0){
				break;
		}

		printf("\n上下に移動して仲間にするキャラクターをあと%d人選んでください >> Enter\n",canselect);
		char input;
		scanf("%c",&input);
		
		switch(input){
			case 'e':
				if(cardCount > 0)cardCount --;
				break;
			case 'd':
				if(cardCount < 9)cardCount ++;
				break;
			case '\n':
				system("afplay \"selectSound.mp3\" &");
				if(selected[cardCount]){
					selected[cardCount] = 0;
					canselect ++;
				}else{
					selected[cardCount] = 1;
					canselect --;
								
					break;
				}
		}
	}

	int count = 0;
	for(int i=0;i<10;i++){
		if(selected[i]){
			useCharactars[count] = jurengacha[i];
			count ++;
		}
	}

	printf("\n\n");
	for(int i=0;i<charnumber;i++){
		printf("%s\n",useCharactars[i].name);
		AllyHP[i] = useCharactars[i].hitPoint;
	}
	printf("が仲間になった！\n");
	system("afplay \"levelup.mp3\"");

	switch(difficulty - '0'){
		case 1:
			canselect = 1;
			enemynumber = 1;
			break;
		case 2:
			canselect = 2;
			enemynumber = 2;
			break;
		case 3:
			canselect = 3;
			enemynumber = 3;
			break;
		default :
			printf("default\n");
	}

	Max = max(charnumber,enemynumber);
	for(int i=0;i<enemynumber;i++){
		struct EnemyStatus enemy;
		while(1){
			int num = GetRandom(1,50);

			if(EnemynameSelected[num-1]){
			}else{
				strcpy(enemy.name,Enemynames[num-1]);
				EnemynameSelected[num-1] = 1;
				break;
			}
		}
		enemy.hitPoint = GetRandom(100,180);
		enemy.attack = GetRandom(20,40);
		enemy.defence = GetRandom(10,20);
		enemy.speed = GetRandom(10,30);
		enemy.IQ = GetRandom(1,100);
		Enemies[i] = enemy;
		EnemyHP[i] = enemy.hitPoint;
	}

// setup battle field

	strcpy(commands[0],"ガンガンいこうぜ");
	strcpy(commands[1],"いろいろやろうぜ");
	strcpy(commands[2],"いのちだいじに");
	strcpy(commands[3],"こぶしでていこう");

	for(int i=0;i<5;i++){
		FieldColor[i].AllyHP.textColor = white;
		FieldColor[i].AllyName.textColor = white;
		FieldColor[i].EnemyHP.textColor = white;
		FieldColor[i].EnemyName.textColor = white;
		FieldColor[i].AllyHP.backgroundColor = black;
		FieldColor[i].AllyName.backgroundColor = black;
		FieldColor[i].EnemyHP.backgroundColor = black;
		FieldColor[i].EnemyName.backgroundColor = black;
		
	}
	

	for(int i=0;i<charnumber + enemynumber;i++){
		// if(isSorted[i])continue;
		int maxspeed = 0;
		struct Sorted who;

		for(int j=0;j<charnumber + enemynumber;j++){
			if(isSorted[j])continue;
			if(j < charnumber){
				if(maxspeed != max(maxspeed,useCharactars[j].speed)){
					maxspeed = useCharactars[j].speed;
					who.isAlly = 1;
					who.number = j;
				}
			}else{
				if(maxspeed != max(maxspeed,Enemies[j-charnumber].speed)){
					maxspeed = Enemies[j-charnumber].speed;
					who.isAlly = 0;
					who.number = j;
				}
			}
		}
		sorted[i]  = who;
		isSorted[who.number] = 1;
	}

	printf("\n\nラスボスたちが襲いかかってきた！！\n");
	usleep(2000000);

// 	命令を選ぶ
	// system("while :; do afplay \"battle.mp3\"; done &");
	// system("VAR=$!");
	system("afplay \"battle.mp3\" &");
	while(1){
		clearLog();
		logrowBorder = 20;
	for(int i=0;i<charnumber;i++){
		if(AllyHP[i] == 0)continue;
		if(kobushi[i]){
			sprintf(Log[logrowCount],"\n%s は拳に集中している...\n",useCharactars[i].name);
			logrowCount++;
			printField();
			printLog();

			charorders[i] = -1;
			continue;
		}

		int canchoice = 0;
		int nowchoice = 0;
		if(useCharactars[i].IQ >= 90 && useCharactars[i].attack >= 25){
			canchoice = 4;
		}else{
			canchoice = 3;
		}

		char input;
		isWhiling = 1;
		while(isWhiling){
			// system("clear");
			sprintf(Log[logrowCount],"\n%s はどうする\n",useCharactars[i].name);

			logrowCount++;

			for(int j=0;j<canchoice;j++){
				if(nowchoice == j){
					sprintf(Log[logrowCount],"▶︎ %s\n",commands[j]);
				}else{
					sprintf(Log[logrowCount],"  %s\n",commands[j]);
				}
				logrowCount ++;
			}

			printField();
			printLog();
			while(1){
				scanf("%c",&input);
				
				if(input == 'd' && nowchoice < canchoice-1){
					nowchoice ++;
					logrowCount = logrowCount - canchoice - 1;
					break;
				}
				if(input == 'e' && nowchoice > 0){
					nowchoice --;
					logrowCount = logrowCount - canchoice - 1;
					break;
				}
				if(input == '\n'){
					system("afplay \"selectSound.mp3\" &");
					isWhiling = 0;
					charorders[i] = nowchoice;
					break;
				}
			}
		}
	}
// 命令を選ぶ

// バトルの準備
	//素早さ順にソート Ally.1 .2 .3  Enemy.1 .2 .3
	clearLog();
	logrowBorder = 4;

	for(int i=0;i<charnumber + enemynumber;i++){
		int now = sorted[i].number;
		if(now < charnumber){//ally
			if(AllyHP[now] == 0)continue;
			FieldColor[now].AllyName.textColor = underlining;
			int minHP = 100000;
			int who;
			int HPpercent=100;
			switch(charorders[now]){
				case 0://ガンガン
					singleAttack(1,now);
					break;
				case 1://いろいろ
					for(int i=0;i<enemynumber;i++){
						if(EnemyHP[i] == 0)continue;
						if(minHP != min(minHP,EnemyHP[i])){
							minHP = EnemyHP[i];
							who = i;
						}
					}

					int rand = GetRandom(1,100);
					if(useCharactars[now].attack / enemynumber * 20 / Enemies[who].defence >= minHP){
						if(rand < useCharactars[now].IQ){
							Bless(1,now);
						}else{
							singleAttack(1,now);
						}
					}else{
						if(rand < useCharactars[now].IQ){
							singleAttack(1,now);
						}else{
							Bless(1,now);
						}
					}
					break;
				case 2://いのち
					if(useCharactars[now].IQ < 60){
						Guard(1,now);
					}else{
						for(int i=0;i<charnumber;i++){
							if(HPpercent > AllyHP[i]*100/useCharactars[i].hitPoint){
								HPpercent = AllyHP[i]*100/useCharactars[i].hitPoint;
								who = i;
							}
						}
						if(HPpercent == 0 && useCharactars[now].IQ >= 80){
							Rivival(now,who);
						}else if(HPpercent < 75 && 0 < HPpercent){
							Heal(now,who);
						}else{
							Guard(1,now);
						}
						// if(minHP == 0 && )
					}
					break;
				case 3://こぶし
					Kobushi(now);
					break;
				default :
					break;
			}
			if(FieldColor[now].AllyName.textColor != green && FieldColor[now].AllyName.textColor != bold){
				FieldColor[now].AllyName.textColor = white;
			}

		}else{//enemy
			now = now - charnumber;
			int minHP = 1000000;
			int who;
			if(EnemyHP[now] == 0)continue;
			FieldColor[now].EnemyName.textColor = underlining;
			int Rand = GetRandom(1,100);
			if(EnemyHP[now] * 100 / Enemies[now].hitPoint < 50 && Rand < 50){
				Guard(0,now);
			}else{
				for(int i=0;i<charnumber;i++){
					if(AllyHP[i] == 0)continue;
					if(minHP != min(minHP,AllyHP[i])){
						minHP = AllyHP[i];
						who = i;
					}
				}

				int rand = GetRandom(1,100);
				if(Enemies[now].attack * 20 / useCharactars[who].defence / charnumber >= minHP){
					if(rand < Enemies[now].IQ){
						Bless(0,now);
					}else{
						singleAttack(0,now);
					}
				}else{
					if(rand < Enemies[now].IQ){
						singleAttack(0,now);
					}else{
						Bless(0,now);
					}
				}
			}
			if(FieldColor[now].EnemyName.textColor != green && FieldColor[now].EnemyName.textColor != bold){
				FieldColor[now].EnemyName.textColor = white;
			}
		}
		usleep(300000);
	}
}


	system("stty echo -icanon min 1 time 0");
	return 0;
}