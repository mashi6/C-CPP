#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(void);

FILE *fp;

char searchName[100];
char name[100][100]={{'\0'}};
long long int number[100];
int AllNumber;

void Read(void){
	int j=0;
	while(1){

		printf("電話番号を調べたい人の名前を入力してください.\n>>");
		scanf("%s",searchName);

		for(j=0;j<100;j++){
			if(strcmp(searchName,name[j])==0){

				printf("氏名:%s  電話番号:%lld\n",name[j],number[j]);
				break;
			}
		}
		printf("\n");

	}
}

void Write(void){
	char command[10];
	char Target[100];
	int TargetNumber;

	while(1){

	printf("\n削除したい場合はremoveを\n追加したい場合はaddを\n一覧を見たい場合はlsを入力してください。\n\n");

	scanf("%s",command);

	int i=0;

	if(strcmp(command,"save")==0){
		sort();
		fclose(fp);
		fp=fopen("data.txt","w");
		for(int i=0;i<100;i++){
			if(name[i][0]=='\0'){

			}else{
				fprintf(fp,"%s\t%lld\n",name[i],number[i]);
			}
		}
		fclose(fp);
	}
	if(strcmp(command,"quit")==0){
		fclose(fp);
		exit(-1);
	}

	if(strcmp(command,"remove")==0){
		printf("対象の名前を入力してください。\n");
		scanf("%s",Target);
		for(i=0;i<100;i++){
			if(strcmp(Target,name[i])==0){
				break;
			}
		}
		if(i!=100){
			name[i][0]='\0';
			// strcpy(name[i],"");
			number[i]=NULL;
		}

	}
	if(strcmp(command,"add")==0){
		printf("対象の名前を入力してください。\n");
		scanf("%s",Target);
		for(i=0;i<100;i++){
			if(strcmp(Target,name[i])==0){
				printf("同名者がいます。");
				break;
			}

		}

		if(i==100){
			printf("電話番号を入力してください。\n");
			scanf("%d",&TargetNumber);

			strcpy(name[AllNumber],Target);
			number[AllNumber]=TargetNumber;
			AllNumber++;
		}

	}
	if(strcmp(command,"ls")==0){
		for(int i=0;i<AllNumber;i++){
			printf("氏名:%s 電話番号:%lld\n",name[i],number[i]);
		}

	}
}


}

void sort(void){
	for(int j=0;j<AllNumber-1;j++){
	for(int i=0;i<AllNumber-1;i++){
		char memo[100];
		int MEMO;

		strcpy(memo,name[i]);
		MEMO=number[i];
		if(strcmp(name[i],name[i+1])>0){
			strcpy(name[i],name[i+1]);
			number[i]=number[i+1];
			number[i+1]=MEMO;
			strcpy(name[i+1],memo);
		}
	}
}
}

int main(void){

	int i=0;


	fp=fopen("data.txt","r");

	for(i=0;i<100;i++){
		if(fscanf(fp,"%s",name[i])==-1){
			printf("読み取り終了。\n");
			break;
		}
		if(fscanf(fp,"%lld",&number[i])==-1){
			printf("読み取り終了。\n");
			break;
		}
	}

	AllNumber=i;

	printf("読み取った人数は%d人です。\n",i);
	sort();

	printf("Read or Write\n");
	char a ;
	a = getchar();

	if(a=='r'){
		Read();
	}else if(a=='w'){
		Write();
	}

	return 0;
}
