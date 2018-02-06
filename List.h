#pragma once

//***********************************************************************************
//  Linked-List
//  CSS 342 Program-6
//
//  Created by Fahad Alshehri on November 25, 2017.
//  An implementation of a LinkedList.
//***********************************************************************************


#include <iostream>

using namespace std;


//***********************************************************************************
// Object data type for the Node's data.
// makes the Node be able to hold any kind of data 
//***********************************************************************************
struct Object {
	int data;
};

//-----------------------------------------------------------------------------------
// Enables the object to be printed to the console. Instead of printing memroy address
//------------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& ostr, const Object& ls) {
	return ostr << ls.data;
}

//***********************************************************************************
// Node structs contain data and a pointer to the next node.
//***********************************************************************************
struct Node {
	Object *data;
	Node *next;
};

//***********************************************************************************
// LinkedList is a list of singly-linked nodes.
//***********************************************************************************
class List {

private:
	// Head of the list contains no data, but points to the list.
	Node *head;
public:

	// method prototyping for of the linked-list methods
	List();
	List(const List &anotherList);
	~List();
	void append(Object &data);
	void insert(Object &data, int position);
	void Delete(int position);
	int size();
	void clear();
	bool isEmpty();
	void print();
	Node* reverseIterative(Node *head);
	Node* getHead();
	void reverseRecursive(Node* current);
	int find(Object &findThis);
};

//------------------------------------------------------------------------
// Deafut constructor that sets the head to NULL
//-----------------------------------------------------------------------
List::List() {

	head = NULL;
}

//----------------------------------------------------------------------
// Creates another linked-list with another linked-list of the same class
//----------------------------------------------------------------------
List::List(const List & obj) {
	if (this != &obj) {
		clear();
	}

	//creating a new node as the head of the other linked-list
	Node *current = obj.head;

	//traversing through the linked-list 
	while (current != NULL) {
		append(*current->data);
		current = current->next;
	}
}

//-------------------------------------------------------------------
// Destructor de-allocates memory used by the list
//------------------------------------------------------------------
List::~List()
{
	cout << "Desturctor got called " << endl;
	// a method that cleans up memroy 
	clear();
}


//----------------------------------------------------------------------------------------------
// Reverses a linked-list iteratively
//--------------------------------------------------------------------------------------------
Node* List::reverseIterative(Node *head) {
	// creating three pointers to keep track of out nodes  
	Node *prev = NULL;
	Node *current = head;
	Node *next;
	// traversing the linked-list until we reached the end 
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	this->head = prev;
	// returning the new position of the head after manupulating pointers
	return this->head;

}

//----------------------------------------------------------------------------------------------
// Reverses a linked-list recursively 
//--------------------------------------------------------------------------------------------
void List::reverseRecursive(Node* current) {
	// a flag that tells me when I reach the end of the linked-list
	bool pointToNull = false;
	if (current == head) {
		pointToNull = true;
	}
	if (current->next != NULL) {
		//keep travering by calling recursively
		reverseRecursive(current->next);
		current->next->next = current;
		//when I reach the end make the last node point to NULL
		if (pointToNull == true) {
			current->next = NULL;
		}
	}
	else {
		head = current;
	}
}
//----------------------------------------------------------------------------------------------
// Finds the node's data and returns the index that it is located in 
//--------------------------------------------------------------------------------------------
int List::find(Object &findThis) {
	Node *current = this->head;
	int counter = 1;
	// traversing through the linked-list and stop when we find the correct object
	while (current != NULL) {
		if (current->data->data == findThis.data) {
			return counter; // returning the index that we found the data at
		}
		counter++;
		current = current->next;
	}

	return 0;
}

//--------------------------------------------------------------------
// A helper method for getter the head 
//------------------------------------------------------------------
Node* List::getHead() {
	return head;
}

