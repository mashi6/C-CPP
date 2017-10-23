#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int a[101];
int b[101];
int answer[101];
int hissan(int x){
	if(x==101){
		return 0;
	}
	int c;
	c=a[x]+b[x]+hissan(x+1);
	answer[x]=c%10;
	return c/10;
}
int main(void){
	char input[101];
	int inputNum=0,j=0;
	for(int i=0;i<101;i++){
		a[i]=0;
		b[i]=0;
		answer[i]=0;
	}
	scanf("%s",input);
	inputNum=strlen(input);
	for(int i=0;i<inputNum;i++){
		//a[101-inputNum+i]=atoi(input[i]); atoiの引数が文字のため正常に動作しない
		a[101-inputNum+i]=input[i]-'0';// 改善
	}
	scanf("%s",input);
	inputNum=strlen(input);
	for(int i=0;i<inputNum;i++){
		// b[101-inputNUm+i]=atoi(input[i]); 上記
		b[101-inputNum+i]=input[i]-'0';// 改善
	}
	hissan(0);
	for(j=0;j<101;j++){
		if(answer[j]!=0)break;

	}
	for(j;j<101;j++){
		printf("%d",answer[j]);
	}
	printf("\n");
	return 0;
}
