#include<stdio.h>

int main(){
	int a,b,c,d;
	int kakudo1,kakudo2;

	printf("辺aを入力\n>>");
	scanf("%d",&a);
	printf("\n辺bを入力\n>>");
	scanf("%d",&b);
	printf("\n辺cを入力\n>>");
	scanf("%d",&c);
	printf("\n辺dを入力\n>>");
	scanf("%d",&d);
	printf("\n角度1を入力\n>>");
	scanf("%d",&kakudo1);
	printf("\n角度2を入力\n>>");
	scanf("%d",&kakudo2);

	if((((a==c)||((b==d)))&&((kakudo1==kakudo2) || (kakudo1 + kakudo2 == 180)))){
		printf("四角形は蹬脚台形である\n");
	}else{
		printf("四角形は蹬脚台形でない\n");
	}

	printf("-----------\n");

	if(a==c||b==d&&kakudo1==kakudo2||kakudo1 + kakudo2 == 180){
		printf("四角形は蹬脚台形である\n");
	}else{
		printf("四角形は蹬脚台形でない\n");
	}

	return 0;
}
