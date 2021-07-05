#include<stdio.h>
#include<GL/glut.h>
#include<string.h>
GLfloat mat_ambient[]={1.0,0.0,0.0,1.0};
GLfloat mat_diffuse[]={0.5,0.5,0.5,1.0};
GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
const GLfloat mat_shininess[] = {50.0};
GLfloat light_intensity[]= {0.7,0.7,0.7,1.0};
GLfloat light_position[]={2.0,6.0,3.0,0.0};

void render(float x, float y, char *str){
  glColor3f(0.0,0.0,0.0);
  glRasterPos2f(x,y);
  for (int i = 0; i < strlen(str); i++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
  }
}

void init(){
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_intensity);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-2.0,2.0,-2.0,2.0,-10.0,10.0);
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(2.0,1.0,2.0,0.0,0.2,0.2,0.0,1.0,0.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void teapot(){
  glPushMatrix();
  glTranslated(0.4,0.0,0.4);
  glRotated(30,0,1,0);
  glutSolidTeapot(0.2);
  glPopMatrix();
}

void tabletop(){
  glPushMatrix();
  glTranslated(0.0,-0.3,0.0);
  glScaled(7.0,0.5,7.0);
  glutSolidCube(0.2);
  glPopMatrix();
}

void frontleg(){
  glPushMatrix();
  glTranslated(0.5,-0.7,0.5);
  glScaled(0.5,7.0,0.5);
  glutSolidCube(0.1);
  glPopMatrix();
}

void leftleg() {
  glPushMatrix();
  glTranslated(-0.5,-0.7,0.5);
  glScaled(0.5,7.0,0.5);
  glutSolidCube(0.1);
  glPopMatrix();
}
void rightleg() {
  glPushMatrix();
  glTranslated(0.5,-0.7,-0.5);
  glScaled(0.5,7.0,0.5);
  glutSolidCube(0.1);
  glPopMatrix();
}
void backleg() {
  glPushMatrix();
  glTranslated(-0.5,-0.7,-0.5);
  glScaled(0.5,7.0,0.5);
  glutSolidCube(0.1);
  glPopMatrix();
}

void leftwall(){
  glPushMatrix();
  glTranslated(-1.0,0.0,0.0);
  glScaled(0.1,10.0,10.0);
  glutSolidCube(0.2);
  glPopMatrix();
}
void rightwall(){
  glPushMatrix();
  glTranslated(0.0,0.0,-1.0);
  glScaled(10.0,10.0,0.1);
  glutSolidCube(0.2);
  glPopMatrix();
}
void bfloor(){
  glPushMatrix();
  glTranslated(0.0,-1.0,0.0);
  glScaled(10.0,0.1,10.0);
  glutSolidCube(0.2);
  glPopMatrix();
}

void display(){
  init();
  teapot();
  leftleg();
  rightleg();
  frontleg();
  backleg();
  tabletop();
  bfloor();
  leftwall();
  rightwall();
  render(-1.8,-1.8,"1BI18CS026");
  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(50,50);
  glutInitWindowSize(500,500);
  glutCreateWindow("Teapot");
  glutDisplayFunc(display);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  glClearColor(0.1,1.0,1.0,0.0);
  glViewport(0,0,640,480);
  glutMainLoop();
  return 0;
}
