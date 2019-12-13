#pragma once
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "Floor.h"
using namespace std;

class WaitingFloors
{
public:
	void addElement(int x)
	{
		int flag = 0;
		for (int y = 0; y < waitingFloors.size(); y++)
		{
			if (waitingFloors[y] == x)
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			waitingFloors.push_back(x);
		}
	}
	int removeElement()
	{
		int temp = waitingFloors[0];
		waitingFloors.erase(waitingFloors.begin());
		return temp;
	}
	int size()
	{
		return waitingFloors.size();
	}
	int peek()
	{
		return waitingFloors.front();
	}
	void deleteFromList(int FLOORNUMBER)
	{
		// REMOVES ELEMENTS OF WAITINGFLOORS BY VALUE == TO FLOORNUMBER

		waitingFloors.erase(remove(waitingFloors.begin(), waitingFloors.end(), FLOORNUMBER), waitingFloors.end());
	}
	void moveToEnd(int FLOORNUMBER)
	{
		waitingFloors.erase(remove(waitingFloors.begin(), waitingFloors.end(), FLOORNUMBER), waitingFloors.end());
		waitingFloors.push_back(FLOORNUMBER);
	}
	void printWaitingFloors()
	{
		cout << "<";
		for (int x = 0; x < waitingFloors.size(); x++)
		{
			cout << waitingFloors[x];
		}
		cout << ">" << endl;
	}
private:
	vector <int> waitingFloors;
};
