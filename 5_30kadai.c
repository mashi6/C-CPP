#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
double Pythagorean(int a,int b){
	return sqrt(pow(a,2)+pow(b,2));
}

int main(int argc char **argv){
	srandom( (unsigned)time(NULL) );
	double pi;
	double totalPi=0;
	int inCircle=0,outCircle=0;
	long long int x,y;
	for(int t = 0;t<1000;t++){
		inCircle = 0;
		outCircle = 0;

	for (int i=0;i<=100000;i++){
		x = (random()*random())%100000000;

		y = (random()*random())%100000000;

		if (Pythagorean(x,y)<100000000.0){
			inCircle++;

		}else{
			outCircle++;

		}
}

	// printf("in : out = %d : %d\n",inCircle,outCircle);
	pi = (double)(4.0*(double)(inCircle))/(double)(inCircle+outCircle);
	totalPi+=pi;
	// printf("pi : %f\n",pi);
}
	printf("Average pi : %f\n",totalPi/1000.0);

	return 0;
}
