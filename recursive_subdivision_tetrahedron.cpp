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

void divide_tetra(float *a, float *b, float *c, float *d, int n)
{
	float ab[3], ac[3], ad[3], bc[3], bd[3], cd[3];
	if (n > 0)
	{
		for (int j = 0; j < 3; j++)
		{
			ab[j] = (a[j] + b[j]) / 2;
			ac[j] = (a[j] + c[j]) / 2;
			ad[j] = (a[j] + d[j]) / 2;
			bc[j] = (b[j] + c[j]) / 2;
			bd[j] = (b[j] + d[j]) / 2;
			cd[j] = (c[j] + d[j]) / 2;
		}
		divide_tetra(a, ab, ac, ad, n - 1);
		divide_tetra(ab, b, bc, bd, n - 1);
		divide_tetra(ac, bc, c, cd, n - 1);
		divide_tetra(ad, bd, cd, d, n - 1);
	}
	else
	{
		draw_tetra(a, b, c, d);
	}
}

void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	float v[4][3] = { {-0.5,-0.25,0},{0.5,-0.25,0},{0,0.75,0},{0,0,0.25} };
	int n = 1;
	divide_tetra(v[0], v[1], v[2], v[3], n);
	glFlush();
}

int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(500, 500);
	glutCreateWindow("3D Tetraheadron");
	myinit();
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;

}





