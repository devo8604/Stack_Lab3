//
//  main.cpp
//  Stack_Lab3
//
//  Created by Devon Smith on 7/21/14.
//  Copyright (c) 2014 Devon Smith. All rights reserved.
//


#include "SeatingList.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

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

