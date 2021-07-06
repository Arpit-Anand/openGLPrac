#include<stdio.h>
#include <string.h>
#include<GL/glut.h>
#include <stdlib.h>
int pat = 0;
int submenu;
float x1,y1,x2,y2,x3,y3,x4,y4;

void render(float x, float y, char *str){
  glRasterPos2f(x,y);
  for(int i = 0 ; i < strlen(str); i++){
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
  //x1 = 200.0, y1 = 200.0, x2 = 100.0, y2 = 300.0, x3 = 200.0, y3 = 400.0, x4 = 300.0, y4 = 300.0;
  if(!pat){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();
    render(20,5,"1BI18CS026");
    scanfill(x1,y1,x2,y2,x3,y3,x4,y4);
    glFlush();
  }
  else{
    GLubyte ini1[]=
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
      0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
      0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,
      0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,
      0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
      0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
      0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,
      0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,
      0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
      0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
      0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,
      0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,
      0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
      0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
      0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,
      0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,
    };
    GLubyte ini2[]= {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x03, 0x80, 0x01, 0xC0, 0x06, 0xC0, 0x03, 0x60,
   0x04, 0x60, 0x06, 0x20, 0x04, 0x30, 0x0C, 0x20,
   0x04, 0x18, 0x18, 0x20, 0x04, 0x0C, 0x30, 0x20,
   0x04, 0x06, 0x60, 0x20, 0x44, 0x03, 0xC0, 0x22,
   0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,
   0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,
   0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,
   0x66, 0x01, 0x80, 0x66, 0x33, 0x01, 0x80, 0xCC,
   0x19, 0x81, 0x81, 0x98, 0x0C, 0xC1, 0x83, 0x30,
   0x07, 0xe1, 0x87, 0xe0, 0x03, 0x3f, 0xfc, 0xc0,
   0x03, 0x31, 0x8c, 0xc0, 0x03, 0x33, 0xcc, 0xc0,
   0x06, 0x64, 0x26, 0x60, 0x0c, 0xcc, 0x33, 0x30,
   0x18, 0xcc, 0x33, 0x18, 0x10, 0xc4, 0x23, 0x08,
   0x10, 0x63, 0xC6, 0x08, 0x10, 0x30, 0x0c, 0x08,
   0x10, 0x18, 0x18, 0x08, 0x10, 0x00, 0x00, 0x08
    };
    GLubyte ini3[] ={
      0xff, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
    0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
    0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
    0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
    0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
    0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
    0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
    0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
    0xff, 0x01, 0xff, 0x01, 0x00, 0x01, 0x01, 0x01,
    0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01,
    0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01,
    0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01,
    0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01,
    0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01,
    0xff, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };
    glClear(GL_COLOR_BUFFER_BIT);
    //glColor3f(1.0,1.0,1.0);
    glEnable(GL_POLYGON_STIPPLE);
    switch (pat) {
      case 1: glPolygonStipple(ini1);
              break;
      case 2: glPolygonStipple(ini2);
              break;
      case 3: glPolygonStipple(ini3);
              break;
    }
    pat = 0;
    /*glRectf (100.0, 100.0, 400.0, 400.0);*/
    glBegin(GL_POLYGON);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();
    glDisable(GL_POLYGON_STIPPLE);
    glFlush();
  }
}

void init(){
  glClearColor(0.0,0.0,0.0,1.0);
  glColor3f(0.6,1.0,0.3);
  glPointSize(1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,499.0,0.0,499.0);
  glShadeModel(GL_FLAT);
}

void menufunc(int n){
  switch (n) {
    case 1: glColor3f(1.0,0.0,0.0);
            break;
    case 2 :glColor3f(0.2,0.4,0.6);
            break;
    case 3 : glColor3f(0.6,0.2,0.4);
            break;
    case 4 : pat = 1;
            break;
    case 5 : pat = 2;
            break;
    case 6 : pat = 3;
            break;
    case 7: exit(0);
  }
  glutPostRedisplay();
}
void reshape(int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
}
int main(int argc, char **argv) {
  printf("Enter the four edges of rhombus\n");
  printf("First edge(x,y) \t");
  scanf("%f%f",&x1,&y1);
  printf("Second edge(x,y) \t");
  scanf("%f%f",&x2,&y2);
  printf("Third edge(x,y) \t");
  scanf("%f%f",&x3,&y3);
  printf("Fourth edge(x,y) \t");
  scanf("%f%f",&x4,&y4);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(50,50);
  glutCreateWindow("Scan Line Algo");
  int sub1 = glutCreateMenu(menufunc);
  glutAddMenuEntry("Red", 1);
  glutAddMenuEntry("SomeColor1", 2);
  glutAddMenuEntry("SomeColor2", 3);
  int sub2 = glutCreateMenu(menufunc);
  glutAddMenuEntry("Pattern 1", 4);
  glutAddMenuEntry("Pattern 2", 5);
  glutAddMenuEntry("Pattern 3", 6);
  glutCreateMenu(menufunc);
  glutAddSubMenu("Colors", sub1);
  glutAddSubMenu("Patterns", sub2);
  glutAddMenuEntry("Exit", 7);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  init();
  glutMainLoop();
  return 0;
}