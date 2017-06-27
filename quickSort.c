#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>

const int length = 50;
int Array[length]={};
clock_t start,end;

void change(int *,int *);
void quickSort(int,int,int,int,int);
void bubbleSort(void);
int max(int,int);
int min(int,int);
void times(void);

void quickSort(int stem,int top,int bottom,int highLocation,int lowLocation){

	while(1){

		while(1){
			if(highLocation == lowLocation){//重なろうとしている時
				highLocation = lowLocation - 1;
				break;
			}
			if(stem <= Array[highLocation]){
				break;
			}
			highLocation++;
		}

		while(1){
			if(highLocation == lowLocation){
				lowLocation = highLocation + 1;
				break;
			}
			if(stem > Array[lowLocation]){
				break;
			}
			lowLocation--;
		}

		if(highLocation+1==lowLocation){//重なろうとしている時
			if(Array[highLocation] > Array[lowLocation]){
				change(&Array[highLocation],&Array[lowLocation]);
			}
			break;
		}else{
			change(&Array[highLocation],&Array[lowLocation]);
		}

	}

	if(top == bottom){
	}else{
		quickSort(Array[top],top,highLocation,top,highLocation);
		quickSort(Array[lowLocation],lowLocation,bottom,lowLocation,bottom);
	}

}

void bubbleSort(){
	for(int i=0;i<length;i++){
		for(int t=0;t<length - 1;t++){
			int a = max(Array[t],Array[t+1]);
			Array[t] = min(Array[t],Array[t+1]);
			Array[t+1] = a;
		}
	}
}

void selectionSort(){
	int a = INT_MAX;
	int a_num = 0;

	for(int i=0;i<length;i++){
		for(int t=i;t<length;t++){
			if(a > Array[t]){
				a  = Array[t];
				a_num = t;
			}
		}
		change(&Array[i],&Array[a_num]);
		a = INT_MAX;
	}
}

void change(int *a,int *b){
	int x = *a;
	int y = *b;

	*a = y;
	*b = x;
}

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

void times(void){
	start = clock();
	bubbleSort();
	end = clock();

	printf("BubbleSort    : %fsec\n",(double)(end-start)/CLOCKS_PER_SEC);
	for(int i = 0;i < length;i++){
		Array[i] = rand();
		// printf("%d\n",Array[i]);
	}

	start = clock();
	selectionSort();
	end = clock();

	printf("SelectionSort : %fsec\n",(double)(end-start)/CLOCKS_PER_SEC);
	for(int i = 0;i < length;i++){
		Array[i] = rand();
		// printf("%d\n",Array[i]);
	}

	start = clock();
	quickSort(Array[0],0,length-1,0,length-1);
	end = clock();

	printf("QuickSort     : %fsec\n",(double)(end-start)/CLOCKS_PER_SEC);
}

int main(void){
	srand( (int)time(NULL) );

	for(int i = 0;i < length;i++){
		Array[i] = rand();
		printf("%d\n",Array[i]);
	}
	printf("\n");

	quickSort(Array[0],0,length-1,0,length-1);

	for(int i = 0;i < length;i++){
		printf("%d\n",Array[i]);
	}


	return 0;
}
