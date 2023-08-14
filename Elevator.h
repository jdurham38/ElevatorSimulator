// File: Elevator.h
// Author: Josh
// Date: 08/10/2023
// Description: 
//_________________________________________________________________________________________________________________



#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "LinkedList.h"
#include "Floor.h"

class Elevator {
private:
    int currentFloor;
    int direction;  // -1 for down, 0 for idle, 1 for up
    LinkedList requests;
    int totalFloors; // Add totalFloors here
    Floor* floors;   // An array of Floor objects

public:
    Elevator(Floor* floorsArray, int totalFloors);
    
    void addRequest(int floor);
    void move();
    void displayStatus();
    int getCurrentFloor() const;
};

#endif // ELEVATOR_H

