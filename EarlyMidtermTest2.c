// 変更点無し。
#include<stdio.h>
#include<stdlib.h>

int Phycowler(void){
	double a;
	a = 6.0*((float)rand()/((float)RAND_MAX + 1.0));
	if(0.0 <= a && a < 1.0){return 1;}
	if(1.0 <= a && a < 2.0){return 2;}
	if(2.0 <= a && a < 3.0){return 3;}
	if(3.0 <= a && a < 4.0){return 4;}
	if(4.0 <= a && a < 5.0){return 5;}
	if(5.0 <= a && a < 6.0){return 6;}
}

int main(void){
	int totalCount = 0,sixCount = 0,number = 0;
	srand(27);

	while(1){
		totalCount++;
		number = Phycowler();
		if(number == 6){
			sixCount++;
		}else{
			sixCount = 0;
		}
		if(sixCount == 3){
			printf("totalCount : %d回目\n",totalCount);
			break;
		}
	}

	return 0;
}
