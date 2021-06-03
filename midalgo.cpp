#include <stdio.h>
#include<bits/stdc++.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

int pntX1, pntY1, r;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+pntX1, y+pntY1);
	glEnd();
}

void renderstring(float x, float y, string str){
	glColor3f(0.5,0.5,0.5);
	glRasterPos2f(x,y);
	for(int i=0; i<str.size(); i++){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
	}
}
void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}


void midPointCircleAlgo()
{
	int x = 0;
	int y = r;
	float decision = 5/4 - r;
	plot(x, y);

	while (y > x)
	{
		x++;
		if (decision < 0)
		{ 
			decision += 2*x+1;
		}
		else
		{
			y--;
			decision += 2*(x-y)+1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}

}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);
	renderstring(0,0,"Arpit Anand 1BI18cs026");
	midPointCircleAlgo();

	glFlush ();
}

int main(int argc, char** argv)
{	
	cout << "Enter the coordinates of the center:\n\n" << endl;

	cout << "X-coordinate   : "; cin >> pntX1;
	cout << "\nY-coordinate : "; cin >> pntY1;
	cout << "\nEnter radius : "; cin >> r;


	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (0,0);
	glutCreateWindow ("Line Drawing Alogrithms");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();
	return 0;
}
