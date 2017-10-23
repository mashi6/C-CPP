#include<stdio.h>
#include<stdlib.h>

int main(void){
	
	char A = 'a';
	int A_ascii = A;

	printf("%c\n",A); //  a
	printf("%c\n",A_ascii);//  a

	printf("%d\n",A);//  97
	printf("%d\n",A_ascii);//  97
	return 0;
}