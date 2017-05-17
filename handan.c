#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int const True=1;
char Seiza[100] ={'\0'};

int getRandomASCII(int min,int max){
	int x=91;
	while (True){
		x=(rand() % (max - min + 1)) + min;
		if(91 <= x){
			if(x <= 96){
				continue;
			}
		}
		break;
	 	}
	return x;
}

void getSeizaNumber(int month,int day){
	switch(month){
		case 1:
			if(day <= 19){
				strcpy(Seiza,"やぎ座");
			}else{
				strcpy(Seiza,"みずがめ座");
			}
			break;
		case 2:
			if(day <= 18){
				strcpy(Seiza,"みずがめ座");
			}else{
				strcpy(Seiza,"うお座");
			}
			break;
		case 3:
			if(day <= 20){
				strcpy(Seiza,"うお座");
			}else{
				strcpy(Seiza,"おひつじ座");
			}
			break;
		case 4:
			if(day <= 19){
				strcpy(Seiza,"おひつじ座");
			}else{
				strcpy(Seiza,"おうし座");
			}
			break;
		case 5:
			if(day <= 20){
				strcpy(Seiza,"おうし座");
			}else{
				strcpy(Seiza,"ふたご座");
			}
			break;
		case 6:
			if(day <= 21){
				strcpy(Seiza,"ふたご座");
			}else{
				strcpy(Seiza,"かに座");
			}
			break;
		case 7:
			if(day <= 22){
				strcpy(Seiza,"かに座");
			}else{
				strcpy(Seiza,"しし座");
			}
			break;
		case 8:
			if(day <= 22){
				strcpy(Seiza,"しし座");
			}else{
				strcpy(Seiza,"おとめ座");
			}
			break;
		case 9:
			if(day <= 22){
				strcpy(Seiza,"おとめ座");
			}else{
				strcpy(Seiza,"てんびん座");
			}
			break;
		case 10:
			if(day <= 23){
				strcpy(Seiza,"てんびん座");
			}else{
				strcpy(Seiza,"さそり座");
			}
			break;
		case 11:
			if(day <= 22){
				strcpy(Seiza,"さそり座");
			}else{
				strcpy(Seiza,"いて座");
			}
			break;
		case 12:
			if(day <= 21){
				strcpy(Seiza,"いて座");
			}else{
				strcpy(Seiza,"やぎ座");
			}
			break;
		default:;

	}
}

int main(void){
	srand( (int)time(NULL) );
	double month,day,c;
	int d;
	char str[101]={'\0'};

	int AsciiNumber=0;
	int AsciiMin = 65;
	int AsciiMax = 122;
	int SeizaNumber = 0;


	printf("誕生日は何月ですか？\n>>");
	scanf("%lf",&month);

	printf("誕生日は何日ですか？\n>>");
	scanf("%lf",&day);

	printf("今日の気分を0~100の数字で表すと？\n>>");
	scanf("%lf",&c);

	d = (int)((month + day + c - 2) / 141.0 * 100.0);

	getSeizaNumber((int)month,(int)day);

	for(int i = 0;i < d;i++){
		AsciiNumber = getRandomASCII(AsciiMin,AsciiMax);
		char AsciiRandom = AsciiNumber;

		str[i] = AsciiRandom;

	}
	printf("\nごめんなさい。今日最も運勢の悪いのは %sのあなた。\n中略\n",Seiza);
	printf("でも大丈夫！そんな %sのツキを回復させるラッキーアルファベット群は %sです！\n今日も1日頑張りましょう！\n",Seiza,str);
}
