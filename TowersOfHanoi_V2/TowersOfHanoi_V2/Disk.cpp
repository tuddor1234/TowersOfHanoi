#include "Disk.h"


void Disk::Draw()
{
	glPushMatrix();
	glTranslatef((GLfloat)this->position, yPos , -10);
	cylinder.Draw();
	glPopMatrix();
}
