#include<stdio.h>
#include<math.h>

int main(void){
	double d;

	for(d = 0.0;d < 360;d+=1.0){
		printf("%.0lf\t%lf\n",d,cos(d * M_PI / 180));
	}
	for(d = 0.0;d < 360;d+=1.0){
		printf("%.0lf\t%lf\n",d,tan(d * M_PI / 180));
	}
	return 0;
}
