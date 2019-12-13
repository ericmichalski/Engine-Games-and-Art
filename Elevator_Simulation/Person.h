#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;



class Person
{
public:

	// CONSTRUCTOR SETS ALL MEMBER VARIABLES TO 0, AND A RANDOM 4 DIGIT ID NUMBER

	Person()
	{
		fromFloor = 0;
		toFloor = 0;
		id = rand() % 9000 + 1000;
		waitTime = 0;
		travelTime = 0;
	}

	int getID()
	{
		return id;
	}

	int getFromFloor()
	{
		return fromFloor;
	}

	int getToFloor()
	{
		return toFloor;
	}

	int getWaitTime()
	{
		return waitTime;
	}

	int getTravelTime()
	{
		return travelTime;
	}

	void setID(int ID)
	{
		id = ID;
	}

	void setFromFloor(int FROMFLOOR)
	{
		fromFloor = FROMFLOOR;
	}

	void setToFloor(int FROMFLOOR)
	{
		flag = 0;
		while (toFloor == FROMFLOOR || flag == 0)
		{
			if (flag == 0)
			{
				flag = 1;
			}
			toFloor = rand() % 6 + 1;
		}
	}

	void setWaitTime(int WAITTIME)
	{
		waitTime = WAITTIME;
	}

	void setTravelTime(int TRAVELTIME)
	{
		travelTime = TRAVELTIME;
	}

	int toFloor;

private:
	int id;
	int fromFloor;
	int waitTime;
	int travelTime;
	int flag = 0;
};
