#include <math.h>
#include <iostream>
#include "Pole.h"


void Pole::Draw()
{
	glPushMatrix();
	
	glTranslatef((GLfloat) this->position, -3, -10);
	cylinder.Draw();

	glPopMatrix();
}


bool Pole::TryPushDisk(Disk * disk)
{
	if (disks.size() > 0)
	{
		auto radius = disks.back()->getRadius();
		if (radius < disk->getRadius())
			return false;
	}

	disks.push_back(disk);
	disk->setYPos(disks.size() * 0.25f - 3);
		

	return true;
}

Disk * Pole::PopDisk()
{
	if (disks.size() == 0)
		return nullptr;

	auto * top = disks.back();
	disks.pop_back();
	return top;
}



void Pole::Highlight(bool isHigh)
{
	cylinder.HighLight(isHigh);
}

int Pole::GetNumberOfDisks()
{
	return disks.size();
}

