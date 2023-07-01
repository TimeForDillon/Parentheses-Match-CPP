/*******************************************************************************
* AUTHOR       : Dillon Welsh
* ASSIGNMENT 4 : Stacks
* CLASS        : CS 8
* SECTION      : 33776
* DUE DATE     : 04/03/2021
*******************************************************************************/

#include "charstack.h"

/*******************************************************************************
* CONSTRUCTOR CharStack
*_______________________________________________________________________________
* This constructor constructs an empty char stack.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

CharStack::CharStack()
{
    this->head = nullptr;
    this->tail = nullptr;
}

/*******************************************************************************
* DESTRUCTOR CharStack
*_______________________________________________________________________________
* This destructs the CharStack object and deallocated memory.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

CharStack::~CharStack()
{
    CharNode* temporaryNode = this->head;       // IN - set the temp to head
    CharNode* currentNode = nullptr;            // IN - empty node

    // PROCESSING - go through stack and delete memory
    while(temporaryNode != nullptr)
    {
        currentNode = temporaryNode;
        temporaryNode = temporaryNode->next;
        delete currentNode;
    }

    // PROCESSING - set head and tail to null
    this->head = nullptr;
    this->tail = nullptr;
}

/*******************************************************************************
* MUTATOR push(char value)
*_______________________________________________________________________________
* This method adds a new CharNode with the given char value and places it at the
* head
*_______________________________________________________________________________
* PRE-CONDITIONS
* char value
*
* POST-CONDITIONS
* None
*******************************************************************************/

void CharStack::push(char value)
{
    CharNode *newNode = new CharNode(value);        // IN - new node
    newNode->next = nullptr;

    // PROCESSING - add to head if head is currently null
    if(this->head == nullptr)
    {
        this->head = newNode;
        this->tail = head;
    }
    // PROCESSING - shift head if head is not null
    else
    {
        newNode->next = this->head;
        this->head = newNode;
    }
}

/*******************************************************************************
* MUTATOR pop()
*_______________________________________________________________________________
* This method removes the front node from the stack
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/
void CharStack::pop()
{
    // PROCESSING - case with one element
    if(this->head == this->tail && this->head != nullptr)
    {
        this->head = nullptr;
        delete this->tail;
        this->tail = nullptr;
    }
    // PROCESSING - shift head by one
    else if(this->head != nullptr)
    {
        CharNode * temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}

/*******************************************************************************
* ACCESSOR top() const
*_______________________________________________________________________________
* This method returns the char value at the top of the stack
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* char
*******************************************************************************/
char CharStack::top() const
{
    // PROCESSING - return the top
    return this->head->data;
}

/*******************************************************************************
* ACCESSOR isEmpty()
*_______________________________________________________________________________
* This method returns true if the stack is empty
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* bool
*******************************************************************************/
bool CharStack::isEmpty()
{
    // PROCESSING - returns true if empty otherwise false
    if(this->head == nullptr && this->tail == nullptr) return true;
    else return false;
}

/*******************************************************************************
* ACCESSOR display() const
*_______________________________________________________________________________
* This method displays the stack
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* void
*******************************************************************************/
void CharStack::display() const
{
    CharNode * temp = this->head;

    //PROCESSING - display the elements of the list.
    while(temp != nullptr)
    {
        cout << temp->data;
        // PROCESSING - checks if this is the last pointer
        if (temp->next != nullptr) cout << " ";
        temp = temp->next;
    }
}