//----------------------------------------------------------------------
// Adds a node with a given data at the end of the linked-list
//----------------------------------------------------------------------
void List::append(Object &d)
{
	//making a new Node to add 
	Node *newNode = new Node();
	newNode->data = &d;
	newNode->next = NULL;
	// in case if it is the first node, we lit it be the head
	if (head == NULL) {
		this->head = newNode;
	}
	else {
		// if not the first, node then we traverse until we find the last 
		Node *cur = head;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		//append the newNode at the last position
		cur->next = newNode;
	}
}
//---------------------------------------------------------------------
// Adds a node to the list at a given position 
// Takes a node and list position as parmeters 
// Position must be between 1 and the number of data nodes
//----------------------------------------------------------------------
void List::insert(Object &data, int position) {

	//Validating that the user enters the correct position
	if ((position > size() + 1) || position < 1) {
		cout << "Error: the given position is out of range." << endl;
		return;
	}

	//creating a new node to insert at a valid position 
	Node *newNode = new Node();
	newNode->data = &data;

	//If we are inserting at an empty linked-list
	if (head == NULL || size() == 0) {
		head = newNode;
		return;
	}

	//Keeping track at the index before the position we want to insert at 
	Node * prev = head;
	int count = 1;
	while (count < position - 1) {
		prev = prev->next;
		count++;
	}
	// Manupulating pointers to let the connection between the nodes work 
	Node *cur = prev->next;
	newNode->next = cur;
	prev->next = newNode;

}

//-------------------------------------------------------------------------
//to check wether a linked-list is empty or not
// return 1 if true, returns 0 if false
//-----------------------------------------------------------------------
bool List::isEmpty()
{
	if (head == NULL) {
		return true;
	}

	return false;
}

//-------------------------------------------------------------------------
// De-allocated memory for every single node 
// Mainly used to be called in the destructor 
//------------------------------------------------------------------------
void List::clear()
{
	Node *cur = head;
	// traversing through out the linked-list to delete each node
	while (cur != NULL) {
		Node *next = cur->next;
		delete cur;
		cur = next;
	}
	head = NULL;
}


//----------------------------------------------------------------------
// Deletes a node by its given position 
// For example, position 1 for the first index 
// Handels inveriants and edge cases
//----------------------------------------------------------------------
void List::Delete(int position) {

	// validating a correct position to delete. Otherwise, will send a message 
	if ((position < 1) || (position > size()))
	{
		cout << "Error: the given position is out of range." << endl;
		return;
	}

	// validating if we are deleting at an empty position
	if (head == NULL)
	{
		cout << "Error: there is nothing to remove." << endl;
		return;
	}

	//In case if its the first Node, 
	if (position == 1) {
		Node *temp = head; // save the 1st Node in temp
		head = head->next; // point head to the node next to it
		delete temp;	   // delete the 1st Node
		return;
	}
	else {
		Node * prev = head;
		int counter = 1;
		//traversing until we find the correct position to remove
		while (counter < position - 1) {
			prev = prev->next;
			counter++;
		}
		// manupulating pointers 
		Node * current = prev->next;
		prev->next = current->next;
		current->next = NULL;
		//deleting the index to manage memeory 
		delete current->next;
	}
}

//---------------------------------------------------------------
// Prints each node in the linked-list in consecutive order
// print data to the console. 
//--------------------------------------------------------------
void List::print() {
	// validate to avoid printing an empty node
	if (head == NULL) {
		cout << "The LinkedList is empty " << endl;
		return;
	}
	Node *current = head;
	while (current != NULL) {
		cout << *current->data << endl;
		current = current->next;
	}
}


//-------------------------------------------------------------------
// returns the size of the linked-list
//-----------------------------------------------------------------
int List::size() {
	int size = 0; // a counter to keep track of size
	if (head == NULL) {
		return size;
	}

	Node *current = head;
	while (current != NULL) {
		size++; // incremnting it unti the last node
		current = current->next;
	}
	return size;
}