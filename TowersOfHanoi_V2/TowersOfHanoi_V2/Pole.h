#pragma once
#include <vector>
#include <GL/glut.h>

#include "Structs.h"
#include "Disk.h"
#include "Cylinder.h"

class Pole
{
	float radius = 0.2f;
	std::vector<Disk * > disks;

	Cylinder cylinder{ &radius, 3, false};
	
public:
	
	Positions position;
	
	bool TryPushDisk(Disk * disk);

	Disk * PopDisk();

	void Draw();

	void Highlight(bool isHigh);

	int GetNumberOfDisks();
	
};

