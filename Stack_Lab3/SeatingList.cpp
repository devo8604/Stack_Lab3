//
//  SeatingList.cpp
//  Stack_Lab3
//
//  Created by Devon Smith on 7/21/14.
//  Copyright (c) 2014 Devon Smith. All rights reserved.
//

#include "SeatingList.h"
#include "GuestList.h"
#include <vector>
#include <stack>
#include <time.h>

using namespace std;

bool inistialListSort(GuestList &lhs, GuestList &rhs)
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
}

void SeatingList::stackBuilder(vector<GuestList>& initialList, stack<GuestList, vector<GuestList>>& leftSideOfTable, stack<GuestList, vector<GuestList>>& rightSideOfTable)
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
}

void SeatingList::rightSideOfTableSorter(stack<GuestList, vector<GuestList>>& rightSideOfTable, stack<GuestList, vector<GuestList>>& rightSideOfTableSorted)
{
    while (!rightSideOfTable.empty()) {
        rightSideOfTableSorted.push(rightSideOfTable.top());
        rightSideOfTable.pop();
    }
}






