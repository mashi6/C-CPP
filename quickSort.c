#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

const int length = 50;
int Array[length]={};

void sortReady(int []);
void quickSort(int,int,int,int,int);
void change(int *,int *);
int max(int,int);
int min(int,int);

void sortReady(int Array []){
	quickSort(Array[0],0,length - 1,0,length - 1);
}

void quickSort(int stem,int top,int bottom,int highLocation,int lowLocation){//軸,上限,下限,現在地(上),現在地(下)

	while(1){
		while(highLocation < bottom){
			if(stem <= Array[highLocation]){//軸以上の値にぶつかるまで進む
				break;
			}
			highLocation++;
		}

		while(lowLocation > top){
			if(stem > Array[lowLocation]){//軸未満の値に当たるまで進む
				break;
			}
			lowLocation--;
		}

		if(highLocation == bottom){//一番下に行くまで軸より小さい値が見つからなかった
			highLocation--;//１つずらして
			break;//分割
		}else if(lowLocation == top){//一番上に行くまで軸より大きい値が見つからなかった
			lowLocation++;//１つずらして
			break;//分割
		}else if(top == bottom){//探索対象が１つのみ(その分割域でのソート完了)
			break;//(終了)
		}else if(highLocation+1==lowLocation){//要交換 & 要分割
			change(&Array[highLocation],&Array[lowLocation]);
			break;
		}else if(highLocation>lowLocation){//片方は軸(未満or以上)が見つかったが、片方は見つからなかった(分割位置調整 -> 分割)
			int a = highLocation;//highLocation <-> lowLocation
			highLocation = lowLocation;
			lowLocation = a;
			break;
		}else{//一般的にはここにあたる。
			change(&Array[highLocation],&Array[lowLocation]);//交換してさらに探索を進める
		}
	}

	if(top == bottom){//探索対象が１つのみ
	//終了
}else{//分割して再帰
		quickSort(Array[top],top,highLocation,top,highLocation);
		quickSort(Array[lowLocation],lowLocation,bottom,lowLocation,bottom);
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

int main(void){
	srand( (int)time(NULL) );

	for(int i=0;i<length;i++){//ランダムな数列を生成
		Array[i] = rand();
		printf("%d\n",Array[i]);
	}
	printf("\n");

	sortReady(Array);

	for(int i=0;i<length;i++){//結果
		printf("%d\n",Array[i]);
	}

	return 0;
}
