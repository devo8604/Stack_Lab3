//*************************************************************************
// TITLE: 			   	STL Stack Lab
// FILENAME:            SeatingList.h
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
//=================================================================
//                        CLASS DESCRIPTION
//  This class handles the building and sorting of the guest list
//
//*******************************************************************************
//
//*******************************************************************************
//              PROCESS THIS FILE ONLY ONCE PER PROJECT
//
#ifndef __Stack_Lab3__SeatingList__
#define __Stack_Lab3__SeatingList__
//
//======================================================================
//                     CONSTANT DEFINITIONS
//
//*******************************************************************************
//                  STANDARD AND USER DEFINED INCLUDES
#include "GuestList.h"
#include <iostream>
#include <vector>
#include <Stack>
//*******************************************************************************
//                     USER DEFINED DATA TYPES
class SeatingList
{
public:
    //Generates and sorts a vector of salesmen
    void guestListGenerator(std::vector<GuestList>& initialList);
    
    //Separates the vector of people in vector stacks
    void stackBuilder(std::vector<GuestList>& initialList,
                      std::stack<GuestList, std::vector<GuestList>>& leftSideOfTable,
                      std::stack<GuestList, std::vector<GuestList>>& rightSideOfTable);
    
    //Sorts the right side of table stack so that it can be displayed properly
    void rightSideOfTableSorter(std::stack<GuestList, std::vector<GuestList>>& rightSideOfTable,
                                std::stack<GuestList, std::vector<GuestList>>& rightSideOfTableSorted);
};
//*******************************************************************************
//                    END OF CONDITIONAL BLOCK
#endif /* defined(__Stack_Lab3__SeatingList__) */
//*******************************************************************************
//                      END OF HEADER FILE
//*******************************************************************************