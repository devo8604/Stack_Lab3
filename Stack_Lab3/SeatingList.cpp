//*************************************************************************
// TITLE: 			   	STL Stack Lab
// FILENAME:            SeatingList.cpp
// PREPARED FOR:        CS230
// PROGRAMMER(S):       Devon J. Smith
// DEVELOPMENT DATE:    07/21/14
// COMPILER USED:       Apple LLVM Version 5.1
// TARGET PLATFORM:     Mac OS X i386 & x86_64
//=================================================================
//                           PROJECT FILES
//    <LIST ALL PROGRAM AND HEADER FILES IN THE PROJECT HERE>
//		lab3.cpp (main)
//		SeatingList.h
//		SeatingList.cpp
//		GuestList.h
//		GuestList.cpp
//=================================================================
//   		REVISION HISTORY
//   List revisions made to the Program
//
//   DATE     PROGRAMMER            DESCRIPTION OF CHANGES MADE
//	 07/21/14 Devon J. Smith        Original
//
//*******************************************************************************
//                               CONSTANTS
//
//*******************************************************************************
//                  STANDARD AND USER DEFINED INCLUDES
#include "SeatingList.h"
#include "GuestList.h"
#include <vector>
#include <stack>
#include <time.h>

using namespace std;
//*******************************************************************************
//             Definition of member functions for class Entry
//*******************************************************************************
bool inistialListSort(GuestList &lhs,
                      GuestList &rhs)
{
    return lhs.GuestList::getSalesAmount() > rhs.GuestList::getSalesAmount();
}

void SeatingList::guestListGenerator(vector<GuestList>& initialList)
{
    double sales = 0.0;
    int sex;
    srand((unsigned) time(NULL));
    
    for (int i = 0; i < 100; i++)
    {
        sales = rand() %1000;
        sex = rand() %10;
        if (sex > 5)
        {
            initialList.insert(initialList.end(), GuestList("Gentlemen Salesman", "Male", sales));
        }
        else
        {
            initialList.insert(initialList.end(), GuestList("Lady Salesman", "Female", sales));
        }
    }
    sort(initialList.begin(), initialList.end(), inistialListSort);
} //END guestListGenerator

void SeatingList::stackBuilder(vector<GuestList>& initialList,
                               stack<GuestList, vector<GuestList>>& leftSideOfTable,
                               stack<GuestList, vector<GuestList>>& rightSideOfTable)
{
    while (!initialList.empty() && leftSideOfTable.size() < 50)
    {
        for (vector<GuestList>::iterator itr = initialList.begin(); itr != initialList.end(); ++itr)
        {
            if (itr->GuestList::getSex() == "Male") {
                leftSideOfTable.push(*itr);
                initialList.erase(itr);
                break;
            }
        }
        for (vector<GuestList>::iterator itr = initialList.begin(); itr != initialList.end(); ++itr)
        {
            if (itr->GuestList::getSex() == "Female") {
                leftSideOfTable.push(*itr);
                initialList.erase(itr);
                break;
            }
        }
        for (vector<GuestList>::iterator itr = initialList.begin(); itr != initialList.end(); ++itr)
        {
            if (itr->GuestList::getSex() == "Female") {
                rightSideOfTable.push(*itr);
                initialList.erase(itr);
                break;
            }
        }
        for (vector<GuestList>::iterator itr = initialList.begin(); itr != initialList.end(); ++itr)
        {
            if (itr->GuestList::getSex() == "Male") {
                rightSideOfTable.push(*itr);
                initialList.erase(itr);
                break;
            }
        }

    }
} //END stackBuilder

void SeatingList::rightSideOfTableSorter(stack<GuestList, vector<GuestList>>& rightSideOfTable,
                                         stack<GuestList, vector<GuestList>>& rightSideOfTableSorted)
{
    while (!rightSideOfTable.empty()) {
        rightSideOfTableSorted.push(rightSideOfTable.top());
        rightSideOfTable.pop();
    }
} //END rightSideOfTableSorter






