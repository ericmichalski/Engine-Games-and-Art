#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <queue>
#include "Person.h"
#include "WaitingFloors.h"
using namespace std;

// MAX NUM PEOPLE ON A SINGLE FLOOR = 6

class Floor
{
public:
	Floor()
	{
		numPeople = 0;
		floorNumber = 0;
	}

	// 0.8% CHANCE TO FILL A FLOOR, THEN FILLS FLOOR WITH WAITING PEOPLE RANDOMLY FROM 0-6

	void fillFloor(WaitingFloors* WAITINGFLOORS)
	{
		if (getNumPeople() < 6)
		{
			int x = -1;
			x = rand() % 5;
			if (x == 0)
			{
				int x = -1;
				x = rand() % 5;
				if (x == 0)
				{
					int x = -1;
					x = rand() % 5;
					if (x == 0)
					{
						int numPeopleAvail = 6 - getNumPeople();
						int numGen = rand() % (numPeopleAvail + 1);
						if (numGen != 0)
						{
							WAITINGFLOORS->addElement(getFloorNumber());
						}
						for (int x = 0; x < numGen; x++)
						{
							Person* Rider = new Person;
							Rider->setFromFloor(getFloorNumber());
							Rider->setToFloor(getFloorNumber());
							if (Rider->getToFloor() > Rider->getFromFloor())
							{
								personUpQueue.push(Rider);
								numPeople = numPeople + 1;
							}
							if (Rider->getToFloor() < Rider->getFromFloor())
							{
								personDownQueue.push(Rider);
								numPeople = numPeople + 1;
							}
						}
					}
				}
			}
		}
	}

	void emptyUpQueue()
	{
		while (personUpQueue.size() != 0)
		{
			personUpQueue.pop();
		}
	}

	void emptyDownQueue()
	{
		while (personDownQueue.size() != 0)
		{
			personDownQueue.pop();
		}
	}

	void addPersonUp(Person* TEMP)
	{
		personUpQueue.push(TEMP);
	}

	void addPersonDown(Person* TEMP)
	{
		personDownQueue.push(TEMP);
	}

	int getNumPeople()
	{
		return numPeople;
	}

	// DEQUEUES A PERSON GOING UP FROM FLOOR QUEUE

	Person* leaveFloorUp()
	{
		Person* temp = personUpQueue.top();
		personUpQueue.pop();
		numPeople = numPeople - 1;
		return temp;
	}

	// DEQUEUES A PERSON GOING DOWN FROM FLOOR QUEUE

	Person* leaveFloorDown()
	{
		Person* temp = personDownQueue.top();
		personDownQueue.pop();
		numPeople = numPeople - 1;
		return temp;
	}

	void setFloorNumber(int FLOORNUMBER)
	{
		floorNumber = FLOORNUMBER;
	}
	int getFloorNumber()
	{
		return floorNumber;
	}

	// RETURNS THE FIRST PERSON IN UP QUEUE WITHOUT DEQUEUEING

	Person* peekUp()
	{
		return personUpQueue.top();
	}

	// RETURNS THE FIRST PERSON IN DOWN QUEUE WITHOUT DEQUEUEING

	Person* peekDown()
	{
		return personDownQueue.top();
	}

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

	bool isPersonUpQueueEmpty()
	{
		if (personUpQueue.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isPersonDownQueueEmpty()
	{
		if (personDownQueue.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Person* tempRemovePersonUp()
	{
		Person* temp = personUpQueue.top();
		personUpQueue.pop();
		return temp;
	}

	Person* tempRemovePersonDown()
	{
		Person* temp = personDownQueue.top();
		personDownQueue.pop();
		return temp;
	}

private:
	priority_queue <Person*, vector<Person*>, GoingUp> personUpQueue;
	priority_queue <Person*, vector<Person*>, GoingDown> personDownQueue;
	int numPeople;
	int floorNumber;
};
