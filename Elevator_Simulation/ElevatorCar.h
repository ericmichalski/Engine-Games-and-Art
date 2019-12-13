#pragma once
#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "Floor.h"
#include "Person.h"
#include "WaitingFloors.h"
using namespace std;

// MAX NUM PEOPLE ON A SINGLE FLOOR = 6

class ElevatorCar
{
public:
	ElevatorCar()
	{
		floor = 1;
		numPeopleDown = 0;
		numPeopleUp = 0;
		lastFloor = 0;
		totalRunTime = 0;
	}

	void fillElevatorCar(Person* RIDER)
	{
		if (personUpQueue.size() + personDownQueue.size() < 10)
		{
			if (RIDER->getToFloor() > getFloor())
			{
				cout << "Person ID: " << RIDER->getID() << " getting on elevator " << getElevatorNum() << " from floor: " << RIDER->getFromFloor() << " going up to floor: " << RIDER->getToFloor() << endl;
				personUpQueue.push(RIDER);
			}
			else
			{
				cout << "Person ID: " << RIDER->getID() << " getting on elevator " << getElevatorNum() << " from floor: " << RIDER->getFromFloor() << " going down to floor: " << RIDER->getToFloor() << endl;
				personDownQueue.push(RIDER);
			}
		}
		numPeopleUp = personUpQueue.size();
		numPeopleDown = personDownQueue.size();
	}

	void fillUpQueue(Person* TEMP)
	{
		personUpQueue.push(TEMP);
	}

	void fillDownQueue(Person* TEMP)
	{
		personDownQueue.push(TEMP);
	}

	Person* releaseUpRider()
	{
		cout << "Rider ID: " << peekUp()->getID() << " exited on floor: " << getFloor() << endl;
		Person* temp = personUpQueue.top();
		personUpQueue.pop();
		numPeopleUp = personUpQueue.size();
		numPeopleDown = personDownQueue.size();
		return temp;
	}

	Person* releaseDownRider()
	{
		cout << "Rider ID: " << peekDown()->getID() << " exited on floor: " << getFloor() << endl;
		Person* temp = personDownQueue.top();
		personDownQueue.pop();
		numPeopleUp = personUpQueue.size();
		numPeopleDown = personDownQueue.size();
		return temp;
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

	void setFloor(int FLOOR)
	{
		floor = FLOOR;
	}

	void setLastFloor()
	{
		lastFloor = floor;
	}

	void setElevatorNum(int NUM)
	{
		elevatorNumber = NUM;
	}

	int getElevatorNum()
	{
		return elevatorNumber;
	}

	int getFloor()
	{
		return floor;
	}

	int getNumUpPeople()
	{
		return numPeopleUp;
	}

	int getNumDownPeople()
	{
		return numPeopleDown;
	}

	Person* peekUp()
	{
		return personUpQueue.top();
	}

	Person* peekDown()
	{
		return personDownQueue.top();
	}

	int getLastFloor()
	{
		return lastFloor;
	}

	void setTotalRunTime(int x)
	{
		totalRunTime = totalRunTime + x;
	}

	int getTotalRunTime()
	{
		return totalRunTime;
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

private:
	priority_queue <Person*, vector<Person*>, GoingUp> personUpQueue;
	priority_queue <Person*, vector<Person*>, GoingDown> personDownQueue;
	int floor;
	int numPeopleUp;
	int numPeopleDown;
	int lastFloor;
	int totalRunTime;
	int elevatorNumber;
};
