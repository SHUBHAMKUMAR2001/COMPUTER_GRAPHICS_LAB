#include<stdio.h>
#include<GL/glut.h>

void myinit()
{
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}
void draw_triangle(float *a, float *b, float *c)
{
	glBegin(GL_POLYGON);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
}
void draw_tetra(float *a, float *b, float *c, float *d)
{
	glColor3f(1, 0, 0);
	draw_triangle(a, b, c);
	glColor3f(0, 1, 0);
	draw_triangle(a, b, d);
	glColor3f(0, 0, 1);
	draw_triangle(a, c, d);
	glColor3f(1, 1, 1);
	draw_triangle(b, c, d);
}

void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	float v[4][3] = { {-0.5,-0.25,0},{0.5,-0.25,0},{0,0.75,0},{0,0,0.25} };
	draw_tetra(v[0], v[1], v[2], v[3]);
	glFlush();
}

int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(500, 500);
	glutCreateWindow("3D Tetraheadron");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;

}