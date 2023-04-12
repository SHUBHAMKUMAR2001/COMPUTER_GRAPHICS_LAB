#include<stdio.h>
#include<GL/glut.h>
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.1, 0.5, 0.7);
	//glPointSize(2);
	glBegin(GL_LINES);
	glVertex2f(-50, 0);
	glVertex2f(-25, 0);
	glEnd();
	glFlush();
	glBegin(GL_LINES);
	glVertex2f(50, 0);
	glVertex2f(25, 0);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);
	glVertex2f(-75, 00);
	glVertex2f(-75, -50);
	glVertex2f(-50, -50);
	glVertex2f(-50, 0);
	glEnd();
	glFlush();
	//glColor3f(0.1, 0.5, 0.7);
	//glPointSize(2);
	glBegin(GL_POLYGON);
	glVertex2f(-25, 00);
	glVertex2f(25, 00);
	glVertex2f(25, -75);
	glVertex2f(-25, -75);


	glEnd();
	glFlush();
	glBegin(GL_POLYGON);
	glVertex2f(75, 00);
	glVertex2f(75, -50);
	glVertex2f(50, -50);
	glVertex2f(50, 0);

	//glColor3f(0.5, 0.7, 0.7);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);
	glVertex2f(25, 50);
	glVertex2f(-25, 50);
	glVertex2f(-25, 20);

	glVertex2f(25, 20);
	glVertex2f(25, 50);


	glEnd();
	glFlush();

	glBegin(GL_POLYGON);
	glVertex2f(-15, 20);
	glVertex2f(-15, 0);
	glVertex2f(15, 0);
	glVertex2f(15, 20);
	glEnd();
	glFlush();
}
void myinit()
{
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);

}
int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("first");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();

}