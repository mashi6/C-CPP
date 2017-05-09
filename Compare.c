/*
macOS Sierra 10.12.4
x86_64-apple-darwin 16.5.0
gcc 4.2.1
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int const True = 1;

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

int getRandom(int min,int max){
	return rand()% (max-min) + min;
}

int main(void){
	srand( (int)time(NULL) );

	char str_1[101][10]={{'\0'}},str_2[101][10]={{'\0'}};

	char cmp_1[101]={'\0'},cmp_2[101]={'\0'};

	int strNumMin = 3;
	int strNumMax = 99;

	int AsciiMin = 65;
	int AsciiMax = 122;

	int AsciiNumber;

	int strNumRandom;

	for(int t = 0;t <= 9;t++){
		strNumRandom = getRandom(strNumMin,strNumMax);

		for(int i = 0;i < strNumRandom;i++){
			AsciiNumber = getRandomASCII(AsciiMin,AsciiMax);
			char AsciiRandom = AsciiNumber;

			str_1[i][t] = AsciiRandom;

		}
	}

	for(int t = 0;t <= 9;t++){
		strNumRandom = getRandom(strNumMin,strNumMax);

		for(int i = 0;i < strNumRandom;i++){
			AsciiNumber = getRandomASCII(AsciiMin,AsciiMax);
			char AsciiRandom = AsciiNumber;

			str_2[i][t] = AsciiRandom;
		}
	}

	for (int t= 0;t <= 9;t++){
		int i = 0;

		while(True){
			cmp_1[i] = str_1[i][t];
			if(cmp_1[i] == '\0'){break;}
			i++;
		}

		i = 0;
		while(True){
			cmp_2[i] = str_2[i][t];
			if(cmp_2[i] == '\0'){break;}
			i++;
		}

		printf("compare [");

		for(int i = 0 ;i <= strlen(cmp_1) - 1; i++){
			printf("%c",cmp_1[i]);
		}

		printf("] with [");

		for(int i = 0 ;i <= strlen(cmp_2) - 1; i++){
			printf("%c",cmp_2[i]);
		}

		printf("] : %d <-> %d\n",strcmp(cmp_1,cmp_2),strcmp(cmp_2,cmp_1));

	}
}
