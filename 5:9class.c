#include<stdio.h>
#include<string.h>

int main(void){/*
	char s[30],t[30];
	int a,b;

	strcpy(s,"dazou");
	strcpy(t,"dazou");

	printf("s= %s\n",s);
	printf("t= %s\n",t);

	a = strlen(s);
	printf("sの長さ = %d\n",a);

	b = strcmp(s,t);
	printf("strcmpの結果 = %d\n",b);

	strcat(s,t);
	printf("s = %s\n",s);
	a = strlen(s);
	printf("sの長さ = %d\n",a);
*/

	char s[100];
	strcpy(s,"123456789");
	printf("%s\n",s);
	s[9] = 'a';
	printf("%s\n",s);

	return(0);
}
