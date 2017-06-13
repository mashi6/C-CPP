#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
	char a[1000]={'\0'},b[1000]={'\0'};

	while(1){
		printf("数aを入力\n >> ");
		scanf("%s",a);
		if(strlen(a)>4){
			printf("値が大きすぎる\n");
// 			break;
			continue;//改善コード
		}
		if(strcmp(a,"quit")){
		}else{
			break;
		}

		printf("数bを入力\n >> ");
		scanf("%s",b);
		if(atoi(b)==0){
// 			break;
			continue;//改善コード
		}
		if(strlen(b)>4){
			printf("値が大きすぎる\n");
// 			break;
			continue;//改善コード
		}
		if(strcmp(a,"quit")){
		}else{
			break;
		}

		printf("a / b = %d\n",atoi(a)/atoi(b));

// 		printf("a % b = %d\n",atoi(a)%atoi(b)); <-元のコード。%の出力ができていない。
		printf("a %% b = %d\n",atoi(a)%atoi(b));// <-改善コード

		printf("a / b = %8.2f\n",atof(a)/atof(b));

// 		以下、scanfが上書き代入だったので不要
// 		for(int i=0;i<1000;i++){
// 		a[i] = '\0';
// 		b[i] = '\0';
// 		}
	}
	return 0;
}
