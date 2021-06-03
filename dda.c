#include<GL/glut.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
float x1,x2,y1,y2;
 
void renderstring(float x, float y, char *str){
	glColor3f(0.5,0.5,0.5);
	glRasterPos2f(x,y);
	for(int i=0; i<strlen(str); i++){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
	}
}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
float dy,dx,step,x,y,k,Xin,Yin;
dx=x2-x1;
dy=y2-y1;
 
if(abs(dx)> abs(dy))
{
step = abs(dx);
}
else
step = abs(dy);
 
Xin = dx/step;
Yin = dy/step;

x= x1;
y=y1;
renderstring(0.0,0.0,"Arpit Anand 1BI18CS026");

glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();

for (k=1 ;k<=step;k++)
{
x= x + Xin;
y= y + Yin;
glColor3f(1.0,0.0,0.0);
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
}

glFlush();
}
 
void init(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,500,0,500);
}


int main(int argc, char** argv) {
printf("Enter the value of x1 : ");
scanf("%f",&x1);
printf("Enter the value of y1 : ");
scanf("%f",&y1);
printf("Enter the value of x2 : ");
scanf("%f",&x2);
printf("Enter the value of y2 : ");
scanf("%f",&y2);
 
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (0,0);
glutCreateWindow ("DDA Line Algo");
init();
glutDisplayFunc(display);
glutMainLoop();
 
return 0;
}
