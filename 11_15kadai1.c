#include <GLUT/glut.h>

#include <stdio.h>
#include <math.h>

void Display(void);
void Reshape(int,int);

double length;

int main(int argc,char **argv){

	printf("一辺 何ptの星を描きましょうか。\n>>");
	scanf("%lf",&length);

	glutInit(&argc,argv);
	glutInitWindowSize(length,length*0.95);
	glutCreateWindow("計算一筆書き");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutInitDisplayMode(GLUT_RGBA);
	glClearColor(0.0,0.0,1.0,1.0);

	glutMainLoop();

	return (0);
}


void Display(void){
	glClear(GL_COLOR_BUFFER_BIT);

	double nextX=0,nextY=0,previousX=0,previousY=36.2/100.0*length;
		//next..次の座標(頂点) previous..１つ前の座標(頂点)
		//一番左の点から書き始めるのでpreviousX,Yにあらかじめ座標を代入

	double angle=0.0;
		//角 (度)

	glPointSize(10.0);
	glBegin(GL_LINE_LOOP);
		//描画開始(折れ線)

	for(int i=0;i<5;i++){

		double radian = angle/360.0 * 2.0*3.14;
			//角 (ラジアン)

		nextX = cos(radian)*length + previousX;
		nextY = sin(radian)*length + previousY;
			//座標計算
			//直前の座標 + 今向いてる角度[radian]に一辺の長さ[length]分進む
			//            x : cos(角度[radian]) * 一辺の長さ[length]
			//            y : sin(角度[radian]) * 一辺の長さ[length]
			//            {cos(radian)*length}^2 + {sin(radian)*length}^2 == length^2
		
		glVertex2d(previousX,previousY);
		glVertex2d(nextX,nextY);
			//描画
		
		previousX = nextX;
		previousY = nextY;
			//座標更新

		printf("radian:%lf,x:%lf,y:%lf",radian,nextX,nextY);

		angle += 144;
			//角更新
			//x軸の方向が下向きなので 180 - 36 == 144度回転
	}
	glEnd();
		//描画終了
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