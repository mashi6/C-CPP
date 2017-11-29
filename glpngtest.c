#include <stdio.h>
#include <GLUT/glut.h>
#include <glpng/glpng.h>

GLuint texture;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(0, 0, 0);
        glBindTexture(GL_TEXTURE_2D, texture);
    glPopMatrix();
  
    glBegin(GL_QUADS);
        glTexCoord2d(0.0, 1.0);
        glVertex2d(-1, -1);
        glTexCoord2d(1.0, 1.0);
        glVertex2d(1, -1);
        glTexCoord2d(1.0, 0.0);
        glVertex2d(1, 1);
        glTexCoord2d(0.0, 0.0);
        glVertex2d(-1, 1);
    glEnd();
    glFlush();
} 

void init()
{ 
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3d(1.0, 1.0, 1.0);
    glEnable(GL_TEXTURE_2D);
  
    pngInfo info;
    texture = pngBind("glpngtest.png", PNG_NOMIPMAP, PNG_ALPHA, &info, GL_CLAMP, GL_NEAREST, GL_NEAREST);
} 
  
int main(int argc, char** argv)
{ 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(404, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("PNG");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
} 