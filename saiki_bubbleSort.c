#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int is_sorted(int[],int);

void sort(int list[]){
	int num = 50;	// 要素数

	for(int i=0;i<num - 1;i++){	//要素数-1回　くり返す
		if(list[i] > list[i+1]){	//入れ替える必要があるならば。。。
			int big = list[i];
			int small = list[i+1];
			list[i+1] = big;
			list[i] = small;
		}
	}

	if(is_sorted(list,num)){//ソートできていれば。。。
	}else{
		sort(list);
	}
}

int is_sorted(int list[],int num){
	for(int i=0;i<num-1;i++){
		if(list[i] > list[i+1]){
			return 0;//偽
		}
	}
	return 1;//真
}

int main(){
	srand((int)time(NULL));
	int List[50];
	for(int i=0;i<50;i++){
		List[i] = rand();	//ランダムな数列を用意
	}

	sort(List);
	for(int i=0;i<50;i++){
		printf("%d\n",List[i]);
	}
	return 0;
}
