// File: LinkedList.cpp
// Author: Josh
// Date: 08/10/2023
// Description: Implementation file for linked list-based elevator simulation.

#include "LinkedList.h"
#include <iostream> // Include this header for using std::cout

// Node constructor
Node::Node(int value) : data(value), next(nullptr) {
    // Constructor code for Node class
}

// LinkedList constructor
LinkedList::LinkedList() : head(nullptr) {
    // Constructor code for LinkedList class
}

// LinkedList destructor
LinkedList::~LinkedList() {
    // Destructor code for LinkedList class
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Method to insert a new node at the front of the list
void LinkedList::insertFront(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAny(int value) {
    Node* newNode = new Node(value);

    // If the list is empty, just make the new node the head
    if (!head) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next) {
        if (current->data == value) {
            newNode->next = current->next;
            current->next = newNode;
            return;  // Inserted, so return
        }
        current = current->next;
    }

    // If the value was not found in the existing nodes, append it to the end
    current->next = newNode;
}


void LinkedList::displayRequests() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << "Floor: " << current->data << std::endl;
        current = current->next;
    }
}


// Method to remove a node with a specific value from the list
void LinkedList::remove(int value) {
    if (!head) {
        return; // List is empty
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    }
}

// Method to check if a specific value exists in the list
bool LinkedList::contains(int value) {
    Node* current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool LinkedList::isEmpty() const {
    return head == nullptr;
}