//GUIプログラミング~時計~


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

const int X = 100;
const int Y = 100;
int main(){
	
	char clock[200][200];

	int h,m,s,y,month,d;
	time_t tt;
	struct tm *ts;

		
		time(&tt);
		ts = localtime(&tt);
		
		y = ts->tm_year;

		h = ts->tm_hour;
		m = ts->tm_min;
		s = ts->tm_sec;
		
		float H = -((float)h);
		float M = -((float)m);
		float S = -((float)s);
		
		for(int i=0;i<200;i++){
		for(int j=0;j<200;j++){
			clock[i][j] = ' ';
		}
	}
	for(int i=50;i<150;i++){
		clock[(int)(sqrt(50*50 - (i-100)*(i-100)))+100][i] = '#';
		clock[-(int)(sqrt(50*50 - (i-100)*(i-100)))+100][i] = '#';
	}


		for(int i=0;i<50;i++){
			
			
			clock[(int)(-(cos(S/30.0*3.14))*((float)i))+100][(int)(-(sin(S/30.0*3.14))*((float)i))+100] = 'S';
		}
		for(int i=0;i<45;i++){
			clock[(int)(-(cos(M/30.0*3.14))*((float)i))+100][(int)(-(sin(M/30.0*3.14))*((float)i))+100] = 'M';
		}
		for(int i=0;i<30;i++){
			clock[(int)(-(cos(H/6.0*3.14 + M/60.0*2.0*3.14/12.0))*((float)i))+100][(int)(-(sin(H/6.0*3.14 + M/60.0*2.0*3.14/12.0))*((float)i))+100] = 'H';
		}

		for(int i=50;i<151;i++){
			for(int j=50;j<151;j++){
				printf("%c",clock[i][j]);
				printf(" ");
			}
			printf("\n");
		}
		
		usleep(1000000);
		system("clear");

	}
	return 0;
}
