#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Person.h"
#include "Floor.h"
#include "ElevatorCar.h"
#include "WaitingFloors.h"
#include <queue>
#include <vector>
class IncrementTime
{
public:

	// SORTS THE PRIORITY QUEUE FROM LEAST FLOOR TO GREATEST

	class GoingUp
	{
	public:
		bool operator()(const Person* p1, const Person* p2) const
		{
			return p1->toFloor > p2->toFloor;
		}
	};

	// SORTS THE PRIORITY QUEUE FROM GREATEST FLOOR TO LEAST

	class GoingDown
	{
	public:
		bool operator()(const Person* p1, const Person* p2) const
		{
			return p1->toFloor < p2->toFloor;
		}
	};

	// INCREMENTS WAIT TIME FOR PEOPLE

	void incrementTime(Floor** FLOORS, ElevatorCar* ELEVATORCAR)
	{
		// INCREMENTS WAIT TIME FOR PEOPLE ON THE FLOORS

		for (int x = 0; x < 6; x++)
		{
			while (!FLOORS[x]->isPersonUpQueueEmpty())
			{
				temp = FLOORS[x]->tempRemovePersonUp();
				temp->setWaitTime(temp->getWaitTime() + 10);
				tempQueueUp.push(temp);
				temp = nullptr;
			}
			while (!FLOORS[x]->isPersonDownQueueEmpty())
			{
				temp = FLOORS[x]->tempRemovePersonDown();
				temp->setWaitTime(temp->getWaitTime() + 10);
				tempQueueDown.push(temp);
				temp = nullptr;
			}
			while (!tempQueueUp.empty())
			{
				temp = tempQueueUp.top();
				tempQueueUp.pop();
				FLOORS[x]->addPersonUp(temp);
				temp = nullptr;
			}
			while (!tempQueueDown.empty())
			{
				temp = tempQueueDown.top();
				tempQueueDown.pop();
				FLOORS[x]->addPersonDown(temp);
				temp = nullptr;
			}
		}

		// INCREMENTS TIME FOR PEOPLE IN ELEVATOR QUEUES

		while (!ELEVATORCAR->isPersonUpQueueEmpty())
		{
			temp = ELEVATORCAR->tempRemovePersonUp();
			temp->setTravelTime(temp->getTravelTime() + 10);
			tempQueueUp.push(temp);
			temp = nullptr;
		}
		while (!ELEVATORCAR->isPersonDownQueueEmpty())
		{
			temp = ELEVATORCAR->tempRemovePersonDown();
			temp->setTravelTime(temp->getTravelTime() + 10);
			tempQueueDown.push(temp);
			temp = nullptr;
		}
		while (!tempQueueUp.empty())
		{
			temp = tempQueueUp.top();
			tempQueueUp.pop();
			ELEVATORCAR->fillUpQueue(temp);
			temp = nullptr;
		}
		while (!tempQueueDown.empty())
		{
			temp = tempQueueDown.top();
			tempQueueDown.pop();
			ELEVATORCAR->fillDownQueue(temp);
			temp = nullptr;
		}

	}

private:

	priority_queue <Person*, vector<Person*>, GoingUp> tempQueueUp;
	priority_queue <Person*, vector<Person*>, GoingDown> tempQueueDown;
	Person* temp = nullptr;

};
