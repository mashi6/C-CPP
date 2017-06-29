#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int max(int x,int y){
	if(x > y){
		return x;
	}else{
		return y;
	}
}
int min(int x,int y){
	if(x<y){
		return x;
	}else{
		return y;
	}
}

void bubbleSort(int Array[]){
	//i:最悪、最小値がArray[49]にあると、50回交換しないといけない。
	for(int i=0;i<49;i++){
		for(int t=0;t<50 - 1;t++){//配列外参照しないように -1
			int a = max(Array[t],Array[t+1]);//小さい方を t へ　大きい方を t+1 へ
			Array[t] = min(Array[t],Array[t+1]);
			Array[t+1] = a;
		}
	}
	for(int i=0;i<50;i++){
		printf("%d\n",Array[i]);
	}

}

int main(void){
	srand((int)time(NULL));
	int Array[50];
	for(int i=0;i<50;i++){
		Array[i] = rand();
	}

	bubbleSort(Array);

	return 0;
}
