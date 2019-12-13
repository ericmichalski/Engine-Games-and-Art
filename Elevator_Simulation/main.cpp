#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Person.h"
#include "Floor.h"
#include "ElevatorCar.h"
#include "WaitingFloors.h"
#include "IncrementTime.h"
#include <queue>
#include <vector>
using namespace std;

// ELEVATOR TRAVEL BETWEEN 2 FLOORS = 10s

// FUNCTION DECLARATORS

void floorToElevator(Floor*, ElevatorCar*, WaitingFloors*);
void elevatorToFloor(Floor*, ElevatorCar*, int*, int*, int*);
void fillFloorsRandomly(Floor**, WaitingFloors*);
void move(Floor**, ElevatorCar*, WaitingFloors*, int*, int*, int*);
void ASCII();


int main()
{
	srand(time(NULL));

	// BUILDS ALL FLOORS AND SINGLE ELEVATOR

	Floor* floor1 = new Floor;
	floor1->setFloorNumber(1);
	Floor* floor2 = new Floor;
	floor2->setFloorNumber(2);
	Floor* floor3 = new Floor;
	floor3->setFloorNumber(3);
	Floor* floor4 = new Floor;
	floor4->setFloorNumber(4);
	Floor* floor5 = new Floor;
	floor5->setFloorNumber(5);
	Floor* floor6 = new Floor;
	floor6->setFloorNumber(6);

	ElevatorCar* elevator = new ElevatorCar;
	elevator->setElevatorNum(1);
	ElevatorCar* elevator2 = new ElevatorCar;
	elevator2->setElevatorNum(2);
	ElevatorCar* elevator3 = new ElevatorCar;
	elevator3->setElevatorNum(3);

	int numElevators = 3;

	Floor* Floors[6] = { floor1, floor2, floor3, floor4, floor5, floor6 };
	WaitingFloors* waitingFloors = new WaitingFloors;
	IncrementTime* incrementTime = new IncrementTime;

	int* totalRiderWaitTime = new int;
	*totalRiderWaitTime = 0;
	int* totalRiderTravelTime = new int;
	*totalRiderTravelTime = 0;
	int* totalRidersServed = new int;
	*totalRidersServed = 0;

	ASCII();
	cout << "\nPress Enter twice to continue";
	fgetc(stdin);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << endl << endl;

	cout << "ELEVATOR START TIME: 9:00am" << endl << endl;

	for (int x = 0; x < 3000; x++)
	{
		
/*_____________ UNCHECK TO FILL ONLY FIRST FLOOR _____________*/

		// Floors[0]->fillFloor(waitingFloors);

/*________________ UNCHECK TO FILL ALL FLOORS ________________*/

		fillFloorsRandomly(Floors, waitingFloors);

		move(Floors, elevator, waitingFloors, totalRidersServed, totalRiderWaitTime, totalRiderTravelTime);
		move(Floors, elevator2, waitingFloors, totalRidersServed, totalRiderWaitTime, totalRiderTravelTime);
		move(Floors, elevator3, waitingFloors, totalRidersServed, totalRiderWaitTime, totalRiderTravelTime);
		incrementTime->incrementTime(Floors, elevator);
	}
	while (!elevator->isPersonUpQueueEmpty() && !elevator->isPersonDownQueueEmpty() && !elevator2->isPersonUpQueueEmpty() && !elevator2->isPersonDownQueueEmpty() && !elevator3->isPersonUpQueueEmpty() && !elevator3->isPersonDownQueueEmpty())
	{
		move(Floors, elevator, waitingFloors, totalRidersServed, totalRiderWaitTime, totalRiderTravelTime);
		move(Floors, elevator2, waitingFloors, totalRidersServed, totalRiderWaitTime, totalRiderTravelTime);
		move(Floors, elevator3, waitingFloors, totalRidersServed, totalRiderWaitTime, totalRiderTravelTime);
		incrementTime->incrementTime(Floors, elevator);
	}

	cout << endl;
	cout << "Elevator End TIME: 5:00 pm" << endl << endl;
	cout << "****************************************************************" << endl;
	cout << "                 Elevator Simulation Statistics" << endl;
	cout << "Start Time: 9:00am" << endl;
	cout << "End Time: 5:00pm" << endl;
	cout << "Total Elevator Travel Time of " << numElevators << " Elevators: " << (elevator->getTotalRunTime() + elevator2->getTotalRunTime() + elevator3->getTotalRunTime()) / 60 << " minutes" << endl;
	cout << "Total Riders Served: " << *totalRidersServed << endl;
	cout << "Average Rider Wait Time: " << *totalRiderWaitTime / *totalRidersServed << " seconds" << endl;
	cout << "Average Rider Travel Time: " << *totalRiderTravelTime / *totalRidersServed << " seconds" << endl;
	cout << "****************************************************************" << endl;

	return 0;
}


// **************************************************************************************
// TAKES RIDERS FROM THE FLOOR INTO THE ELEVATOR UNTIL ELEVATOR IS FULL OR FLOOR IS EMPTY
// **************************************************************************************

