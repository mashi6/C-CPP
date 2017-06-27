#include<stdio.h>

int main (void){

	int a[10];
	printf("a[-1] = \n",a[-1]);
	a[10] = 100;
	printf("a[10] = %d\n",a[10]);

	// printf("a[]")
	// printf("a[-1]address = %p\n",&a[-1]);
	// printf("a[10]address = %p\n",&a[10]);






	/*
	int a[100];
	char b[100];
	double c[100];
*/


	for(int i = -1;i <= 10;i++){

			printf("a[%d] : %p  \n",i,&a[i]);
			// printf("b[i] : %p  ",&b[i]);
			// printf("c[i] : %p\n",&c[i]);
	}

	return 0;
}
