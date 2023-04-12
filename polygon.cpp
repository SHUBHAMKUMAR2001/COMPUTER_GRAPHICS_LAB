#include<stdio.h>
#include<GL/glut.h>
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);

	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(4, 0);
	glVertex2f(4, 4);
	glVertex2f(0, 4);
	
	glEnd();
	glFlush();
	
}
void myinit()
{
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
}
int main()
{
	glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
	glutInitWindowPosition(500, 500);
	glutCreateWindow("TRIANGLES");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}