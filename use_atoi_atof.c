/*
macOS Sierra 10.12.4
x86_64-apple-darwin 16.5.0
gcc 4.2.1
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	char a[10];

	strcpy(a,"0414.9000");

	printf("atoi : %d\n",atoi(a));
	printf("atof : %f\n",atof(a));
}
