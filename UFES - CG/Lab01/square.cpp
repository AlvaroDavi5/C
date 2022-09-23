// lib headers
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#define WINDOW_SIZE 500

// global variables
float gX = 0.0, gY = 0.0;

void display(void)
{
	// clear display buffer for all pixels
	glClear(GL_COLOR_BUFFER_BIT);

	// set vertex colors using RGB scale ranging between 0.0 and 1.0
	glColor3f(0.5, 1.0, 0.7);

	// drawn a green polygon (square)
	glBegin(GL_POLYGON);
	glVertex3f(0.25 + gX, 0.25 + gY, 0.0);
	glVertex3f(0.75 + gX, 0.25 + gY, 0.0);
	glVertex3f(0.75 + gX, 0.75 + gY, 0.0);
	glVertex3f(0.25 + gX, 0.75 + gY, 0.0);
	glEnd();

	// drwan on frame buffer
	glutSwapBuffers();
}

void keyPress(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		gY += (0.01);
		break;
	case 's':
		gY -= (0.01);
		break;
	case 'a':
		gX -= (+0.01);
		break;
	case 'd':
		gX += (+0.01);
		break;
	default:
		break;
	}

	// reload display
	glutPostRedisplay();
}

void mouseControl(int button, int state, int x, int y)
{
	float posX = 0.0, posY = 0.0;
	char buttonName[7] = "";

	y = WINDOW_SIZE - y; // invert Y aexis
	posX = float(x) / float(WINDOW_SIZE);
	posY = float(y) / float(WINDOW_SIZE);

	gX = posX - 0.25;
	gY = posY - 0.25;

	switch (button)
	{
	case 0:
		strcpy(buttonName, "left");
		break;
	case 1:
		strcpy(buttonName, "middle");
		gX = 0.0;
		gY = 0.0;
		break;
	case 2:
		strcpy(buttonName, "right");
		gX = -gX;
		gY = -gY;
		break;
	default:
		break;
	}

	printf("Mouse Button: %s (%d)\t", buttonName, state);
	printf("Mouse Position: X=%d, Y=%d\n", x, y);

	glutPostRedisplay();
}

void initView(void)
{
	// set background color
	glClearColor(0.0, 0.0, 0.0, 0.0);

	// init view system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char **argv)
{
	// GLUT initialization
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	// view window initialization
	glutInitWindowSize(WINDOW_SIZE, WINDOW_SIZE);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Square");
	initView();

	// callbacks register
	glutDisplayFunc(display);
	//glutReshapeFunc();
	glutKeyboardFunc(keyPress);
	glutMouseFunc(mouseControl);

	// render loop
	glutMainLoop();

	return 0;
}
