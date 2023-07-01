/*******************************************************************************
* AUTHOR       : Dillon Welsh
* ASSIGNMENT 4 : Stacks
* CLASS        : CS 8
* SECTION      : 33776
* DUE DATE     : 04/03/2021
*******************************************************************************/

#ifndef PARENMATCH_H
#define PARENMATCH_H

#include "charstack.h"

bool ParenMatch(char [], int );

// Algorithm ParenMatch(X , n):
// Input: An array X of n tokens, each of which is either a grouping symbol, a
// variable, an arithmetic operator, or a number
// Output: true if and only if all the grouping symbols in X match
bool ParenMatch(char X[], int sz)
{
    CharStack myStack;      // IN - stack for paren symbols
    bool match = true;      // IN - bool for match

    // PROCESSING - go throught the char array
    for(int i = 0; i < sz; i++)
    {
        cout << X[i];
        // PROCESSING - add opening parens to stack always
        if(X[i] == '{' || X[i] == '[' || X[i] == '(')
        {
            myStack.push(X[i]);
        }
        // PROCESSING - look for closed parens and decide what to do
        else if(X[i] == '}' || X[i] == ']' || X[i] == ')')
        {
            // PROCESSING - exit and return false if empty stack and closed paren
            if(myStack.isEmpty()) match = false;
            // PROCESSING - pop off top open paren if next paren is a matching closed paren
            else
            {
                if((myStack.top() == '{' && X[i] == '}') ||
                   (myStack.top() == '[' && X[i] == ']') ||
                   (myStack.top() == '(' && X[i] == ')'))
                {
                    myStack.pop();
                }
            }
        }
    }

    // PROCESSING - return true if stack is empty otherwise return false
    if(match == false) return false;
    if(myStack.isEmpty()) return true;
    else return false;
}

#endif // PARENMATCH_H
