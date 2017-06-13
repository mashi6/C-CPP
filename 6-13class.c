#include<stdio.h>

void graph(int);
int fib(int);

// int Booln[10000]={0};
int Num[10000]={0};

int main(void){
	int i=0;
	printf("ともやんの強さ\n");

	printf("攻撃力 : ");
	for(i = 0;i<15;i++){
		printf("*");
	}
	printf("\n");

	printf("防御力 : ");
	for(i=0;i<12;i++){
		printf("*");
	}
	printf("\n");

	printf("素早さ : ");
	for(i = 0;i<19;i++){
		printf("*");
	}
	printf("\n\n\n");
	printf("関数を使うと。\n");

	printf("ともやんの強さ\n");

	printf("攻撃力 : ");
	graph(fib(8));

	printf("防御力 : ");
	graph(fib(9));

	printf("素早さ : ");
	graph(fib(10));

	// printf("%d",fib(15));

	return 0;

}

void graph(int x){
	int i;

	for(i = 0;i < x; i++){
		printf("*");
	}
	printf("\n");
	return;
}

int fib(int x){
	if (Num[x]){
		return Num[x];
	}
	if (x == 0){
		Num[x]=0;
		return 0;
	}
	if (x <= 2){
		Num[x] = 1;
		return 1;
	}
	Num[x] = fib(x-1) + fib(x-2);
	return Num[x];
}

int fib2(int x){

	if (x == 0){

		return 0;
	}
	if (x <= 2){

		return 1;
	}
	return fib(x-1) + fib(x-2);

}
