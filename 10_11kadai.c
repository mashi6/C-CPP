#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Str{
	int memba1;
	int memba2;
	int memba3;
};
int main(void){
	srand((unsigned int)time(NULL));
	char Chars[10];
	int Ints[10];
	double Doubles[10];

	char *charPoint;
	int *intPoint;
	double *doublePoint;

	for(int i=0;i<10;i++){
		Chars[i] = rand() % 255;
		Ints[i] =  rand() % 10000000;
		Doubles[i] = (double)(rand() % 10000000);
	}

	for(int i=0;i<10;i++){
		charPoint = &Chars[i];
		printf("  char[%d]: point [%p]  value [%c]\n",i,charPoint,*charPoint);
	}
	printf("\n");
	for(int i=0;i<10;i++){
		intPoint = &Ints[i];
		printf("   int[%d]: point [%p]  value [%d]\n",i,intPoint,*intPoint);
	}
	printf("\n");
	for(int i=0;i<10;i++){
		doublePoint = &Doubles[i];
		printf("double[%d]: point [%p]  value [%lf]\n",i,doublePoint,*doublePoint);
	}
	printf("\n");


	struct Str strarray[10];

	for(int i=0;i<10;i++){
		printf("str[%d]: point [%p]\n",i,&strarray[i]);

		printf("   str[%d].memba1: point [%p]\n",i,&strarray[i].memba1);
		printf("   str[%d].memba2: point [%p]\n",i,&strarray[i].memba2);
		printf("   str[%d].memba3: point [%p]\n\n",i,&strarray[i].memba3);
	}

	int x = 0;
	int *xPoint = &x;
	for(int i=0;i<=100;i++){
		printf("*(x+%d): point [%p]  value [%d]\n",i,xPoint + i,*(xPoint + i));
	}
	return 0;
}