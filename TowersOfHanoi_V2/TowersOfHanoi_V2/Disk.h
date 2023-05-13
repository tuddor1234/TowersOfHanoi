
#pragma once

#include <gl/glut.h>
#include "Structs.h"
#include "Cylinder.h"

class Disk
{
	float radius = 2;
	
	float yPos;
	Positions position = Positions::Left;

	Cylinder cylinder{ &radius , 0.1f, true };

public:

	

	Disk(float r) : radius(r) {}

	float getRadius() { return radius; }

	void Draw();

	void setYPos(float y)
	{
		yPos = y;
	}
	
	void setPole(Positions pos)
	{
		position = pos;
	}
};

