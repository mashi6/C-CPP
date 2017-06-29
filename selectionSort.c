#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

void selectionSort(int Array[]){
	int a = INT_MAX;//一番初めの a > Array[t] を必ず満たすように。
	int a_num = 0;

	for(int i=0;i<50;i++){//i:挿入する配列の添え字(前から順に取っていく)
		for(int t=i;t<50;t++){//すでに挿入したところはソートにかけなくていいので t=i
			if(a > Array[t]){//一番小さい値を探していく
				a  = Array[t];//(どんどん上書き)
				a_num = t;//暫定一番小さいであろう値の添え字(保存しておかないと交換するときに交換先がわからなくなる)
			}
		}
		int x = Array[a_num];//交換
		Array[a_num] = Array[i];
		Array[i] = x;
		a = INT_MAX;
	}
	for(int i =0;i<50;i++){
		printf("%d\n",Array[i]);
	}
}

int main(void){
	srand((int)time(NULL));
	int Array[50];

	for(int i=0;i<50;i++){
		Array[i] = rand();
	}

	selectionSort(Array);

	return 0;
}
