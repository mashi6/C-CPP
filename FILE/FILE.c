#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
	srand((int) time(NULL));
	int i;
	int mathPoint[40]={0};
	int engPoint[40]={0};
	int engAll=0;
	int mathAll=0;
	FILE *math,*eng,*score;
	score = fopen("score.txt","w+");
	math = fopen("Mathmatics.txt","w");
	eng = fopen("English.txt","w");

	if(score==NULL||math==NULL||eng==NULL){
		printf("ファイルの読み込みに失敗。\n");
		fclose(score);
		fclose(eng);
		fclose(math);
		exit(-1);
	}

	for(i=0;i<40;i++){
		fprintf(score,"%d\t%d\n",rand()%101+1,rand()%101+1);
	}

	rewind(score);

	for(i=0;i<40;i++){
		if(fscanf(score,"%d",&engPoint[i])!=1){
			printf("データの読み込みに失敗\n");
			fclose(score);
			fclose(eng);
			fclose(math);
			exit(-1);
		}
		if(fscanf(score,"%d",&mathPoint[i])!=1){
			printf("データの読み込みに失敗\n");
			fclose(score);
			fclose(eng);
			fclose(math);
			exit(-1);
		}
	}

	for(i=0;i<40;i++){
		engAll+=engPoint[i];
		mathAll+=mathPoint[i];
	}

	fprintf(score,"average\n");
	fprintf(score,"%d\t%d\n",engAll/40,mathAll/40);

	for(i=0;i<40;i++){
		fprintf(eng,"%d\n",engPoint[i] - engAll/40);
		fprintf(math,"%d\n",mathPoint[i] - mathAll/40);
	}

	fclose(score);
	fclose(eng);
	fclose(math);

	return 0;
}
