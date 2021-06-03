#include<GL/glut.h>
#include<stdio.h>

int x1[5], x2[5], y1[5], y2[5];
int i;

void init(){
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.5,1.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}
void draw_pixel(int x, int y){
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
void draw_line(int x1, int x2, int y1, int y2){
	int dx,dy,i,e;
	int incx=1, incy=1, inc1, inc2;
	int x = x1, y=y1 ;
	dx = x2 -x1;
	dy = y2 -y1;
	if(dx < 0)
		dx = -dx;
	if( dy<0)
		dy =-dy;
	if (x2 <x1)
		incx =-1;
	if(y2<y1)
		incy = -1;
	if(dx>dy){
		draw_pixel(x,y);
		e =2*dy - dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for(i=0; i<dx; i++){
			if (e>=0){
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_pixel(x,y);
			}
		}
		else{
			draw_pixel(x,y);
			e = 2*dy - dx;
			inc1 = 2*(dx-dy);
			inc2 = 2*dx;
			for(i=0; i<dy;i++){
				if(e>=0){
					x += incx;
					e += inc1;
				}
				else
					e += inc2;
				y += incy;
				draw_pixel(x,y);
			}
		}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	for(i=0; i<5; i++){
		draw_line(x1[i],x2[i],y1[i],y2[i]);	
	}
	glFlush();
}

int main(int argc, char **argv){
	printf("Will Print Multiple lines\n");
	for(i=0; i<5; i++){
		printf("Enter end points of the line(x1, y1, x2, y2)\n");
		scanf("%d%d%d%d",&x1[i], &y1[i], &x2[i], &y2[i]);
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("1BI18CS026-ARPIT ANAND-MULTI LINES");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

