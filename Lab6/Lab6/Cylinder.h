#pragma once

#include <GL/glut.h>

#include "Structs.h"

#define PI 3.1415927


class Cylinder
{
	float radius;
	float height;
	Vector3 color { 100,200, 140 };
	
	Vector3 NomalPoleColor{ 80 ,100, 100 };
	Vector3 HighlitedPoleColor{ 100,200, 140 };

	Vector3 DiskColor{ 250,40, 40};

public: 
	
	Cylinder(float *r, float h, bool isDisk) : radius(*r), height(h)
	{
		SetColor(isDisk);
	}

	void Draw();

	void SetColor(bool isDisk);

	void HighLight(bool isHighlited);

};

