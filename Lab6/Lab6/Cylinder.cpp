#include "Cylinder.h"

#include <math.h>


void Cylinder::Draw()
{
	GLubyte R = color.x;
	GLubyte G = color.y;
	GLubyte B = color.z;

	GLfloat x = 0.0;
	GLfloat y = 0.0;
	GLfloat angle = 0.0;
	GLfloat angle_stepsize = 0.1;

	glPushMatrix();

	glTranslatef(0.0, -0.4, -3.0);
	glRotatef(-90, 1.0, 0.0, 0.0);

	/** Draw the tube */
	glColor3ub(R - 40, G - 40, B - 40);
	glBegin(GL_QUAD_STRIP);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
		glVertex3f(x, y, 0.0);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glVertex3f(radius, 0.0, 0.0);
	glEnd();

	/** Draw the circle on top of cylinder */
	glColor3ub(R, G, B);
	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glEnd();

	glPopMatrix();
}

void Cylinder::SetColor(bool isDisk)
{
	color = isDisk ? DiskColor : NomalPoleColor;
}

void Cylinder::HighLight(bool isHighlited)
{
	color = isHighlited ? HighlitedPoleColor : NomalPoleColor;
}
