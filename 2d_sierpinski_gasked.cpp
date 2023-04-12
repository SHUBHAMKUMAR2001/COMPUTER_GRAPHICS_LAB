#include<stdio.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>

int p[2] = { 150,150 };
int v[3][2] = { {100,100},{150,200},{200,100} };

void display()
{
	int r;
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);

	
	for (int i = 0; i < 6000; i++)
	{
		glBegin(GL_POINTS);
		r =rand()%3;
		p[0] = (p[0] + v[r][0])/2;
		p[1] = (p[1] + v[r][1]) / 2;

		glVertex2f(p[0], p[1]);
	}
	glEnd();
	glFlush();

}
void myinit()
{
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(0,220,0,220);
	glMatrixMode(GL_MODELVIEW);
}
int main()
{
	glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutCreateWindow("2d gasked");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}