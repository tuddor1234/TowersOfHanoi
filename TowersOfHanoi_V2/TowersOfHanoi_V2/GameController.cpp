#include "GameController.h"
#include <iostream> 

void GameController::Up()
{
	if (selectedDisk != nullptr)
		return;

	selectedDisk = poles[poleIndex]->PopDisk();
	
	if (selectedDisk == nullptr)
		return;

	selectedDisk->setYPos(3);

}

void GameController::Down()
{
	if (selectedDisk == nullptr)
		return;

	bool out = poles[poleIndex]->TryPushDisk(selectedDisk);
	if (out == true)
	{
		selectedDisk = nullptr;

		if (poles[poleIndex]->GetNumberOfDisks() == NUMBER_OF_DISKS && poleIndex > 0)
		{
			GameOver();
		}
	}
	
}

void GameController::Left()
{
	if (poleIndex == 0)
		return;

	poles[poleIndex]->Highlight(false);
	poleIndex--;
	poles[poleIndex]->Highlight(true);

	if (selectedDisk == nullptr)
		return;

	auto pos = poles[poleIndex]->position;
	selectedDisk->setPole(pos);
}

void GameController::Right()
{
	if (poleIndex == 2)
		return;

	poles[poleIndex]->Highlight(false);
	poleIndex++;
	poles[poleIndex]->Highlight(true);
	
	if (selectedDisk == nullptr)
		return;

	auto pos = poles[poleIndex]->position;
	selectedDisk->setPole(pos);

}

void GameController::GameOver()
{
	std::cout << "Congrats!";
}
