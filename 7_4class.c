#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void){
	int i;
	char s[] = "Hello!";
	printf("%s\n",s);
	for(i = strlen(s)-1;i>=0;i--){
		printf("%c",s[i]);
	}
	printf("\n");

	int a[10][10];
	int j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			printf("a[%d][%d]のアドレスは%p\n",j,i,&a[j][i]);
		}
	}

	char str[10][11],tmp[11];i=0;
	for(i=0;i<10;i++){
		sprintf(tmp,"No.%2d\n",i);
		strcpy(str[i],tmp);
	}
	for(i=0;i<10;i++){
		printf("%s",str[i]);
	}
	return 0;
}
