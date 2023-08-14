// File: LinkedList.h
// Author: Josh
// Date: 08/10/2023
// Description: Header file for linked list-based elevator simulation.

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node {
public:
    int data;
    Node* next;

    Node(int value); // Constructor declaration for the Node class.
};

class LinkedList {
private:
    Node* head; // Private member: pointer to the first node in the linked list.

public:
    // Constructor: Initializes the object with provided values.
    LinkedList(); // Constructor declaration for the LinkedList class.
    ~LinkedList(); // Destructor declaration for the LinkedList class.
     // Destructor: Cleans up resources and performs necessary actions when the object is destroyed.

    void insertFront(int value); // Inserts a new node at the front of the list.
    void insertAny(int value);
    void remove(int value);
    bool contains(int value);
    bool isEmpty() const;
    void displayRequests(); // Displays the state of elevator requests.
    // Other methods you want to include
};

#endif // LINKEDLIST_H
