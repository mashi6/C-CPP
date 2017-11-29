#include <GLUT/glut.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

void Display(void);
void Timer(void);
void Reshape(int,int);

int main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowSize(700,700);
	glutCreateWindow("Clock");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutTimerFunc(10,Timer,0);
	glutMainLoop();
	return(0);
}

void Timer(void){
	glutPostRedisplay();
	glutTimerFunc(10,Timer,0);
}

void Reshape(int w,int h){
	printf("Windowの幅%d,高さ%d",w,h);
	glViewport(0,0,w,h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(0,w,0,h);
	glScaled(1,-1,1);
	glTranslated(0,-h,0);
}

void Display(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	time_t tt;
	struct tm *ts;
	struct timeval myTime;
	gettimeofday(&myTime,NULL);
	time(&tt);
	ts = localtime(&tt);
	double w,h,m,s;
	w = (double)(ts->tm_wday);
	h = (double)(ts->tm_hour);
	m = (double)(ts->tm_min);
	s = (double)(ts->tm_sec) + ((double)(myTime.tv_usec))/(1000000.0);

	double x=0.0,y=0.0;
	double wx,wy,hx,hy,mx,my,sx,sy;
	double center = 350.0;
	double r = 350.0;

	x = center;
	y = center;

//W
	glColor3ub(127,76,114);
	glLineWidth(14.0);
	glBegin(GL_LINE_LOOP);
	for(double i=0;i<360;i++){
		glVertex2d(cos(i/360.0*2.0*3.14)/1.8*r + x,sin(i/360.0*2.0*3.14)/1.8*r + y);
	}
	glEnd();

	for(double i=0;i<7;i++){
		glBegin(GL_LINES);
		glVertex2d(sin(i/7.0*2.0*3.14)/2.2*r + x,-cos(i/7.0*2.0*3.14)/2.2*r + y);
		glVertex2d(sin(i/7.0*2.0*3.14)/1.8*r + x,-cos(i/7.0*2.0*3.14)/1.8*r + y);
		glEnd();
	}

	glBegin(GL_LINES);
	glVertex2d(x,y);
	x = sin(w/7.0*2.0*3.14 + h/24.0*2.0*3.14/7.0)/1.8*r + x;
	y = -cos(w/7.0*2.0*3.14 + h/24.0*2.0*3.14/7.0)/1.8*r + y;
	wx = x;
	wy = y;
	glVertex2d(x,y);
	glEnd();
//W

//H
	glColor3ub(204,0,0);
	glLineWidth(10.0);
	glBegin(GL_LINE_LOOP);
	for(double i=0;i<360;i++){
		glVertex2d(cos(i/360.0*2.0*3.14)/2.5*r + x,sin(i/360.0*2.0*3.14)/2.5*r + y);
	}
	glEnd();
	
	for(double i=0;i<12;i++){
		glBegin(GL_LINES);
		glVertex2d(sin(i/12.0*2.0*3.14)/3.0*r + x,cos(i/12.0*2.0*3.14)/3.0*r + y);
		glVertex2d(sin(i/12.0*2.0*3.14)/2.5*r + x,cos(i/12.0*2.0*3.14)/2.5*r + y);
		glEnd();
	}

	glBegin(GL_LINES);
	glVertex2d(x,y);
	x = sin(h/12.0*2.0*3.14 + m/60.0*2.0*3.14/12.0)/2.5*r + x;
	y = -cos(h/12.0*2.0*3.14 + m/60.0*2.0*3.14/12.0)/2.5*r + y;
	hx = x;
	hy = y;
	glVertex2d(x,y);
	glEnd();
//H

//M
	glColor3ub(116,169,214);
	glLineWidth(5.0);
	
	glBegin(GL_LINE_LOOP);
	for(double i=0;i<360;i++){
		glVertex2d(cos(i/360.0*2.0*3.14)/4.0*r + x,sin(i/360.0*2.0*3.14)/4.0*r + y);
	}
	glEnd();

	for(double i=0;i<60;i++){
		glBegin(GL_LINES);
		if((int)i%15 == 0){
			glVertex2d(sin(i/60.0*2.0*3.14)/5.1*r + x,cos(i/60.0*2.0*3.14)/5.1*r + y);
		}else{
			glVertex2d(sin(i/60.0*2.0*3.14)/4.3*r + x,cos(i/60.0*2.0*3.14)/4.3*r + y);
		}
		glVertex2d(sin(i/60.0*2.0*3.14)/4.0*r + x,cos(i/60.0*2.0*3.14)/4.0*r + y);
		glEnd();
	}

	glBegin(GL_LINES);
	glVertex2d(x,y);
	x = x + sin(m/60.0*2.0*3.14 + s/60.0*2.0*3.14/60.0)/4.0*r;
	y = y + -cos(m/60.0*2.0*3.14 + s/60.0*2.0*3.14/60.0)/4.0*r;
	mx = x;
	my = y;
	glVertex2d(x,y);
	glEnd();
	glRasterPos2f(x,y);
//M

//S
	glColor3ub(236,165,23);
	glLineWidth(3.0);
	
	glBegin(GL_LINE_LOOP);
	for(double i=0;i<360;i++){
		glVertex2d(cos(i/360.0*2.0*3.14)/8.0*r + x,sin(i/360.0*2.0*3.14)/8.0*r + y);
	}
	glEnd();
	for(double i=0;i<60;i++){
		glBegin(GL_LINES);
		if((int)i%15 == 0){
			glVertex2d(sin(i/60.0*2.0*3.14)/9.8*r + x,cos(i/60.0*2.0*3.14)/9.8*r + y);
		}else{
			glVertex2d(sin(i/60.0*2.0*3.14)/8.5*r + x,cos(i/60.0*2.0*3.14)/8.5*r + y);
		}
		glVertex2d(sin(i/60.0*2.0*3.14)/8.0*r + x,cos(i/60.0*2.0*3.14)/8.0*r + y);
		glEnd();
	}
		
	glBegin(GL_LINES);
	glVertex2d(x,y);
	x = x + sin(s/60.0*2.0*3.14)/8.0*r;
	y = y + -cos(s/60.0*2.0*3.14)/8.0*r;
	sx = x;
	sy = y;
	glVertex2d(x,y);
	glEnd();
	glRasterPos2f(x,y);
//S

// 1/10
	glColor3ub(71,234,126);
	glBegin(GL_LINE_LOOP);
	for(double i=0;i<360;i++){
		glVertex2d(cos(i/360.0*2.0*3.14)/16.0*r + x,sin(i/360.0*2.0*3.14)/16.0*r + y);
	}
	glEnd();

	glBegin(GL_LINES);
	glVertex2d(x,y);
	
	x = x + sin(((double)(myTime.tv_usec))/(1000000.0)*2.0*3.14)/16.0*r;
	y = y + -cos(((double)(myTime.tv_usec))/(1000000.0)*2.0*3.14)/16.0*r;

	glVertex2d(x,y);
	glEnd();
// 1/10

	char output[10]="\0";
	char week[7][10] = {
		"Sun","Mon","Tue","Wed","Thu","Fri","Sat"
	};
	glColor3ub(255,255,255);

	sprintf(output,"%s",week[(int)w]);
	for(double j=0;j<(double)sizeof(output);j++){
		glRasterPos2f(wx + j*12,wy);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,output[(int)j]);
	}
	sprintf(output,"%dh",(int)h);
	for(double j=0;j<(double)sizeof(output);j++){
		glRasterPos2f(hx + j*12,hy);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,output[(int)j]);
	}
	sprintf(output,"%dm",(int)m);
	for(double j=0;j<(double)sizeof(output);j++){
		glRasterPos2f(mx + j*12,my);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,output[(int)j]);
	}		
	sprintf(output,"%ds",(int)s);
	for(double j=0;j<(double)sizeof(output);j++){
		glRasterPos2f(sx + j*12,sy);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,output[(int)j]);
	}

	glutSwapBuffers();
}