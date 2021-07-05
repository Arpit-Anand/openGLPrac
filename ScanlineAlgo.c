#include<stdio.h>
#include <string.h>
#include<GL/glut.h>
#include <stdlib.h>

int submenu;
float x1,y1,x2,y2,x3,y3,x4,y4;

void render(float x, float y,char *str){
	glColor3f(0.2,0.6,0.6);
	glRasterPos2f(x,y);
	for(int i = 0; i< strlen(str); i++){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
	}
}
int edgedetect(float x1, float y1, float x2, float y2, int *le, int *re){
  float mx, x, temp;
  int i;
  if ((y2-y1) < 0) {
    temp = y1;
    y1 = y2;
    y2 = temp;
    temp = x1;
    x1 = x2;
    x2 = temp;
  }
  if((y2-y1) != 0)
    mx = (x2-x1)/(y2-y1);
  else
    mx = x2-x1;
  x = x1;
  for(i = y1; i <= y2; i++){
    if(x < (float)le[i])
      le[i] = (int)x;
    if(x > (float)re[i])
      re[i] = (int)x;
    x += mx;
  }
}

void drawpixel(int x, int y) {
  /* code */
  //glColor3f(1.0,1.0,0.0);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}

void scanfill(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4){
  int le[500], re[500];
  int i,y;
  for(i=0; i<500; i++){
    le[i] = 500;
    re[i] = 0;
  }
  edgedetect(x1,y1,x2,y2,le,re);
  edgedetect(x2,y2,x3,y3,le,re);
  edgedetect(x3,y3,x4,y4,le,re);
  edgedetect(x4, y4, x1, y1, le, re);
  for(y = 0; y < 500; y++){
    if(le[y] <= re[y]){
      for(i=(int)le[y]; i < (int)re[y]; i++){
        drawpixel(i,y);
      }
    }
  }
}

void display(){
  x1 = 200.0, y1 = 200.0, x2 = 100.0, y2 = 300.0, x3 = 200.0, y3 = 400.0, x4 = 300.0, y4 = 300.0;
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINE_LOOP);
  glVertex2f(x1,y1);
  glVertex2f(x2,y2);
  glVertex2f(x3,y3);
  glVertex2f(x4,y4);
  glEnd();
  scanfill(x1,y1,x2,y2,x3,y3,x4,y4);
  render(20,0,"1BI18CS026");
  glFlush();
}

void init(){
  glClearColor(1.0,1.0,1.0,1.0);
  glColor3f(1.0,1.0,0.0);
  glPointSize(1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,499.0,0.0,499.0);
}

void menufunc(int n){
  switch (n) {
    case 1:glColor3f(1.0,0.0,0.0);
          break;
    case 2 : glColor3f(0.0,1.0,0.0);
            break;
    case 3 : glColor3f(0.0,0.0,1.0);
            break;
  }
  glutPostRedisplay();
}
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(50,50);
  glutCreateWindow("Scan Line Algo");
  glutCreateMenu(menufunc);
  glutAddMenuEntry("Red", 1);
  glutAddMenuEntry("Green", 2);
  glutAddMenuEntry("Blue", 3);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutDisplayFunc(display);
  init();
  glutMainLoop();
  return 0;
}