void floorToElevator(Floor* FLOOR, ElevatorCar* ELEVATOR, WaitingFloors* WAITINGFLOORS)
{
	if (FLOOR->getNumPeople() != 0)
	{
		if (ELEVATOR->getNumUpPeople() + ELEVATOR->getNumDownPeople() < 10)
		{
			int maxNumTransfer = 10 - (ELEVATOR->getNumUpPeople() + ELEVATOR->getNumDownPeople());
			int actNumTransfer = maxNumTransfer - FLOOR->getNumPeople();
			if (actNumTransfer < 0)
			{
				actNumTransfer = maxNumTransfer;
			}
			else
			{
				actNumTransfer = FLOOR->getNumPeople();
			}
			if (ELEVATOR->getLastFloor() < ELEVATOR->getFloor())
			{
				while (!FLOOR->isPersonUpQueueEmpty() && actNumTransfer != 0)
				{
					ELEVATOR->fillElevatorCar(FLOOR->leaveFloorUp());
					actNumTransfer--;
				}
				if (FLOOR->isPersonUpQueueEmpty())
				{
					while (!FLOOR->isPersonDownQueueEmpty() && actNumTransfer != 0)
					{
						ELEVATOR->fillElevatorCar(FLOOR->leaveFloorDown());
						actNumTransfer--;
					}
				}
				if (FLOOR->isPersonUpQueueEmpty() && FLOOR->isPersonDownQueueEmpty())
				{
					WAITINGFLOORS->deleteFromList(FLOOR->getFloorNumber());
				}
				else if (!FLOOR->isPersonUpQueueEmpty() || !FLOOR->isPersonDownQueueEmpty())
				{
					WAITINGFLOORS->moveToEnd(FLOOR->getFloorNumber());
				}
			}
			else if (ELEVATOR->getLastFloor() > ELEVATOR->getFloor())
			{
				while (!FLOOR->isPersonDownQueueEmpty() && actNumTransfer != 0)
				{
					ELEVATOR->fillElevatorCar(FLOOR->leaveFloorDown());
					actNumTransfer--;
				}
				if (FLOOR->isPersonDownQueueEmpty())
				{
					while (!FLOOR->isPersonUpQueueEmpty() && actNumTransfer != 0)
					{
						ELEVATOR->fillElevatorCar(FLOOR->leaveFloorUp());
						actNumTransfer--;
					}
				}
				if (FLOOR->isPersonUpQueueEmpty() && FLOOR->isPersonDownQueueEmpty())
				{
					WAITINGFLOORS->deleteFromList(FLOOR->getFloorNumber());
				}
				else if (!FLOOR->isPersonUpQueueEmpty() || !FLOOR->isPersonDownQueueEmpty())
				{
					WAITINGFLOORS->moveToEnd(FLOOR->getFloorNumber());
				}
			}
		}
	}
}


// ***************************************************************************************


// ***************************************************************************************
// CHECKS TO SEE IF ELEVATOR IS GOING UP/DOWN, RELEASE RIDERS FROM ELEVATOR TO THEIR FLOOR
// ***************************************************************************************

void elevatorToFloor(Floor* FLOOR, ElevatorCar* ELEVATOR, int* TOTALRIDERSSERVED, int* TOTALRIDERWAITTIME, int* TOTALRIDERTRAVELTIME)
{
	Person* temp = nullptr;
	if (!ELEVATOR->isPersonUpQueueEmpty() || !ELEVATOR->isPersonDownQueueEmpty())
	{
		if (ELEVATOR->getLastFloor() < ELEVATOR->getFloor())
		{
			if (ELEVATOR->peekUp()->getToFloor() == ELEVATOR->getFloor())
			{
				while (!ELEVATOR->isPersonUpQueueEmpty() && ELEVATOR->peekUp()->getToFloor() == ELEVATOR->getFloor())
				{
					temp = ELEVATOR->releaseUpRider();
					*TOTALRIDERSSERVED = *TOTALRIDERSSERVED + 1;
					*TOTALRIDERWAITTIME = *TOTALRIDERWAITTIME + temp->getWaitTime();
					*TOTALRIDERTRAVELTIME = *TOTALRIDERTRAVELTIME + temp->getTravelTime();
					temp = nullptr;
				}
			}
		}
		else if (ELEVATOR->getLastFloor() > ELEVATOR->getFloor())
		{
			if (ELEVATOR->peekDown()->getToFloor() == ELEVATOR->getFloor())
			{
				while (!ELEVATOR->isPersonDownQueueEmpty() && ELEVATOR->peekDown()->getToFloor() == ELEVATOR->getFloor())
				{
					temp = ELEVATOR->releaseDownRider();
					*TOTALRIDERSSERVED = *TOTALRIDERSSERVED + 1;
					*TOTALRIDERWAITTIME = *TOTALRIDERWAITTIME + temp->getWaitTime();
					*TOTALRIDERTRAVELTIME = *TOTALRIDERTRAVELTIME + temp->getTravelTime();
					temp = nullptr;
				}
			}
		}
	}
}
// *************************************************************************************


