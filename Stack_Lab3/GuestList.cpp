//*************************************************************************
// TITLE: 			   	   STL Stack Lab
// FILENAME:               GuestList.cpp
// PREPARED FOR:           CS230
// PROGRAMMER(S):          Devon J. Smith
// DEVELOPMENT DATE:       07/21/14
// COMPILER USED:          Apple LLVM Version 5.1
// TARGET PLATFORM:        Mac OS X i386 & x86_64
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
#include "GuestList.h"

using namespace std;
//*******************************************************************************
//             Definition of member functions for class Entry
//*******************************************************************************
string name;
string sex;
int salesAmount;

GuestList::GuestList(string name, string sex, int salesAmount)
{
    setName(name);
    setSex(sex);
    setSalesAmount(salesAmount);
}

string GuestList::getName()
{
    return name;
}

string GuestList::getSex()
{
    return sex;
}

int GuestList::getSalesAmount()
{
    return salesAmount;
}

void GuestList::setName(string input)
{
    name = input;
}

void GuestList::setSex(string input)
{
    sex = input;
}

void GuestList::setSalesAmount(int input)
{
    salesAmount = input;
}



