#include<stdio.h>
#include<stdlib.h>

int riverceSearch(int x,int y,int k,int l);
void putStone(int x,int y,int l);

int map[8][8];//0 " " ,1 "◯" ,2 "●"
int check[8][8];
int put;//1 "◯" ,2 "●"

void print(void){
	printf("  ");

	for(int i=0;i<8;i++){
		printf("%d ",i);
	}
	printf("\n");
	for(int i=0;i<8;i++){
		printf("%d ",i);
		for(int j=0;j<8;j++){
			if(check[i][j]){
				printf("×");
			}else if(map[i][j]==0){
				printf(".");
			}else if(map[i][j]==1){
				printf("○");
			}else if(map[i][j]==2){
				printf("●");
			}
			printf(" ");
		}

		printf("\n");
	}
	printf("\n");
}

int search(int i,int j,int k,int l){//k = 0:１つ前が空白  1:１つ前が◯  2:１つ前が●  3:初手
								// 探索パターン l  = 1:上　2:右上 3:右 4:右下 5:下 6:左下 7:左 8:左上

	if(i<0||i>7||j<0||j>7){//オセロの盤外に出る
		return 0;//サーチ終了。置けない
	}
	if(k==0&&(map[i][j]==put)){//黒->黒　白->白　で置けない。
		return 0;//置けない
	}
	if(map[i][j]==0&&k!=3){//初手じゃなく、空白
		return 0;//置けない
	}
	if(map[i][j]&&k==3){//初手に石がある
		return 0;//置けない
	}
	if(map[i][j]==0&&k==0){//現在地が空白　１つ前も空白
		return 0;//置けない
	}
	if(put==1&&map[i][j]==1&&k==2){//黒を置く 現在地が黒　１つ前が白
		return 1;//置ける
	}
	if(put==2&&map[i][j]==2&&k==1){//白を置く 現在地が白　１つ前が黒
		return 1;//置ける
	}

	int now=map[i][j];//現在地の情報

	switch(l){
		case 1://上
			return search(i-1,j,now,l);//さらに上へ
			break;
		case 2://右上
			return search(i-1,j+1,now,l);//さらに右上へ
			break;
		case 3://..
			return search(i,j+1,now,l);//..
			break;
		case 4:
			return search(i+1,j+1,now,l);
			break;
		case 5:
			return search(i+1,j,now,l);
			break;
		case 6:
			return search(i+1,j-1,now,l);
			break;
		case 7:
			return search(i,j-1,now,l);
			break;
		case 8:
			return search(i-1,j-1,now,l);
			break;
	}
}

void riverce(int x,int y){//xタテ　yヨコ
	for(int l=1;l<9;l++){
		if(search(x,y,3,l)){//探索パターンがlの時置けるか。
			putStone(x,y,l);//始点x,yから探索パターンl方向に石を置く。
		}
	}
}

void putStone(int x,int y,int l){

	switch(l){
		case 1://上
			x--;
			while(map[x][y]==put%2+1){//違う色の石が出てくるまで石を置き続ける
				map[x][y]=put;
				x--;
			}
			break;
		case 2://右上
			x--;
			y++;
			while(map[x][y]==put%2+1){
				map[x][y]=put;
				x--;
				y++;
			}
			break;

		case 3://右
			y++;
			while(map[x][y]==put%2+1){
				map[x][y]=put;

				y++;
			}
			break;

		case 4://..
			x++;
			y++;
			while(map[x][y]==put%2+1){
				map[x][y]=put;

				x++;
				y++;
			}
			break;

		case 5:
			x++;
			while(map[x][y]==put%2+1){
				map[x][y]=put;

				x++;
			}
			break;

		case 6:
			y--;
			x++;
			while(map[x][y]==put%2+1){
				map[x][y]=put;
				y--;
				x++;
			}
			break;

		case 7:
			y--;
			while(map[x][y]==put%2+1){
				map[x][y]=put;

				y--;
			}
			break;

		case 8:
			y--;
			x--;
			while(map[x][y]==put%2+1){
				map[x][y]=put;
				y--;
				x--;
			}
			break;
	}
}

int main(void){
	int count =0;//何手目
	int checkCount=0;//置ける場所の数

	for(int i=0;i<8;i++){//初期化
		for(int j=0;j<8;j++){
			map[i][j]=0;
			check[i][j]=0;
		}
	}

	map[3][4]=1;//初期化
	map[4][3]=1;

	map[3][3]=2;
	map[4][4]=2;

	print();

	printf("先攻は白/黒どっちですか。 w/b\n");
	char a;
	a=getchar();

	if(a=='w'){
		put = 2;//white
	}else{
		put = 1;//black
	}


	while(1){
		system("clear");

		checkCount=0;

		if(count==65){//65手目...終了
			int white=0;
			int black=0;
			for(int i=0;i<8;i++){
				for(int j=0;j<8;j++){
					if(map[i][j]==2){
						white++;
					}else if(map[i][j]==1){
						black++;
					}
				}
			}
			system("clear");
			print();
			printf("[結果]　白:%d    黒:%d\n",white,black);
			if(black<white){
				printf("白の勝ちです。\n");
			}else if(black>white){
				printf("黒の勝ちです。\n");
			}else{
				printf("同点です。\n");
			}
			break;
		}

		count++;
		for(int i=0;i<8;i++){//縦軸
			for(int j=0;j<8;j++){//横軸
				for(int l=1;l<9;l++){//探索ルート8パターン
					if(check[i][j]==1){
						//そこに置けることがわかっている。
					}else{
						if(search(i,j,3,l)){//そこに置けるか？-> return Yes:1  No:0
							check[i][j]=1;
							checkCount++;
						}
					}
				}
			}
		}

		if(checkCount==0){//詰みなので次の人へ
			printf("置き場所がありません。パスします。\n");
			put = put%2+1;//先攻後攻 交代
			continue;
		}

		if(count%2!=0){
			printf("[先攻] ");
			if(put==2){
				printf("●\n");
			}else{
				printf("◯\n");
			}
		}else{
			printf("[後攻] ");
			if(put==1){
				printf("◯\n");
			}else{
				printf("●\n");
			}
		}

		print();

		while(1){//入力。間違った文字を入れても入れ直させるために無限ループ
			printf("タテ,ヨコ\n0~7 ,0~7  で入力してください。\n");
			int x;
			int y;
			scanf("%d,%d",&x,&y);

			if(check[x][y]){//そこに置けるかどうか
				for(int i=0;i<8;i++){//初期化
					for(int j=0;j<8;j++){
						check[i][j]=0;
					}
				}
				riverce(x,y);//石を点(x,y)に置いて裏返す。(x,y)にはまだ置かない。
				map[x][y]=put;//ここで(x,y)に石を置く。(諸都合)
				break;//入力から脱出。
			}else{
				printf("置けません。\n");
			}
		}
		put = put%2+1;//先攻後攻 交代
	}

	printf("Thanks for playing.");
	return 0;
}
