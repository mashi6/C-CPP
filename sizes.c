#include<stdio.h>

int main(void){
	char c;
	int i;
	long long int l;
	float f;
	double d;
	void *p;

	printf("char : %zubyte\n",sizeof(c));
	printf("int : %zubyte\n",sizeof(i));
	printf("long long int : %zubyte\n",sizeof(l));
	printf("float : %zubyte\n",sizeof(f));
	printf("double : %zubyte\n",sizeof(d));
	printf("pointer : %zubyte\n",sizeof(p));

	return(0);
}