// ***************************************************************************************
// FILL EACH FLOOR IN A RANDOM ORDER
// ***************************************************************************************

void fillFloorsRandomly(Floor** FLOORS, WaitingFloors* WAITINGFLOORS)
{
	vector <int> floorsFilled;
	int flag = 0;
	int randFloor = rand() % 6;
	FLOORS[randFloor]->fillFloor(WAITINGFLOORS);
	floorsFilled.push_back(randFloor);
	while (floorsFilled.size() < 6)
	{
		randFloor = rand() % 6;
		flag = 0;
		for (int x = 0; x < floorsFilled.size(); x++)
		{
			if (floorsFilled[x] == randFloor)
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			FLOORS[randFloor]->fillFloor(WAITINGFLOORS);
			floorsFilled.push_back(randFloor);
		}
	}
}
// *************************************************************************************


// ***************************************************************************************
// MOVE THE ELEVATOR CAR
// ***************************************************************************************

void move(Floor** FLOORS, ElevatorCar* ELEVATORCAR, WaitingFloors* WAITINGFLOORS, int* TOTALRIDERSSERVED, int* TOTALRIDERWAITTIME, int* TOTALRIDERTRAVELTIME)
{
	elevatorToFloor(FLOORS[ELEVATORCAR->getFloor() - 1], ELEVATORCAR, TOTALRIDERSSERVED, TOTALRIDERWAITTIME, TOTALRIDERTRAVELTIME);
	floorToElevator(FLOORS[ELEVATORCAR->getFloor() - 1], ELEVATORCAR, WAITINGFLOORS);
	if (!ELEVATORCAR->isPersonUpQueueEmpty())
	{
		ELEVATORCAR->setLastFloor();
		ELEVATORCAR->setFloor(ELEVATORCAR->getFloor() + 1);
		ELEVATORCAR->setTotalRunTime(10);
		cout << "ELEVATOR " << ELEVATORCAR->getElevatorNum() << " AT FLOOR: " << ELEVATORCAR->getFloor() << endl;
	}
	else if (!ELEVATORCAR->isPersonDownQueueEmpty())
	{
		ELEVATORCAR->setLastFloor();
		ELEVATORCAR->setFloor(ELEVATORCAR->getFloor() - 1);
		ELEVATORCAR->setTotalRunTime(10);
		cout << "ELEVATOR " << ELEVATORCAR->getElevatorNum() << " AT FLOOR: " << ELEVATORCAR->getFloor() << endl;
	}
	else if (WAITINGFLOORS->size() >= 1)
	{
		if (WAITINGFLOORS->peek() < ELEVATORCAR->getFloor())
		{
			ELEVATORCAR->setLastFloor();
			ELEVATORCAR->setFloor(ELEVATORCAR->getFloor() - 1);
			ELEVATORCAR->setTotalRunTime(10);
			cout << "ELEVATOR " << ELEVATORCAR->getElevatorNum() << " AT FLOOR: " << ELEVATORCAR->getFloor() << endl;
		}
		else
		{
			ELEVATORCAR->setLastFloor();
			ELEVATORCAR->setFloor(ELEVATORCAR->getFloor() + 1);
			ELEVATORCAR->setTotalRunTime(10);
			cout << "ELEVATOR " << ELEVATORCAR->getElevatorNum() << " AT FLOOR: " << ELEVATORCAR->getFloor() << endl;
		}
	}
	else
	{
		ELEVATORCAR->setTotalRunTime(10);
	}
}
// *************************************************************************************


// ***************************************************************************************
// PRINTS ASCII INTRO
// ***************************************************************************************

void ASCII()
{
	cout << " ***********************************************************************************************************************" << endl;
	cout << " _____   _                         _                    _____   _                       _           _" << endl;
	cout << " | ___| | |                       | |                  /  ___| (_)                     | |         | |" << endl;
	cout << " | |__  | |  ___  __   __  __  _  | |_    ___    _ __  \\ `--.   _   _ __ ___    _   _  | |   __ _  | |_    ___    _ __" << endl;
	cout << " | __|  | | / _ \\ \\ \\ / / /  _` | | __| /  _  \\ | '__|  `--. \\ | | | '_ ` _ \\  | | | | | |  / _` | | __| /  _  \\ | '__|" << endl;
	cout << " | |___ | | | __/  \\ \V /  | (_| | | |_  | (_) | | |    /\\__/ / | | | | | | | | | |_| | | | | (_| | | |_  | (_) | | |" << endl;
	cout << " \\____/ |_| \\___|   \\_/   \\__ ,_|  \\__| \\ ___ / |_|    \\____/  |_| |_| |_| |_|  \\__,_| |_|  \\__,_| \\__|  \\ ___ / |_|" << endl;
	cout << " ***********************************************************************************************************************" << endl << endl;
	cout << "			This simulation models daily elevator usage in a 6 floor building" << endl;
}
// *************************************************************************************
