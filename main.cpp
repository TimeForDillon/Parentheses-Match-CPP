/*******************************************************************************
* AUTHOR       : Dillon Welsh
* ASSIGNMENT 4 : Stacks
* CLASS        : CS 8
* SECTION      : 33776
* DUE DATE     : 04/03/2021
*******************************************************************************/

#include <iostream>
#include <vector>
#include <fstream>
#include "ParenMatch.h"

using namespace std;

vector<string> fileData;    // IN - vector storing string line data from txt file

/*******************************************************************************
* bool fileLoader(string fileName)
*_______________________________________________________________________________
* This function pulls text lines from a text file and stores them in a string
* vector
*_______________________________________________________________________________
* PRE-CONDITIONS
* string fileName
*
* POST-CONDITIONS
* bool
*******************************************************************************/
bool fileLoader(string fileName)
{
    ifstream myFile(fileName);
    string fileLine;

    // PROCESSING - if file opens pull data and return true
    if(myFile.is_open())
    {
        while(getline(myFile, fileLine))
        {
            fileData.push_back(fileLine);
        }

        myFile.close();
        return true;
    }
    // PROCESSING - if file doesn't open return false
    else return false;
}

int main()
{
    string fileName;

    cout << "Enter name of input file: ";
    cin >> fileName;

    // PROCESSING - if file extract is successful
    if(fileLoader(fileName))
    {
        char myArray1[fileData[0].size()];
        char myArray2[fileData[1].size()];
        char myArray3[fileData[2].size()];
        char myArray4[fileData[3].size()];
        char myArray5[fileData[4].size()];

        // PROCESSING - push string data into char array
        for(int i = 0; i < int(fileData[0].size()); i++)
        {
            myArray1[i] = fileData[0][i];
        }
        for(int i = 0; i < int(fileData[1].size()); i++)
        {
            myArray2[i] = fileData[1][i];
        }
        for(int i = 0; i < int(fileData[2].size()); i++)
        {
            myArray3[i] = fileData[2][i];
        }
        for(int i = 0; i < int(fileData[3].size()); i++)
        {
            myArray4[i] = fileData[3][i];
        }
        for(int i = 0; i < int(fileData[4].size()); i++)
        {
            myArray5[i] = fileData[4][i];
        }

        // PROCESSING - check if paren match is successful
        if(ParenMatch(myArray1, fileData[0].size()))
        {
            cout << " has matching parentheses" << endl;
        } else cout << " does not have matching parentheses" << endl;
        if(ParenMatch(myArray2, fileData[1].size()))
        {
            cout << " has matching parentheses" << endl;
        } else cout << " does not have matching parentheses" << endl;
        if(ParenMatch(myArray3, fileData[2].size()))
        {
            cout << " has matching parentheses" << endl;
        } else cout << " does not have matching parentheses" << endl;
        if(ParenMatch(myArray4, fileData[3].size()))
        {
            cout << " has matching parentheses" << endl;
        } else cout << " does not have matching parentheses" << endl;
        if(ParenMatch(myArray5, fileData[4].size()))
        {
            cout << " has matching parentheses" << endl;
        } else cout << " does not have matching parentheses" << endl;
    }
    else
        cout << "No file exists." << endl;

    return 0;
}

