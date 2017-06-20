#include<stdio.h>

long long int numbers[10000000] = {0};

long long int fib(long long int x){
	if(numbers[x] != 0){
		return numbers[x];
	}

	if(x == 0){
		// printf("%lld\n",numbers[0]);
		return 0;
	}

	if(x == 1){
		numbers[1] = 1;
		// printf("%lld\n",numbers[1]);
		return 1;
	}

	numbers[x] = fib(x-2) + fib(x-1);
	// printf("%lld\n",numbers[x]);
	return numbers[x];
}

int main(void){
	numbers[0] = 0;

	fib(1000000);

	long long int first = 0;
	long long int second = 1;
	long long int third ;

	// printf("%lld\n",first);
	// printf("%lld\n",second);

/*
	for(int i=2;i<=1000000;i++){
		third = first + second;
		// printf("%lld\n",third);
		first = second;
		second = third;
	}
*/

	return 0;
}
