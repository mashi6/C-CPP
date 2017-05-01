#include<stdio.h>

int main(void){
	double r;
	double pi = 3.1415;
	printf("半径を入力>> ");
	scanf("%lf",&r);
	
	printf("面積:%0lfです\n", pi * pi * r);
	printf("円周:%0lfです\n", 2 * pi * r);

	printf("面積:%5lfです\n", pi * pi * r);
	printf("円周:%5lfです\n", 2 * pi * r);

	printf("面積:%15lfです\n", pi * pi * r);
	printf("円周:%15lfです\n", 2 * pi * r);

	printf("面積:%-5lfです\n", pi * pi * r);
	printf("円周:%-5lfです\n", 2 * pi * r);

	printf("面積:%-15lfです\n", pi * pi * r);
	printf("円周:%-15lfです\n", 2 * pi * r);

	return 0;
}
