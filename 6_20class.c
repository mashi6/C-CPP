#include<stdio.h>
#include<math.h>

void first(void);
void second(void);
void third(void);
void test1(void);
void test2(void);

int fib(int);
int g;



int main(void){
	int i= 0;
	printf("%d\n",i);
	i++;

	printf("%d\n",fib(20));


	return 0;
}




void first(void){
		double d;
		for(d = 0.0;d < 360;d+=1.0){
			printf("%.0lf\t%lf\n",d,sin(d * M_PI / 180.0));
		}
}

void second(void){
	int i;
	for(i =0;i < 100;i++){
		int x;
		x = i*3;
		printf("%d\n",x);
	}

	// printf("%d\n",x);
}

void third(void){
	g = 514;
	printf("main g = %d\n",g);
	test1();
	test2();
	printf("main g = %d\n\n\n",g);

}
void test1()
{
	printf("test1 g = %d\n",g);
	g = 614;
}

void test2(){
	printf("test2 g = %d\n",g);
	g = 1224;
}

int fib(int x){
	if(x == 0){
		return 1;
	}
	if(x == 1){
		return 1;
	}


	return fib(x-1) + fib(x-2);
}
