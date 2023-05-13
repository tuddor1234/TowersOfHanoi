#include "iostream";
#include <GL/glut.h>
#include "Structs.h"
#include "Pole.h"
#include "GameController.h"

GameController* controller;
Pole poles[3];
Disk* disks[NUMBER_OF_DISKS];

void Init() {

	glClearColor(0.3, 0.3, 0.3, 1);
	glShadeModel(GL_FLAT);


	poles[0].position = Positions::Left;
	poles[1].position = Positions::Middle;
	poles[2].position = Positions::Right;

	for (int i = 0; i < NUMBER_OF_DISKS; i++)
	{
		disks[i] = new Disk((NUMBER_OF_DISKS - i) * 0.5f);
		poles[0].TryPushDisk(disks[i]);
	}

	controller = new GameController(&poles[0], &poles[1], &poles[2]);

}

void Keyboard(unsigned char key, int x, int y) 
{

	if (controller == nullptr)
		return;

	switch (key)
	{
	case 'w':
		controller->Up();
		break;

	case 's':
		controller->Down();
		break;

	case 'a':
		controller->Left();
		break;

	case 'd':
		controller->Right();
		break;


	case 27:
		exit(0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}




void Display() {


	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glPushMatrix();

	poles[0].Draw();
	poles[1].Draw();
	poles[2].Draw();

	for (int i = 0; i < NUMBER_OF_DISKS; i++)
	{
		glPushMatrix();
		disks[i]->Draw();
		glPopMatrix();
	}

	glPopMatrix();
	glFlush();

}

//Functia apelata la schimbarea dimensiunii ferestrei
void Reshape(int w, int h) {
	if (w == 0 || h == 0) return;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0);

	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, w, h);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1200, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hanoi tower");
	Init();
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
}