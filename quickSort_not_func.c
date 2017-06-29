#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void){
	srand( (int)time(NULL) );

	const int length = 10000;
	int Array[length];
	int *highLocations;//queue
	int *lowLocations;//queue
	int count;//queue.push()を実現

	for(int i=0;i<length;i++){
		Array[i] = rand();
		printf("%d\n",Array[i]);
	}
	printf("\n");

	count = 0;
	highLocations = (int *)malloc(sizeof(int)*(count + 1));
	lowLocations = (int *)malloc(sizeof(int)*(count + 1));

	highLocations[count] = 0;
	lowLocations[count] = length - 1;

	int i = 0;//queue.front()を実現

	while(i <= count){//queueが無くなったら終了

		//queue(のような配列)から先頭(にあたる)要素を取り出す。
		int highLocation = highLocations[i];
		int lowLocation = lowLocations[i];
		int top = highLocation;
		int bottom = lowLocation;
		int stem = Array[highLocation];

		while(1){
			while(highLocation < bottom){
				if(stem <= Array[highLocation]){
					break;
				}
				highLocation++;
			}

			while(lowLocation > top){
				if(stem > Array[lowLocation]){
					break;
				}
				lowLocation--;
			}

			if(highLocation == bottom){
				highLocation--;
				break;
			}else if(lowLocation == top){
				lowLocation++;
				break;
			}else if(top == bottom){
				break;
			}else if(highLocation+1==lowLocation){
				int a = Array[highLocation];
				Array[highLocation] = Array[lowLocation];
				Array[lowLocation] = a;
				break;
			}else if(highLocation>lowLocation){
				int a = highLocation;
				highLocation = lowLocation;
				lowLocation = a;
				break;
			}else{
				int a = Array[highLocation];
				Array[highLocation] = Array[lowLocation];
				Array[lowLocation] = a;
			}

		}

		if(top == bottom){
		}else{//queue(のような配列)に要素を入れる。
			count++;
			highLocations = (int *)realloc(highLocations,sizeof(int)*(count + 1));
			lowLocations = (int *)realloc(lowLocations,sizeof(int)*(count + 1));

			highLocations[count] = top;
			lowLocations[count] = highLocation;

			count++;
			highLocations = (int *)realloc(highLocations,sizeof(int)*(count + 1));
			lowLocations = (int *)realloc(lowLocations,sizeof(int)*(count + 1));

			highLocations[count] = lowLocation;
			lowLocations[count] = bottom;

		}
		i++;//queue.pop()
	}

	free(highLocations);
	free(lowLocations);

	for(int i=0;i<50;i++){
		printf("%d\n",Array[i]);
	}
	return 0;
}
