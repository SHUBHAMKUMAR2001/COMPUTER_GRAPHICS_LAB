#include<stdio.h>
#include<GL/glut.h>
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2f(250, 250);
	glEnd();
	glFlush();
}
void myinit()
{
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}
int main()
{
	glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
	glutInitWindowPosition(500, 500);
	glutCreateWindow("FIRST");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}