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
//  This class builds the GuestList object
//
//*******************************************************************************
//
//*******************************************************************************
//              PROCESS THIS FILE ONLY ONCE PER PROJECT
//
#ifndef __Stack_Lab3__GuestList__
#define __Stack_Lab3__GuestList__
//
//======================================================================
//                     CONSTANT DEFINITIONS
//
//*******************************************************************************
//                  STANDARD AND USER DEFINED INCLUDES
#include <iostream>
//*******************************************************************************
//                     USER DEFINED DATA TYPES
class GuestList
{
public:
    //Constructor
    GuestList(std::string name,
              std::string sex,
              int salesAmount);
    
    //Getters
    std::string getName();
    std::string getSex();
    int getSalesAmount();
    
private:
    //Variables
    std::string name;
    std::string sex;
    int salesAmount;
    
    //Setters
    void setName(std::string input);
    void setSex(std::string input);
    void setSalesAmount(int input);
};
//*******************************************************************************
//                    END OF CONDITIONAL BLOCK
#endif /* defined(__Stack_Lab3__GuestList__) */
//*******************************************************************************
//                      END OF HEADER FILE
//*******************************************************************************