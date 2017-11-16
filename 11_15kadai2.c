#include <stdio.h>
#include <GLUT/glut.h>

void Display(void);
void Reshape(int,int);

double length;

int main(int argc,char **argv){

	printf("一辺 何ptの星を描きましょうか。\n>>");
	scanf("%lf",&length);

	glutInit(&argc,argv);
	glutInitWindowSize(length,length*0.95);
	glutCreateWindow("決め打ち一筆書き");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutInitDisplayMode(GLUT_RGBA);
	glClearColor(0.0,0.0,1.0,1.0);

	glutMainLoop();

	return (0);
}


void Display(void){
	glClear(GL_COLOR_BUFFER_BIT);

	double x[5];
	double y[5];
	x[0] = 0;
	x[1] = length/2.0 - length*0.31 + 2*length*0.31;
	x[2] = length/2.0;
	x[3] = length/2.0 - length*0.31;
	x[4] = length;
	y[0] = 36.2/100.0*length;
	y[1] = length*0.95;
	y[2] = 0;
	y[3] = length*0.95;
	y[4] = 36.2/100.0*length;

	glPointSize(10.0);
	glBegin(GL_LINE_LOOP);

	glVertex2d(x[0],y[0]);
	glVertex2d(x[1],y[1]);
	glVertex2d(x[2],y[2]);
	glVertex2d(x[3],y[3]);
	glVertex2d(x[4],y[4]);
	glVertex2d(x[0],y[0]);

	glEnd();
	glFlush();
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