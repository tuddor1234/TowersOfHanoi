#pragma once
#include "Pole.h"
#include <vector>
class GameController
{
	float poleIndex = 0;
	Disk * selectedDisk = nullptr;

	std::vector <Pole *> poles;

public:

	GameController(Pole *p1, Pole *p2, Pole *p3)
	{		
		poles.resize(3);
		poles[0] = p1;
		poles[1] = p2;
		poles[2] = p3;

		poles[0]->Highlight(true);
	}


	void Up();
	void Down();
	void Left();
	void Right();

	void GameOver();
	
};

