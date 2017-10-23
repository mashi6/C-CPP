#include<stdio.h>

int main(void){
	FILE *fp;
	char c;
	int count = 0;
	int cCount　 =　0;

	fp=fopen("subtask_1_05.txt","r");
	
	while(1){
		// a=fgetc(fp); aが未定義
		char a=fgetc(fp); //改善
		cCount++;
		if(a=='\n'){
			count++;
		}
		if(a==EOF){
			cCount--;
			break;
		}
	}
	count ++;
	printf("行数 %d バイト数 %d\n",count,cCount);
	fclose(fp);
	return 0;
}
