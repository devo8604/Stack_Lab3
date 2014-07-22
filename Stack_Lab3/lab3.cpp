//*************************************************************************
// TITLE: 			   	STL Stack Lab
// FILENAME:            lab3.cpp
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
//
//=================================================================
//   			PROGRAM DESCRIPTION
//
// This program builds a list of 100 salesmen. The list is then sorted by earnings, highest to lowest.
// Then the names are split up between two stacks alternating between male and female. Then the list is
// output, putting the guest speaker in the middle and putting 50 salesmen on each side of him with the
// high earners being seated closest to him.
//
// INPUTS: NONE
//
// OUTPUTS:  The seating list
//
//=================================================================
//                          INCLUDE FILES
#include "SeatingList.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
//
//=================================================================
//                        CONSTANT DEFINITIONS
//                             NONE
//
//=================================================================
//                      EXTERNAL CLASS VARIABLES
//                          NONE
//=================================================================
//
//*************************************************************************
//                     BEGINNING OF PROGRAM CODE
//*************************************************************************
int main(int argc, const char * argv[])
{
    //Variables
    SeatingList seatingList;
    vector<GuestList> initialList;
    stack<GuestList, vector<GuestList>> leftSideOfTable;
    stack<GuestList, vector<GuestList>> rightSideOfTable;
    stack<GuestList, vector<GuestList>> rightSideOfTableSorted;
    
    
    //Builds and sorts seating list
    seatingList.guestListGenerator(initialList);
    seatingList.stackBuilder(initialList, leftSideOfTable, rightSideOfTable);
    seatingList.rightSideOfTableSorter(rightSideOfTable, rightSideOfTableSorted);
    
    
    //Creates output of seating list
    cout << "Here is the assigned table seating: " << endl << endl;
    while (!leftSideOfTable.empty()) {
        cout << "NAME: " << leftSideOfTable.top().getName() << " SEX: " << leftSideOfTable.top().getSex() << " AMOUNT IN SALES: $" << leftSideOfTable.top().getSalesAmount() << endl;
        leftSideOfTable.pop();
    }
    cout << endl << "Don Juan, the guest speaker, sits here." << endl << endl;
    
    while (!rightSideOfTableSorted.empty()) {
        cout << "NAME: " << rightSideOfTableSorted.top().getName() << " SEX: " << rightSideOfTableSorted.top().getSex() << " AMOUNT IN SALES: $" << rightSideOfTableSorted.top().getSalesAmount() << endl;
        rightSideOfTableSorted.pop();
    }
    return 0;
}
//=================================================================
//                     PROGRAM OUTPUT
//
/*
 Here is the assigned table seating:
 
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $92
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $114
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $132
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $150
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $185
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $232
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $264
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $290
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $329
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $6
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $365
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $43
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $379
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $95
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $398
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $179
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $435
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $191
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $452
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $235
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $456
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $285
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $475
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $326
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $504
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $344
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $516
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $363
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $554
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $367
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $598
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $386
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $605
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $454
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $646
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $485
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $692
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $598
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $706
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $631
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $725
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $713
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $757
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $759
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $838
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $810
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $922
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $880
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $974
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $995
 
 Don Juan, the guest speaker, sits here.
 
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $948
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $913
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $911
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $811
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $827
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $794
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $726
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $736
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $707
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $686
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $696
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $606
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $666
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $534
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $609
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $482
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $602
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $454
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $580
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $367
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $546
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $363
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $509
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $363
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $477
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $328
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $465
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $286
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $453
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $244
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $447
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $230
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $432
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $191
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $391
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $157
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $374
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $83
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $349
 NAME: Gentlemen Salesman SEX: Male AMOUNT IN SALES: $41
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $294
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $276
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $245
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $217
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $173
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $141
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $120
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $107
 NAME: Lady Salesman SEX: Female AMOUNT IN SALES: $28
*/
