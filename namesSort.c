#include<stdio.h>
#include<string.h>

char names[10][1000]={{'\0'}};

void sortReady();
void quickSort(int,int,int,int,int);
void change(int,int);

void sortReady(){
	quickSort(0,0,9,0,9);
}

void quickSort(int stem,int top,int bottom,int highLocation,int lowLocation){//軸,上限,下限,現在地(上),現在地(下)

	while(1){
		while(highLocation < bottom){
			if(strcmp(names[stem],names[highLocation]) <= 0){//軸以上の値にぶつかるまで進む...文字コード的に軸より小さい値にぶつかるまで進む。
				break;
			}
			highLocation++;
		}

		while(lowLocation > top){
			if(strcmp(names[stem],names[lowLocation]) > 0){//軸未満の値に当たるまで進む
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
			change(highLocation,lowLocation);
			break;
		}else if(highLocation>lowLocation){//片方は軸(未満or以上)が見つかったが、片方は見つからなかった(分割位置調整 -> 分割)
			int a = highLocation;//highLocation <-> lowLocation
			highLocation = lowLocation;
			lowLocation = a;
			break;
		}else{//一般的にはここにあたる。
			change(highLocation,lowLocation);//交換してさらに探索を進める
		}
	}

	if(top == bottom){//探索対象が１つのみ
	//終了
	}else{//分割して再帰
		quickSort(top,top,highLocation,top,highLocation);
		quickSort(lowLocation,lowLocation,bottom,lowLocation,bottom);
	}
}

void change(int a,int b){
	char x[1000];
	char y[1000];
	strcpy(x,names[a]);
	strcpy(y,names[b]);
	strcpy(names[a],y);
	strcpy(names[b],x);

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
	strcpy(names[0],"たなかたろう01");
	strcpy(names[1],"たなかたろう03");
	strcpy(names[2],"たなかたろう08");
	strcpy(names[3],"たなかたろう02");
	strcpy(names[4],"たなかたろう06");
	strcpy(names[5],"たなかたろう05");
	strcpy(names[6],"たなかたろう09");
	strcpy(names[7],"たなかたろう04");
	strcpy(names[8],"たなかたろう10");
	strcpy(names[9],"たなかたろう07");

	for(int i=0;i<10;i++){//結果
		printf("%s\n",names[i]);
	}
	sortReady();
	
	printf("\n");
	for(int i=0;i<10;i++){//結果
		printf("%s\n",names[i]);
	}
	return 0;
}
